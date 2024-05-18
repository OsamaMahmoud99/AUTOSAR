

//AUTOSAR IN Depth
//learn-in-depth.com
//eng.kleroles shenouda

#include "Os.h"
#include "Mcu.h"
#include "arc.h"
#include <stdint.h>

#include "stm32f103x8_gpio_driver.h"
#include "stm32f103x8_USART_driver.h"

//#define USE_LDEBUG_PRINTF // Uncomment this to turn debug statements on.
#include "debug.h"

// How many errors to keep in error log.
#define ERROR_LOG_SIZE 20

GPIO_PinConfig_t GPIOApin2cfg ;
UART_Config UART1_config ;

void sendString(const char *str) {
    // Pointer to the current character
    const char *ptr = str;

    // Loop until null terminator is encountered
    while (*ptr != '\0') {
        // Call MCAL_UART_SendData for each character in the string
        MCAL_UART_SendData(USART1, (uint16_t *)ptr, enable);

        // Move to the next character
        ptr++;
    }
}

void bTask( void ) {

	const char *string1 = "AUTOSAR IN Depth : learn-in-depth.com! \n";
	const char *string2 = " Basic Task will be terminated \n";


	GPIOApin2cfg.GPIO_PinNumber = GPIO_PIN_2 ;
	GPIOApin2cfg.GPIO_MODE  = GPIO_MODE_OUTPUT_PP;
	GPIOApin2cfg.GPIO_Output_Speed  = GPIO_SPEED_50M;

	MCAL_GPIO_Init(GPIOA, &GPIOApin2cfg);


	UART1_config.BaudRate = UART_BaudRate_115200 ;
	UART1_config.HwFlowCtl = UART_HwFlowCtl_NONE ;
	UART1_config.IRQ_Enable = UART_IRQ_Enable_NONE ;
	UART1_config.P_IRQ_CallBack =  NULL ;
	UART1_config.Parity = UART_Parity__EVEN ;
	UART1_config.Payload_Length = UART_Payload_Length_8B ;
	UART1_config.StopBits = UART_StopBits__2 ;
	UART1_config.USART_Mode = UART_MODE_TX ;

	MCAL_UART_GPIO_Set_Pins(USART1);
	MCAL_UART_Init(USART1, &UART1_config);

    sendString(string1);
    sendString(string2);

	TerminateTask();
}


void LearnIndepth_exTask( void ) {
	const char *string3 = "AUTOSAR IN Depth : LearnIndepth_exTask  is triggred -> Alarm1 Set Event  \n";


	for(;;) {
		WaitEvent(EVENT_MASK_Event1);
		ClearEvent(EVENT_MASK_Event1);
		sendString(string3);
		MCAL_GPIO_TogglePin(GPIOA, &GPIOApin2cfg);
	}
}


void OsIdle( void ) {
	for(;;) {}
}
