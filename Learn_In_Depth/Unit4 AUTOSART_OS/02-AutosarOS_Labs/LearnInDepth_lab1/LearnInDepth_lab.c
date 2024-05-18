

//AUTOSAR IN Depth
//learn-in-depth.com
//eng.kleroles shenouda

#include "Os.h"
#include "Mcu.h"
#include "arc.h"
#include <stdint.h>
#include "stm32f10x.h"


//#define USE_LDEBUG_PRINTF // Uncomment this to turn debug statements on.
#include "debug.h"

// How many errors to keep in error log.
#define ERROR_LOG_SIZE 20

void OsBTask( void ) {
	StackInfoType si;
	TaskType currTask;
	LDEBUG_PRINTF("[%08u] bTask3 start\n", (unsigned)GetOsTick() );

	GetTaskID(&currTask);
	Os_Arc_GetStackInfo(currTask,&si);
	LDEBUG_PRINTF("bTask3: %u%% stack usage\n",
			(unsigned)OS_STACK_USAGE(&si))

	TerminateTask();
}


void OsExTask1( void ) {
volatile int x ;
	for(;;) {
		WaitEvent(EVENT_MASK_Event1);
		ClearEvent(EVENT_MASK_Event1);
		x++ ;
	}
}


void OsIdleTask( void ) {
	for(;;) {}
}
