/*
 * application.h
 *
 * Created: 9/14/2022 5:45:50 PM
 *  Author: Ahmed Mahmoud Mohamed Ibrahim
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

// leds connections
#define redLedPin	  PIN0
#define redLedPort    Port_B
#define blueLedPin	  PIN1
#define blueLedPort   Port_B
#define GreenLedPin	  PIN2
#define GreenLedPort  Port_B

// dc motors connections
#define heaterDcMotorPin	 PIN6
#define heaterDcMotorPort    Port_D
#define CoolerDcMotorPin	 PIN7
#define CoolerDcMotorPort	 Port_D

// functions prototypes
void setup();
void appStart();



#endif /* APPLICATION_H_ */