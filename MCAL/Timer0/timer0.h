/*
 * timer0.h
 *
 * Created: 9/14/2022 5:40:19 PM
 *  Author: Ahmed Mahmoud Mohamed Ibrahim
 */ 



#ifndef TIMER0_H_
#define TIMER0_H_

#include "../../Utilities/types.h"

// functions prototypes
void timer0_init();
void timer0_start();
void timer0_stop();
void timer0_clearOverFlowFlag();
void timer0_delay_uS(uint16_t milliSeconds);


// timer0 registers pins
#define WGM00 PIN6
#define WGM01 PIN3
#define COM00 PIN4
#define COM01 PIN5
#define CS00  PIN0
#define CS02  PIN2
#define TOV0  PIN0

#endif /* TIMER0_H_ */