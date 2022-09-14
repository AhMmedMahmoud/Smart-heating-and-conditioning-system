/*
 * dc_motor.c
 *
 * Created: 9/14/2022 7:32:15 PM
 *  Author: Ahmed Mahmoud Mohamed Ibrahim
 */ 

#include "dc_motor.h"
#include "../../MCAL/DIO/dio.h"

/*
1-this functions initializes dc motor
2-return DC_MOTOR_OK if initialization is done
3-return DC_MOTOR_INITIALIZATION_FAILED if initialization is failed
*/
EN_dcMotorError_t DC_MOTOR_init(uint8_t dcMotorPin , uint8_t dcMotorPort)
{
	switch ( DIO_init(dcMotorPin,dcMotorPort,OUT) )
	{
		case OK:	return DC_MOTOR_OK;
		default:	return DC_MOTOR_INITIALIZATION_FAILED;
	}
}



/*
1-this functions turns on dc motor
2-return DC_MOTOR_OK if turning on is done
3-return DC_MOTOR_TURING_ON_FAILED if turning on is failed
*/
EN_dcMotorError_t DC_MOTOR_on(uint8_t dcMotorPin , uint8_t dcMotorPort)
{
	switch ( DIO_write(dcMotorPin,dcMotorPort,HIGH) )
	{
		case OK:	return DC_MOTOR_OK;
		default:	return DC_MOTOR_TURING_ON_FAILED;
	}
}



/*
1-this functions turns off de motor
2-return DC_MOTOR_OK if turning off is done
3-return DC_MOTOR_TURING_OFF_FAILED if turning off is failed
*/
EN_dcMotorError_t DC_MOTOR_off(uint8_t dcMotorPin , uint8_t dcMotorPort)
{
	switch ( DIO_write(dcMotorPin,dcMotorPort,LOW) )
	{
		case OK:	return DC_MOTOR_OK;
		default:	return DC_MOTOR_TURING_OFF_FAILED;
	}
}
