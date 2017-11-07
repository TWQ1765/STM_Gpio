/*
 * Rng.c
 *
 *  Created on: Oct 31, 2017
 *      Author: user
 */



#include "Rng.h"
/*
 * start generating a new random number. This non-blocking function.
 */
void generateRandomNmber(void){
	Rng->CR = RNG_RNGEN;
}
/*
 * Find out if RNG has produced a random number
 * return
 * 0 if not ready
 * 1 if ready
 */
int isRandomNumberAvailable(void){
	return Rng->SR & RNG_DRDY;
}


/*
 * Find out if RNG has encountered any error
 * return
 * 0 if not error
 * non 0 if error
 */
int isAnyError(void){
	return Rng->SR & (RNG_FAULTY_SEQUENCE | RNG_FAULTY_CLK);
}

/*
 * Find out if RNG has encountered any faulty random number
 * return
 * 0 if not error
 * 1 if random number is ready
 */
int isFaultyRandomSequence(void){
	return Rng->SR & RNG_FAULTY_SEQUENCE;
}
/*
 *Get a random number.. This blocking function
 */
int getRandomNumber(void){
	do{
		generateRandomNmber();
		while(!isRandomNumberAvailable());
	}while (isRandomNumberAvailable());
	return Rng->DR;

}

void getRandomNumberByInterrupt(void){
	Rng->CR |= RNG_RNGEN | RNG_IE;

}
