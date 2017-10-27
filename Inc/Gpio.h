/*
 * Gpio.h
 *
 *  Created on: Oct 27, 2017
 *      Author: user
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>

#define GPIOG_BASE_ADDR 0x40021800
#define GPIO_MODE_OFF 0x0
#define GPIO_OSPEED_OFF 0x8
#define GPIO_PUPD_OFF 0xc
#define GPIO_OTYPE_OFF 0x4
#define GPIO_OD_OFF 0x14

//pin mode
#define GPIO_MODE_IN 0
#define GPIO_MODE_OUT 1
#define GPIO_MODE_AF 2
#define GPIO_MODE_ANA 3

//pin output drive type
#define GPIO_PUSH_PULL 0
#define GPIO_OPEN_DRAIN 1

//output speed
#define GPIO_LOW_SPEED 0
#define GPIO_MED_SPEED 1
#define GPIO_HI_SPEED 2
#define GPIO_VHI_SPEED 3

//pin pull type
#define GPIO_NO_PULL 0
#define GPIO_PULL_UP 1
#define GPIO_PULL_DOWN 2

//Export variables to other modules
extern uint32_t *gpioGMode;
extern uint32_t *gpioGOSpeed;
extern uint32_t *gpioGPupd;
extern uint32_t *gpioGOType;
extern uint32_t *gpioGOD;

void setGpioG(int pin, int mode, int outDriveType, int pullType, int speed);
void gpioGWrite(int pin, int state);

#endif /* G
PIO_H_ */