/*
 * ExternalIrq.h
 *
 *  Created on: Nov 7, 2017
 *      Author: user
 */

#ifndef EXTERNALIRQ_H_
#define EXTERNALIRQ_H_

#include <stdint.h>

#define EXTERNALIRQ_BASE_ADDR 0x40013c00

typedef struct EXTIReg EXTIReg;
struct EXTIReg{

	volatile uint32_t IMR;		//Interrupt mask register
	volatile uint32_t EMR;		//Event mask register
	volatile uint32_t RTSR;		//Rising trigger selection register
	volatile uint32_t FTSR;		//Falling trigger selection register
	volatile uint32_t SWIER;	//Software interrupt event register
	volatile uint32_t PR;		//Pending register
};

#define Exti ((EXTIReg*)(EXTERNALIRQ_BASE_ADDR))

#define EXTI_IMR_enable(x) 					(Exti->IMR 		|= (1<<(x)))
#define EXTI_IMR_disable(x)					(Exti->IMR 		&= ~(1<<(x)))
#define EXTI_EMR_MASK(x) 					(Exti->EMR 		|= (1<<(x)))
#define EXTI_EMR_UNMASK(x)  				(Exti->EMR 		&= ~(1<<(x)))
#define EXTI_RTSR_set_RisingTrigger(x) 		(Exti->RTSR 	|= (1<<(x)))
#define EXTI_RTSR_reset_RisingTrigger(x)	(Exti->RTSR  	&= ~(1<<(x)))
#define EXTI_FTSR_set_FallingTrigger(x) 	(Exti->FTSR 	|= (1<<(x)))
#define EXTI_FTSR_reset_FallingTrigger(x)	(Exti->FTSR 	&= ~(1<<(x)))
#define EXTI_SWIER_set_SoftwareTrigger(x)	(Exti->SWIER 	|= (1<<(x)))
//#define EXTI_PR_PendingTrigger(x) 			(Exti->PR 		|= (1<<(x)))
#define EXTI_PR_PendingClear(x) 			(Exti->PR		|= (1<<(x)))

/*
#define EXTI_IMR_MASK 	(EXTI->IMR = 0x00000000000000000000000)
#define EXTI_IMR_UNMASK (EXTI->IMR = 0x11111111111111111111111)
#define EXTI_EMR_MASK 	(EXTI->EMR = 0x00000000000000000000000)
#define EXTI_EMR_UNMASK (EXTI->EMR = 0x11111111111111111111111)
#define EXTI_RTSR_trigger_disabled(x) 	(EXTI->RTSR = (x))
#define EXTI_RTSR_trigger_enabled(x)  (EXTI->RTSR = (x))
#define EXTI_FTSR_trigger_disabled(x) 	(EXTI->FTSR = (x))
#define EXTI_SWIER(x)  (EXTI->SWIER = (x))
#define EXTI_SWIER(x)  (EXTI->SWIER = (x))
#define EXTI_PR(x)  (EXTI->SWIER = (x))
#define EXTI_PR(x)  (EXTI->SWIER = (x))
*/



#endif /* EXTERNALIRQ_H_ */
