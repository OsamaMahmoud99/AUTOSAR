
/* -------------------------------- Arctic Core ------------------------------
 * Arctic Core - the open source AUTOSAR platform http://arccore.com
 *
 * Copyright (C) 2009  ArcCore AB <contact@arccore.com>
 *
 * This source code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by the
 * Free Software Foundation; See <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 * -------------------------------- Arctic Core ------------------------------*/
/*
 * DESCRIPTION
 *   Hold all OSEK system hooks.
 */

/* ----------------------------[includes]------------------------------------*/

#include <stdint.h>
#include "Os.h"
#include <assert.h>

#include "Mcu.h"

/* ----------------------------[private define]------------------------------*/
#define ERROR_LOG_SIZE 1

//#define USE_LDEBUG_PRINTF	1
#include "debug.h"
#include "stm32f10x.h"


/* ----------------------------[private macro]-------------------------------*/


/* ----------------------------[private typedef]-----------------------------*/

typedef struct ErrorEntry {
	StatusType 		error;
	OsErrorType     info;
	TaskType    	taskId;
	OsServiceIdType serviceId;
} ErrorEntryType;


typedef struct ErrorLog {
	int 			index;
	ErrorEntryType 	log[ERROR_LOG_SIZE];
} ErrorLogType;

struct LogBad {
	uint32_t param1;
	uint32_t param2;
	uint32_t param3;
	TaskType taskId;
	OsServiceIdType serviceId;
	StatusType error;
} LogBadType;


/* ----------------------------[private function prototypes]-----------------*/
/* ----------------------------[private variables]---------------------------*/
ErrorLogType ErrorLog;
/* ----------------------------[private functions]---------------------------*/
/* ----------------------------[public functions]----------------------------*/

/**
 *
 * @param FatalError
 * @return
 */
ProtectionReturnType ProtectionHook( StatusType FatalError ) {
	printf("## ProtectionHook\n");
	return PRO_KILLAPPL;
}

/**
 *
 */
void StartupHook( void ) {
//	LDEBUG_PRINTF("## StartupHook\n");

	uint32_t sys_freq = McuE_GetSystemClock();
	(void)sys_freq;
	LDEBUG_PRINTF("Sys clock %d Hz\n",sys_freq);
}

/**
 *
 * @param Error
 */
void ShutdownHook( StatusType error ) {
	LDEBUG_FPUTS("## ShutdownHook\n");
	(void)error;
	while(1) {
		//err = err;
		;
	}
}

/**
 *
 * @param error
 */
void ErrorHook( StatusType error ) {

	TaskType task;
	static struct LogBad LogBad[ERROR_LOG_SIZE];
	static uint8_t ErrorCount = 0;

	GetTaskID(&task);


	OsServiceIdType service = OSErrorGetServiceId();

	/* Grab the arguments to the functions
	 * This is the standard way, see 11.2 in OSEK spec
	 */
	switch(service) {
	case OSServiceId_SetRelAlarm:
	{
		// Read the arguments to the faulty functions...
		AlarmType alarm_id = OSError_SetRelAlarm_AlarmId;
		TickType increment = OSError_SetRelAlarm_Increment;
		TickType cycle = OSError_SetRelAlarm_Cycle;
		(void)alarm_id;
		(void)increment;
		(void)cycle;

		// ... Handle this some way.
		break;
	}
	/*
	 * The same pattern as above applies for all other OS functions.
	 * See Os.h for names and definitions.
	 */

	default:
		break;
	}

	LDEBUG_PRINTF("## ErrorHook err=%u\n",Error);

	/* Log the errors in a buffer for later review */
	LogBad[ErrorCount].param1 = os_error.param1;
	LogBad[ErrorCount].param2 = os_error.param2;
	LogBad[ErrorCount].param3 = os_error.param3;
	LogBad[ErrorCount].serviceId = service;
	LogBad[ErrorCount].taskId = task;
	LogBad[ErrorCount].error = error;

	ErrorCount++;

	/* Keep compiler silent */
	(void)LogBad[ErrorCount].param1;

	// Stall if buffer is full.
	while(ErrorCount >= ERROR_LOG_SIZE);
}


/**
 *
 */
void PreTaskHook( void ) {
	StatusType rv;
	TaskType task;
	TaskStateType state;

	rv = GetTaskID(&task);
	assert( rv == E_OK );
	LDEBUG_PRINTF("## PreTaskHook, taskid=%d\n",task);
	rv = GetTaskState(task,&state);
	assert( rv == E_OK );
	assert( state == TASK_STATE_RUNNING );
}

/**
 *
 */
void PostTaskHook( void ) {
	StatusType rv;
	TaskType task;
	TaskStateType state;

	rv = GetTaskID(&task);
	assert( rv == E_OK );
	LDEBUG_PRINTF("## PostTaskHook, taskid=%d\n",task);
	rv = GetTaskState(task,&state);
	assert( rv == E_OK );
	assert( state == TASK_STATE_RUNNING );

}


void SystemInit(void)
{
    /* Reset the RCC clock configuration to the default reset state */
    /* Set HSION bit */
    RCC->CR |= (uint32_t)0x00000001;

    /* Reset SW, HPRE, PPRE1, PPRE2, ADCPRE and MCO bits */
    RCC->CFGR &= (uint32_t)0xF8FF0000;

    /* Reset HSEON, CSSON and PLLON bits */
    RCC->CR &= (uint32_t)0xFEF6FFFF;

    /* Reset HSEBYP bit */
    RCC->CR &= (uint32_t)0xFFFBFFFF;

    /* Reset PLLSRC, PLLXTPRE, PLLMUL and USBPRE/OTGFSPRE bits */
    RCC->CFGR &= (uint32_t)0xFF80FFFF;

    /* Disable all interrupts and clear pending bits  */
    RCC->CIR = 0x009F0000;

    /* Configure the System clock source, PLL Multiplier and Divider, AHB/APBx prescalers and Flash settings */
    /* Enable HSI */
    RCC->CR |= ((uint32_t)RCC_CR_HSION);

    /* Wait till HSI is ready */
    while ((RCC->CR & RCC_CR_HSIRDY) == 0);

    /* Enable Prefetch Buffer and set Flash Latency */
    FLASH->ACR = FLASH_ACR_PRFTBE | FLASH_ACR_LATENCY_2;

    /* HCLK = SYSCLK, PCLK2 = HCLK, PCLK1 = HCLK/2 */
    RCC->CFGR |= (uint32_t)RCC_CFGR_HPRE_DIV1 |
                 RCC_CFGR_PPRE2_DIV1 |
                 RCC_CFGR_PPRE1_DIV2;

    /* PLL configuration: PLLCLK = HSI/2 * 9 = 72 MHz */
    RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLSRC_HSI_Div2 | RCC_CFGR_PLLMULL9);

    /* Enable PLL */
    RCC->CR |= RCC_CR_PLLON;

    /* Wait till PLL is ready */
    while((RCC->CR & RCC_CR_PLLRDY) == 0);

    /* Select PLL as system clock source */
    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
    RCC->CFGR |= (uint32_t)RCC_CFGR_SW_PLL;

    /* Wait till PLL is used as system clock source */
    while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS) != (uint32_t)RCC_CFGR_SWS_PLL);

    /* Optionally, turn on the HSE and configure the PLL to use the HSE instead of HSI */
    /* This is not done here because it's specific to whether an external crystal or oscillator is used */

    /* At this stage the system clock is set to 72 MHz */
}


extern uint32_t _sidata;
/* start address for the .data section. defined in linker script */
extern uint32_t _sdata;
/* end address for the .data section. defined in linker script */
extern uint32_t _edata;
/* start address for the .bss section. defined in linker script */
extern uint32_t _sbss;
/* end address for the .bss section. defined in linker script */
extern uint32_t _ebss;

static uint8_t *__sbrk_heap_end = NULL;


void *_sbrk(ptrdiff_t incr)
{
  extern uint8_t _end; /* Symbol defined in the linker script */
  extern uint8_t _estack; /* Symbol defined in the linker script */
  extern uint32_t _Min_Stack_Size; /* Symbol defined in the linker script */
  const uint32_t stack_limit = (uint32_t)&_estack - (uint32_t)&_Min_Stack_Size;
  const uint8_t *max_heap = (uint8_t *)stack_limit;
  uint8_t *prev_heap_end;

  /* Initialize heap end at first call */
  if (NULL == __sbrk_heap_end)
  {
    __sbrk_heap_end = &_end;
  }

  /* Protect heap from growing into the reserved MSP stack */
  if (__sbrk_heap_end + incr > max_heap)
  {
//    errno = ENOMEM;
    return (void *)-1;
  }

  prev_heap_end = __sbrk_heap_end;
  __sbrk_heap_end += incr;

  return (void *)prev_heap_end;
}
