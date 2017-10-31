/*
 * Rcc.h
 *
 *  Created on: Oct 27, 2017
 *      Author: user
 */

#ifndef RCC_H_
#define RCC_H_

#include <stdint.h>

#define RCC_BASE_ADDR 0x40023800
#define RCC_AHB1RST_OFF 0x10
#define RCC_AHB1EN_OFF 0x30
#define Rcc ((RccReg*)(RCC_BASE_ADDR))

typedef struct RccReg RccReg;
struct RccReg{
	volatile uint32_t RCC_CR;				//00h
	volatile uint32_t RCC_PLLCFGR;			//04h
	volatile uint32_t RCC_CFGR;				//08h
	volatile uint32_t RCC_CIR;				//0Ch
	volatile uint32_t RCC_AHB1RSTR;			//10h
	volatile uint32_t RCC_AHB2RSTR;			//14h
	volatile uint32_t RCC_AHB3RSTR;			//18h
	volatile uint32_t Reserved1[1];			//1Ch xxx
	volatile uint32_t RCC_APB1RSTR;			//20h
	volatile uint32_t RCC_APB2RSTR;			//24h
	volatile uint32_t Reserved2[2];			//28h-2Ch xxx
	volatile uint32_t RCC_AHB1ENR;			//30h
	volatile uint32_t RCC_AHB2ENR;			//34h
	volatile uint32_t RCC_AHB3ENR;			//38h
	volatile uint32_t Reserved3[1];			//3Ch xxx
	volatile uint32_t RCC_APB1ENR;			//40h
	volatile uint32_t RCC_APB2ENR;			//44h
	volatile uint32_t Reserved4[2];			//48h xxx
	volatile uint32_t RCC_AHB1LPENR;		//4Ch
	volatile uint32_t RCC_AHB2LPENR;		//40h
	volatile uint32_t RCC_AHB3LPENR;		//54h
	volatile uint32_t Reserved5[1];			//58h xxx
	volatile uint32_t RCC_APB1LPENR;		//60h
	volatile uint32_t RCC_APB2LPENR;		//64h
	volatile uint32_t Reserved6[2];			//68h-6Ch xxx
	volatile uint32_t RCC_BDCR;				//70h
	volatile uint32_t RCC_CSR;				//74h
	volatile uint32_t Reserved7[2];			//78h-7Ch xxx
	volatile uint32_t RCC_SSCGR;			//80h
	volatile uint32_t RCC_PLLI2SCFGR ;		//84h
};





//Export
extern uint32_t *rccAhb1Rst;
extern uint32_t *rccAhb1En;

void enableGpioG(void);
void enableGpioA(void);
void enableGpioB(void);
void enableRng(void);


#endif /* RCC_H_ */
