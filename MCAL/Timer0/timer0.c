/*
 * timer0.c
 *
 * Created: 9/14/2022 5:40:19 PM
 *  Author: Ahmed Mahmoud Mohamed Ibrahim
 */ 

#include "timer0.h"
#include "../../Utilities/registers.h"



/*
	normal mode
	disconnect PIN 0C0
*/
void timer0_init()
{	
	TCCR0 &= ~( (1<<WGM00) | (1<<WGM01) );   // normal mode	
	TCCR0 &= ~( (1<<COM00) | (1<<COM01) );   // disconnect PIN OC0
}



/*
	 clock source to be used by Timer0  is clk (no prescaler)
*/
void timer0_start()
{
	TCCR0 |= (1<<CS00);              // timer clock is clk (no prescaler) --> starting timer
}



/*
	 clock source to be used by Timer0  is  No clock source
*/
void timer0_stop()
{
	TCCR0 &= ~(1<<CS00);             // timer clock is disconnected --> disable timer
}




/*
	this functions clear overflow flag
*/
void timer0_clearOverFlowFlag()
{
	TIFR |= (1<<TOV0);            // clear overflow flag by writting 1   (commom bug)
}


void timer0_delay_uS(uint16_t milliSeconds)    // busy wait delay
{
	int i;
	for(i = 0 ; i < milliSeconds ; i++)
	{
		TCNT0 = 255;                         // make current value in timer0 is 255
		timer0_start();                      // start timer0
		while( (TIFR & (1<<TOV0) ) == 0);     // at overflow flag
		timer0_clearOverFlowFlag();
		timer0_stop();
	}
}