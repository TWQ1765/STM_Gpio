/*
 * Rng.h
 *
 *  Created on: Oct 31, 2017
 *      Author: user
 */
#include <stdint.h>
#ifndef RNG_H_
#define RNG_H_



#define RNG_BASE_ADDR 0x50060800
#define Rng ((RngReg *)(RNG_BASE_ADDR))

typedef struct RngReg RngReg;
struct RngReg{
	volatile uint32_t CR;		//0h control bh of interrupt , internal bh
	volatile uint32_t SR;		//4h stutas of reg
	volatile uint32_t DR;		//8h data reg

};

//status reg
#define RNG_FAULTY_SEQUENCE (1<<2)
#define RNG_FAULTY_CLK		(1<<1)
#define RNG_DRDY			1

//control reg
#define RNG_RNGEN (1<<2)



void generateRandomNmber(void);
int isRandomNumberAvailable(void);
int isAnyError(void);
int isFaultyRandomSequence(void);
int getRandomNumber(void);



#endif /* RNG_H_ */
