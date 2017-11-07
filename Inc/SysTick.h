/*
 * SysTick.h
 *
 *  Created on: Nov 7, 2017
 *      Author: user
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include <stdint.h>

#define SYSTICK_BASE_ADDR 0xE000E010

typedef struct SysTickReg SysTickReg;
struct SysTickReg{

	volatile uint32_t CTRL;		//control and status register
	volatile uint32_t LOAD;		//reload value register
	volatile uint32_t VAL;		//current value register
	volatile uint32_t CALIB;	//calibration value register
};
#define TICK ((SysTickReg*)( SYSTICK_BASE_ADDR ))

#define SYSTICK_EN					 1
#define SYSTICK_INTR_EN				 (1<<1)
#define SYSTICK_PROC_CLK_SRC 		 (1<<2)
#define SYSTICK_PROC_CNTR_OVERFLOW	 (1<<16)

//macro
#define sysTickEnable()  			(TICK->CTRL |=SYSTICK_EN)
#define sysTickDisable()  			(TICK->CTRL &=~SYSTICK_EN)
#define sysTickIntrEnable()  		(TICK->CTRL |=SYSTICK_INTR_EN)
#define sysTickIntrDisable()  		(TICK->CTRL &=~SYSTICK_INTR_EN)
#define sysTickSetReload(x)  		(TICK->LOAD = (x))
#define sysTickReadCounter(x)  		(TICK->VAL)
#define sysTickClrCounter()  		(TICK->VAL = 0xbadface)	//clear counter
//set SYSTICK to run @ processor speed
#define sysTickFullSpeed()	(TICK->CTRL |= SYSTICK_PROC_CLK_SRC)
//set SYSTICK to run @ 1/8 of AHB frequency
#define sysTickPresceldSpeed()	(TICK->CTRL &= ~SYSTICK_PROC_CLK_SRC)
//determine if SysTick timer has expired Return none zero if has expired
#define sysTickHasExpired()		(TICK->CTRL & SYSTICK_PROC_CNTR_OVERFLOW)

#endif /* SYSTICK_H_ */
