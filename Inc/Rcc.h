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






/*
 * configure the MCOx to be driven by the clock 'src' and the
 * frequency divided by 'div'.
 * WARNING: the MCOx pin is NOT configured here. The user need
 * 			to separately configure it in order for the pin to
 * 			output the clock signal.
 *
 * Input:
 * 	mco		is  MCO1
 * 				MCO2
 *
 * 	src		is	MCO_HSI_SRC
 * 				MCO_LSE_SRC
 * 				MCO_HSE_SRC
 * 				MCO_PLL_SRC
 *
 * 	div		is	MCO_NO_DIV
 * 				MCO_DIV_BY_2
 * 				MCO_DIV_BY_3
 * 				MCO_DIV_BY_2
 * 				MCO_DIV_BY_5
 */
/////////////////////////////////////////////
#define MCO_HSI_SRC	0
#define MCO_LSE_SRC	1
#define MCO_HSE_SRC	2
#define MCO_PLL_SRC	3

//PreScaler
#define MCO_NO_DIV		0
#define MCO_DIV_BY_2	4
#define MCO_DIV_BY_3	5
#define MCO_DIV_BY_4	6
#define MCO_DIV_BY_5	7


#define rccSelectMco1Src(x)				\
	do{\
		Rcc->RCC_CFGR &=~(3<<21);	\
		Rcc->RCC_CFGR |=((x)<<21);	\
		}while(0)

#define rccSetMco1Prescaler(x)			\
	do{\
		Rcc->RCC_CFGR &=~(7<<24);	\
		Rcc->RCC_CFGR |=((x)<<24);	\
		}while(0)

	//Export variables to other modules
	extern uint32_t *rccAhb1Rst;
	extern uint32_t *rccAhb1En;

	void enableGpioG(void);
	void enableGpioA(void);
	void enableGpioB(void);
	void enableRng(void);


#endif /* RCC_H_ */
