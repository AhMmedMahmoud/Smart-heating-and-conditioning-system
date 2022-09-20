/*
 * dc_motoer.h
 *
 * Created: 9/14/2022 7:32:34 PM
 *  Author: Ahmed Mahmoud Mohamed Ibrahim
 */ 

#ifndef DC_MOTOER_H_
#define DC_MOTOER_H_

#include "../../Utilities/types.h"


/*
	enum represents motor errors
*/
typedef enum EN_dcMotorError_t
{
	DC_MOTOR_OK , DC_MOTOR_INITIALIZATION_FAILED, DC_MOTOR_TURING_ON_FAILED, DC_MOTOR_TURING_OFF_FAILED
}EN_dcMotorError_t;


// functions prototypes
EN_dcMotorError_t DC_MOTOR_init(uint8_t dcMotorPin , uint8_t dcMotorPort);
EN_dcMotorError_t DC_MOTOR_on(uint8_t dcMotorPin , uint8_t dcMotorPort);
EN_dcMotorError_t DC_MOTOR_off(uint8_t dcMotorPin , uint8_t dcMotorPort);




#endif /* DC_MOTOER_H_ */