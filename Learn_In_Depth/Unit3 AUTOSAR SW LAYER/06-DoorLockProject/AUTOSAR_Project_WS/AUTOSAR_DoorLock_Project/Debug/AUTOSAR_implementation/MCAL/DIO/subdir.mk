################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AUTOSAR_implementation/MCAL/DIO/DIO.c 

OBJS += \
./AUTOSAR_implementation/MCAL/DIO/DIO.o 

C_DEPS += \
./AUTOSAR_implementation/MCAL/DIO/DIO.d 


# Each subdirectory must supply rules for building sources it contributes
AUTOSAR_implementation/MCAL/DIO/DIO.o: ../AUTOSAR_implementation/MCAL/DIO/DIO.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"G:/OSAMAA/Embedded System/Learn In Depth/AUTOSAR IN DEPTH/Unit3 AUTOSAR SW LAYER/AUTOSAR_Project_WS/AUTOSAR_DoorLock_Project/HAL/includes" -I"G:/OSAMAA/Embedded System/Learn In Depth/AUTOSAR IN DEPTH/Unit3 AUTOSAR SW LAYER/AUTOSAR_Project_WS/AUTOSAR_DoorLock_Project/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"AUTOSAR_implementation/MCAL/DIO/DIO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

