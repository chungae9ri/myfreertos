#include "FreeRTOS.h"
#include "task.h"

void vApplicationTickHook(void) __attribute__((weak));
void vApplicationIdleHook(void) __attribute__((weak));
void vConfigureTickInterrupt(void);
void vClearTickInterrupt(void);
void XTime_SetTime(void);
void vApplicationMallocFailedHook(void) __attribute__((weak));
void _exit(int status) __attribute__((weak));
void _init(void);
void _fini(void);
void _sbrk(void);

#if (configCHECK_FOR_STACK_OVERFLOW > 0)
void vApplicationStackOverflowHook(TaskHandle_t xTask, 
		char *pcTaskName);
#endif

void vApplicationTickHook(void)
{

}

void vApplicationIdleHook(void)
{

}
void vConfigureTickInterrupt(void)
{

}

void vClearTickInterrupt(void)
{

}

#if (configCHECK_FOR_STACK_OVERFLOW > 0)
void vApplicationStackOverflowHook(TaskHandle_t xTask, 
		char *pcTaskName)
{

}
#endif

void vApplicationMallocFailedHook(void)
{

}

void XTime_SetTime(void)
{

}

void _exit(int status)
{
	while(1);
}

void _init(void)
{

}

void _fini(void)
{

}


void _sbrk(void)
{

}
