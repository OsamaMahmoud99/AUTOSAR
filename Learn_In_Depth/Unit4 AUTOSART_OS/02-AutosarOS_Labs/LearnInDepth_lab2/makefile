

PROJECTNAME=LearnInDepth_lab1
ROOTDIR?=../../../
include $(ROOTDIR)/scripts/project_defaults.mk

ifneq (${MAKELEVEL},0) 

	# object files
	obj-y += LearnInDepth_lab.o
	obj-y += system_hooks.o
	obj-y += stm32f103x8_EXTI_driver.o
	obj-y += stm32f103x8_SPI_Drver.o  
	obj-y += stm32f103x8_USART_driver.o
	obj-y += stm32f103x8_gpio_driver.o
	obj-y += stm32f103x8_RCC_driver.o

	
	VPATH += $(ROOTDIR)/learn_in_depth_labs/stm32_stm3210c/labs/$(PROJECTNAME)

endif





