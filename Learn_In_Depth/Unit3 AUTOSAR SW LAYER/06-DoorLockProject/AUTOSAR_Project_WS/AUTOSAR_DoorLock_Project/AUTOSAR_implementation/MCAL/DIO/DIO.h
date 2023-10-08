/*
 * DIO.h
 *
 *  Created on: Oct 6, 2023
 *      Author: Osama
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_

#include "../../Stm32_F103C6_Drivers/inc/stm32f103x8_gpio_driver.h"

unsigned char Dio_ReadChannel(unsigned char ID);
void Dio_WriteChannel(unsigned char ID , unsigned char Level);


#define DOOR_ID           GPIO_PIN_3
#define LED_ID            GPIO_PIN_7

#define GPIO_Port_Used    GPIOA

#endif /* MCAL_DIO_DIO_H_ */
