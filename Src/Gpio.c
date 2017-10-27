/*
 * Gpio.c
 *
 *  Created on: Oct 27, 2017
 *      Author: user
 */


#include "Gpio.h"

uint32_t *gpioGMode = (uint32_t *)(GPIOG_BASE_ADDR + GPIO_MODE_OFF);
uint32_t *gpioGOSpeed = (uint32_t *)(GPIOG_BASE_ADDR + GPIO_OSPEED_OFF);
uint32_t *gpioGPupd = (uint32_t *)(GPIOG_BASE_ADDR + GPIO_PUPD_OFF);
uint32_t *gpioGOTpye = (uint32_t *)(GPIOG_BASE_ADDR + GPIO_OTYPE_OFF);
uint32_t *gpioGOD = (uint32_t *)(GPIOG_BASE_ADDR + GPIO_OD_OFF);


void setGpioG(int pin, int mode, int outDriveType, int pullType, int speed){
	*gpioGMode &= ~(3 << pin*2); //3 = 0x11  //clear pin mode to 0 1st
	*gpioGMode |= mode << (pin * 2); //clear pin mode to 0 1st

	*gpioGOSpeed  &= ~(3 << pin*2);			//clear the pin speed 1st
	*gpioGOSpeed |= speed << (pin * 2);		//set the pin speed

	*gpioGPupd  &= ~(3 << pin*2);			//clear the pin Pupd 1st
	*gpioGPupd  |= pullType << (pin * 2);		//set the pin Pupd

	*gpioGOTpye  &= ~(1 << pin);			//clear the pin speed 1st
	*gpioGOTpye  |= outDriveType << pin;	//set the pin drive-type


}

void gpioGWrite(int pin, int state){

	if(state == 1){
		*gpioGOD |= 1 << pin;
	}else{
		*gpioGOD &= ~(1 << pin);
	}

}
