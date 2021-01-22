/* Standard includes. */
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "xil_printf.h"
#include <odev.h>

#define STACK_SIZE 1024
#define TASK_PRIORITY (configMAX_PRIORITIES - 1)

void vPlatformInit()
{
	xil_printf("vPlatformInit\n");
	/* called from vTaskStartScheduler -> xPortStartScheduler->configSETUP_TICK_INTERRUPT*/
	/*FreeRTOS_SetupTickInterrupt();*/
}

#define O_STREAM_START		0x38000000
#define O_STREAM_END		0x3C000000
#define O_STREAM_BURST_SZ	0x00000040 /* 64B */
#define O_STREAM_STEP		0x00000100 /* 256B */
#define O_STREAM_WRAP		0x00001000 /* 4096 */

void vTaskOutStream(void *pvParams)
{
	volatile uint8_t *psrc;
	uint32_t i, j, consumer_started;
	const TickType_t xDelay = pdMS_TO_TICKS(20);

	xil_printf("%s\n", __func__);
	psrc = (volatile uint8_t *)O_STREAM_START;

	// To avoid underflow, prepare initial data first
	for (i = 0; i < O_STREAM_WRAP * 4; i++) {
		/* seq number starting from 1*/
		((uint32_t *)((uint32_t)psrc + O_STREAM_BURST_SZ * i))[0] = i + 1;
	}
	// 
	xil_printf("start odev \n");
	start_odev();
	set_consume_latency(1000);

	start_odev_stream();

	i = j = consumer_started = 0;
	/* out stream forever */
	for (;;) {
		/*((uint32_t *)((uint32_t)psrc + O_STREAM_STEP * i))[0] = k++;*/
		if (!put_to_itab(O_STREAM_START + O_STREAM_STEP * i, O_STREAM_STEP)) {
			/*xil_printf("put_to_itab: %d\n", i);*/
			vTaskDelay(xDelay);
			i++;
			i = i % O_STREAM_WRAP;
		} else {
			/* blocked for a while */
			vTaskDelay(xDelay);
		}
		if (i == 256 && consumer_started == 0) {
			start_consumer();
			consumer_started = 1;
		}
		xil_printf("i: %d\n", i);
	}
}

int main( void )
{
	TaskHandle_t xHandle;

	vPlatformInit();

	if (xTaskCreate(vTaskOutStream,
			"OutStreamTask",
			STACK_SIZE,
			NULL,
			TASK_PRIORITY,
			&xHandle
		   ) != pdPASS) 
	{
		xil_printf("Start OutStreamTask fail\n");
	}

	vTaskStartScheduler();
	
	xil_printf("vTaskStartScheduler fail\n");
	return 0;
}

void vAssertCalled( const char * pcFile, unsigned long ulLine )
{
	volatile unsigned long ul = 0;

	( void ) pcFile;
	( void ) ulLine;

	taskENTER_CRITICAL();
	{
		/* Set ul to a non-zero value using the debugger to step out of this
		   function. */
		while( ul == 0 )
		{
			portNOP();
		}
	}
	taskEXIT_CRITICAL();
}
