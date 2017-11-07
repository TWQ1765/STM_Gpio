/*
 * Gpio.h
 *
 *  Created on: Oct 27, 2017
 *      Author: user
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>



#define GPIOA_BASE_ADDR 0x40020000
#define GPIOB_BASE_ADDR 0x40020400
#define GPIOC_BASE_ADDR 0x40020800
#define GPIOD_BASE_ADDR 0x40020C00
#define GPIOE_BASE_ADDR 0x40021000
#define GPIOF_BASE_ADDR 0x40021400
#define GPIOG_BASE_ADDR 0x40021800
#define GPIOH_BASE_ADDR 0x40021C00
#define GPIOI_BASE_ADDR 0x40022000

#define GpioA ((GpioReg *)(GPIOA_BASE_ADDR))
#define GpioB ((GpioReg *)(GPIOB_BASE_ADDR))
#define GpioC ((GpioReg *)(GPIOC_BASE_ADDR))
#define GpioD ((GpioReg *)(GPIOD_BASE_ADDR))
#define GpioE ((GpioReg *)(GPIOE_BASE_ADDR))
#define GpioF ((GpioReg *)(GPIOF_BASE_ADDR))
#define GpioG ((GpioReg *)(GPIOG_BASE_ADDR))
#define GpioH ((GpioReg *)(GPIOH_BASE_ADDR))
#define GpioI ((GpioReg *)(GPIOI_BASE_ADDR))



typedef struct GpioReg GpioReg;
struct GpioReg{
	volatile uint32_t mode;			//0h
	volatile uint32_t outType;		//4h
	volatile uint32_t outSpeed;		//8h
	volatile uint32_t pullType;		//ch
	volatile uint32_t inData;		//10h
	volatile uint32_t outData;		//14h
	//volatile uint32_t bitData;		//18h
	volatile uint32_t bsr;
	volatile uint32_t lock;			//1ch
	volatile uint32_t altFuncLo;	//20h
	volatile uint32_t altFuncHi;	//24h
};


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


//pin reset and set
#define SET_PIN(gpio,pinNum) (gpio->bsr = (1 << pinNum))
#define RESET_PIN(gpio, pinNum) (gpio->bsr=(1<<(16+pinNum)))

/*
//Export variables to other modules
extern uint32_t *gpioGMode;
extern uint32_t *gpioGOSpeed;
extern uint32_t *gpioGPupd;
extern uint32_t *gpioGOType;
extern uint32_t *gpioGOD;
*/

//Alternate Function
#define AF0		0
#define AF1		1
#define AF2		2
#define AF3		3
#define AF4		4
#define AF5		5
#define AF6		6
#define AF7		7
#define AF8		8
#define AF9		9
#define AF10		10
#define AF11		11
#define AF12		12
#define AF13		13
#define AF14		14
#define AF15		15



void gpioConfig(GpioReg *gpio,int pin, int mode, int outDriveType, int pullType, int speed);
void gpioWrite(GpioReg *gpio,int pin, int state);
int gpioRead(GpioReg *gpio, int pin);

void gpioLock(GpioReg *gpio, int pin);
void gpioGConfig(int pin, int mode, int outDriveType, int pullType, int speed );
void gpioGWrite(int pin, int state);

void gpioConfigAltFuncNum(GpioReg *gpio,int pin,int AF);

#endif /* GPIO_H_ */
