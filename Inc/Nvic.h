/*
 * Nvic.h
 *
 *  Created on: Oct 31, 2017
 *      Author: user
 */

#ifndef NVIC_H_
#define NVIC_H_

#define NVIC_BASE_ADDR 0xE000E100
#define Nvic	((NvicReg *)(NVIC_BASE_ADDR))

typedef struct NvicReg NvicReg;
struct NvicReg{

	volatile uint32_t ISER[3];		//Interrupt Set-Enable Register (0h) // 80h-0h /4 convert dec - 3= 29
	volatile uint32_t reserved1[29];
	volatile uint32_t ICER[3];		//Interrupt Clear-Enable Register (80h)
	volatile uint32_t reserved2[29];
	volatile uint32_t ISPR[3];		//Interrupt Set-Pending Register (100h)
	volatile uint32_t reserved3[29];
	volatile uint32_t ICPR[3];		//Interrupt Clear-Pending Register (180h)
	volatile uint32_t reserved4[29];
	volatile uint32_t IABR[3];		//Interrupt Active-Bit Register (200h)
	volatile uint32_t reserved5[61];
	volatile uint32_t IPR[21];		//Interrupt priority Register (300h)
	volatile uint32_t reserved6[683]; // (hex e00-300)=b00/4=2c0 convert dec = 701 - 21= 683
	volatile uint32_t STIR[1];		//Interrupt Software trigger interrupt Register (e00h)

};
// (irqNum /32 ====== irqNum >> 5) same
// (irqNum%32 ======= irqNum&0x1F) same
#define nvicEnableIrq(irqNum)	(Nvic->ISER[irqNum >> 5] |= 1 <<( irqNum & 0x1F))

#define nvicDisableIrq(irqNum)	(Nvic->ISER[irqNum >> 5] |= 1 <<( irqNum & 0x1F))

#define nvicSetPriority(irqNum, priority) (Nvic->ISER[irqNum >> 2] |= priority << (irqNum & 0x3)*8 + 4)

#endif /* NVIC_H_ */
