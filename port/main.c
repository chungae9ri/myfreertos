/* Standard includes. */
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

int main( void )
{
#if 0
	/* See http://www.freertos.org/RTOS-Xilinx-Zynq.html for instructions. */

	/* Configure the hardware ready to run the demo. */
	prvSetupHardware();

	/* The mainSELECTED_APPLICATION setting is described at the top	of this
	file. */
	#if( mainSELECTED_APPLICATION == 0 )
	{
		main_blinky();
	}
	#elif( mainSELECTED_APPLICATION == 1 )
	{
		main_full();
	}
	#else
	{
		main_lwIP();
	}
	#endif

	/* Don't expect to reach here. */
#endif
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

/* dummy funcs for fixing compile error from linking libc */
void _init()
{

}

void _fini()
{

}
