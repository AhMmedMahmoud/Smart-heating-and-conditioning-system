/*
 * application.c
 *
 * Created: 9/14/2022 5:45:17 PM
 *  Author: Ahmed Mahmoud Mohamed Ibrahim
 */ 

#include "application.h"
#include <stdio.h>
#include "../ECUAL/LCD/lcd.h"
#include "../ECUAL/LED/led.h"
#include "../ECUAL/DC Motor/dc_motor.h"
#include "../MCAL/ADC/adc.h"

ST_lcd_t lcd;
float oldRead = -1;
float currentRead = 0;
char currentStringRead[17];


void setup()
{
	LED_init(redLedPin,redLedPort);
	LED_init(blueLedPin,blueLedPort);
	LED_init(GreenLedPin,GreenLedPort);
	DC_MOTOR_init(heaterDcMotorPin,heaterDcMotorPort);
	DC_MOTOR_init(CoolerDcMotorPin,CoolerDcMotorPort);
	
	LCD_init(&lcd, PIN0, Port_D, PIN1, Port_D, PIN0, Port_C, PIN1, Port_C, PIN2, Port_C, PIN3, Port_C, PIN4, Port_C, PIN5, Port_C, PIN6, Port_C, PIN7, Port_C);
	ADC_init(0);
}


void appStart()
{
	ADC_read(&currentRead,0);
	
	currentRead = (currentRead / 0.01) - 49.5;
	if(currentRead < 0)
		currentRead--;
		
	sprintf(currentStringRead, "temperature: %dC\n", (int)currentRead);
	
	if(currentRead != oldRead)
	{
		if((int)currentRead <= 20)
		{
			LED_on(redLedPin,redLedPort);
			LED_off(blueLedPin,blueLedPort);
			LED_off(GreenLedPin,GreenLedPort);
			
			DC_MOTOR_on(heaterDcMotorPin,heaterDcMotorPort);
			DC_MOTOR_off(CoolerDcMotorPin,CoolerDcMotorPort);
			
			LCD_pass(&lcd,CLEAR_DISPLAY,COMMAND);
			LCD_writeString(&lcd, (uint8_t*)currentStringRead);
			
			LCD_pass(&lcd,JUMP_TO_SECOND_LINE_POSITION_0,COMMAND);
			LCD_writeString(&lcd, (uint8_t*)"   Heater Mode");
		}
		else if((int)currentRead >= 30)
		{
			LED_off(redLedPin,redLedPort);
			LED_on(blueLedPin,blueLedPort);
			LED_off(GreenLedPin,GreenLedPort);
			
			DC_MOTOR_off(heaterDcMotorPin,heaterDcMotorPort);
			DC_MOTOR_on(CoolerDcMotorPin,CoolerDcMotorPort);
			
			LCD_pass(&lcd,CLEAR_DISPLAY,COMMAND);
			LCD_writeString(&lcd, (uint8_t*)currentStringRead);
			
			LCD_pass(&lcd,JUMP_TO_SECOND_LINE_POSITION_0,COMMAND);
			LCD_writeString(&lcd, (uint8_t*)"   Cooler Mode");
		}
		else
		{
			LED_off(redLedPin,redLedPort);
			LED_off(blueLedPin,blueLedPort);
			LED_on(GreenLedPin,GreenLedPort);
			
			DC_MOTOR_off(heaterDcMotorPin,heaterDcMotorPort);
			DC_MOTOR_off(CoolerDcMotorPin,CoolerDcMotorPort);
			
			LCD_pass(&lcd,CLEAR_DISPLAY,COMMAND);
			LCD_writeString(&lcd, (uint8_t*)currentStringRead);
			
			LCD_pass(&lcd,JUMP_TO_SECOND_LINE_POSITION_0,COMMAND);
			LCD_writeString(&lcd, (uint8_t*)"  Default Mode");
		}
		oldRead = currentRead;		
	}
}


/*
	1-If the air temperature is 20 or less
		 turn on the heater 
		 light up the RED LED
		 display "Heater Mood".
		 
	2-If the air temperature is 30 ° or more
		 turn on the Air conditioner 
		 light up the blue LED
		 display "Cooler mood".
		 
	3-If the air temperature is from 20°: 30°
		light up the green LED
		display "default mood"
*/