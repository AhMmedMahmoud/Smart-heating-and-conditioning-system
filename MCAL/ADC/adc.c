/*
 * adc.c
 *
 * Created: 9/14/2022 5:39:45 PM
 *  Author: Ahmed Mahmoud Mohamed Mahmoud
 */ 

#include "adc.h"
#include "../../MCAL/Dio/dio.h"

void ADC_init(uint8_t number)
{
	DIO_init(number,Port_A,IN);								// configure pin as input
	ADMUX |= (1<<REFS0);									// External Vref at pin AVCC
	ADMUX &= ~(1<<ADLAR);									// right adjustment
	ADCSRA &= ~( (1<<ADPS2) | (1<<ADPS1)| (1<< ADPS0) );	// choose ADC Prescaler = 2
	ADCSRA |= (1<<ADEN);							  	    // turn on ADC
}

void ADC_read(float *analogValue, uint8_t number)
{
	uint16_t adc_result;
	
	ADMUX = (ADMUX & ~0X1F) | number;				// choose channel with no differential inputs
	ADCSRA |= (1<<ADSC);							// start conversion
	while( (ADCSRA & (1<<ADIF)) == 0);				// wait to end of conversion
	
	adc_result = ADCL;		 /* Read the low byte */
	adc_result += (ADCH<<8); /* Read and add the high byte */
	
	*analogValue = adc_result*ADC_step;
}
