/*
 * led.h
 *
 * Created: 9/13/2022 1:34:44 PM
 *  Author: Ahmed Mahmoud Mohamed Ibrahim
 */ 

#ifndef LED_H_
#define LED_H_

#include "../../Utilities/types.h"

/*
	enum represents led errors
*/
typedef enum EN_ledError_t
{
	OK_LED , LED_INITIALIZATION_FAILED, LED_TURING_ON_FAILED, LED_TURING_OFF_FAILED , LED_TOGGLING_FAILED
}EN_ledError_t;


// functions prototypes
EN_ledError_t LED_init(uint8_t ledPin , uint8_t ledPort);
EN_ledError_t LED_on(uint8_t ledPin , uint8_t ledPort);
EN_ledError_t LED_off(uint8_t ledPin , uint8_t ledPort);
EN_ledError_t LED_toggle(uint8_t ledPin , uint8_t ledPort);

#endif /* LED_H_ */