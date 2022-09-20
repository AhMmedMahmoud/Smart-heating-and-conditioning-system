/*
 * adc.h
 *
 * Created: 9/14/2022 5:40:19 PM
 *  Author: Ahmed Mahmoud Mohamed Ibrahim
 */ 


#ifndef ADC_H_
#define ADC_H_


#include "../../Utilities/registers.h"
#include "../../Utilities/types.h"

// pins of Register ADMUX
#define MUX0	PIN0
#define MUX1	PIN1
#define MUX2	PIN2
#define MUX3	PIN3
#define MUX4	PIN4
#define ADLAR	PIN5
#define REFS0	PIN6
#define REFS1	PIN7
// pins of Register ADCSRA
#define ADPS0	PIN0
#define ADPS1	PIN1
#define ADPS2	PIN2
#define ADIE	PIN3
#define ADIF	PIN4
#define ADATE	PIN5
#define ADSC	PIN6
#define ADEN	PIN7
// pins of Register SFIOR
#define ADTS0	PIN5
#define ADTS1	PIN6
#define ADTS2	PIN7

// ADC parameters
#define ADC_Vref  5
#define ADC_step  ADC_Vref/1024.0

// functions prototypes
void ADC_init(uint8_t number);
void ADC_read(float *analogValue, uint8_t number);


#endif /* ADC_H_ */