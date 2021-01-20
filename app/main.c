/* Standard includes. */
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "xil_printf.h"

#define STACK_SIZE 1024
#define TASK_PRIORITY (configMAX_PRIORITIES - 1)

void vPlatformInit()
{
	xil_printf("vPlatformInit\n");
	/* called from vTaskStartScheduler -> xPortStartScheduler->configSETUP_TICK_INTERRUPT*/
	/*FreeRTOS_SetupTickInterrupt();*/
}


void vTaskOutStream(void *pvParams)
{
	const TickType_t xDelay = pdMS_TO_TICKS(200);

	for (;;) {
		xil_printf("%s\n", __func__);
		/*vPrintString("%s\n", __func__);*/
		vTaskDelay(xDelay);
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
