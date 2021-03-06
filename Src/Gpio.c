/*
 * Gpio.c
 *
 *  Created on: Oct 27, 2017
 *      Author: user
 */


#include "Gpio.h"



void gpioConfig(GpioReg *gpio,int pin, int mode, int outDriveType, int pullType, int speed){
	gpio->mode &= ~(3 << pin*2); //3 = 0x11  //clear pin mode to 0 1st
	gpio->mode |= mode << (pin * 2); //clear pin mode to 0 1st

	gpio->outSpeed  &= ~(3 << pin*2);			//clear the pin speed 1st
	gpio->outSpeed |= speed << (pin * 2);		//set the pin speed

	gpio->pullType  &= ~(3 << pin*2);			//clear the pin Pupd 1st
	gpio->pullType  |= pullType << (pin * 2);		//set the pin Pupd

	gpio->outType  &= ~(1 << pin);			//clear the pin speed 1st
	gpio->outType  |= outDriveType << pin;	//set the pin drive-type


}

void gpioConfigAltFuncNum(GpioReg *gpio, int pin,int AF){
	if(pin<7)
		gpio->altFuncLo = AF << (pin*4);
	else
		gpio->altFuncHi = AF << (pin*4);
}


void gpioWrite(GpioReg *gpio,int pin, int state){

	if(state == 1){
		SET_PIN(gpio,pin);
		//gpio->outData |= 1 << pin;
	}else{
		RESET_PIN(gpio,pin);
		//gpio->outData &= ~(1 << pin);
	}

}


void gpioLock(GpioReg *gpio, int pin)
{
	int lockStatus;
	gpio->lock = (1<<16) | (1<<pin);
	gpio->lock = (0<<16) | (1<<pin);
	gpio->lock = (1<<16) | (1<<pin);
	lockStatus = gpio->lock;

}

int gpioRead(GpioReg *gpio, int pin){

	return gpio->inData & (1 << pin);
}




void gpioGConfig(int pin ,int modeNo, int outDriveType, int pullType, int speed)
{

	GpioG->mode &= ~(3 << (pin*2));				//clear pin mode to 0 1st
	GpioG->mode |= modeNo << (pin * 2); 			//clear pin mode to 0 1st
	GpioG->outSpeed  &= ~(3 << pin*2);			//clear the pin speed 1st
	GpioG->outSpeed |= speed << (pin * 2);		//set the pin speed

	GpioG->pullType  &= ~(3 << pin*2);			//clear the pin Pupd 1st
	GpioG->pullType  |= pullType << (pin * 2);		//set the pin Pupd

	GpioG->outType  &= ~(1 << pin);				//clear the pin speed 1st
	GpioG->outType  |= outDriveType << pin;		//set the pin drive-type
}

void gpioGWrite(int pin, int state){

	if(state == 1){
		GpioG->outData |= 1 << pin;
	}else{
		GpioG->outData &= ~(1 << pin);
	}

}
