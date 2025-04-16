/*
 * ultrasonic.c
 *
 *  Created on: Oct 11, 2024
 *      Author: YAS
 */


#include <util/delay.h> /* For the delay functions */
#include "common_macros.h" /* For GET_BIT Macro */
#include "ultrasonic.h"
#include "gpio.h"
#include "icu.h"

    uint8 g_edgeCount = 0;
	uint16 g_timeHigh = 0;

void ultrasonic_edgeProcessing(void){

	g_edgeCount++;
	if(g_edgeCount == 1)
		{
			/*
			 * Clear the timer counter register to start measurements from the
			 * first detected rising edge
			 */
			ICU_clearTimerValue();
			/* Detect falling edge */
			ICU_setEdgeDetectionType(FALLING);
		}
		else if(g_edgeCount == 2)
		{
			/* Store the High time value */
			g_timeHigh = ICU_getInputCaptureValue();
			/* Detect rising edge */
			ICU_setEdgeDetectionType(RAISING);
			g_edgeCount = 0 ;
		}
}

void Ultrasonic_init(void){
	 GPIO_setupPinDirection(TRIG_PORT_ID,TRIG_PIN_ID,PIN_OUTPUT);
	ICU_ConfigType ICU_Configurations = {F_CPU_8,RAISING};
	ICU_init(&ICU_Configurations);
	ICU_setCallBack(ultrasonic_edgeProcessing);


}


void Ultrasonic_Trigger(void){
    GPIO_writePin(TRIG_PORT_ID,TRIG_PIN_ID,LOGIC_HIGH);
    _delay_us(10);
    GPIO_writePin(TRIG_PORT_ID,TRIG_PIN_ID,LOGIC_LOW);
}
uint16 Ultrasonic_readDistance(void){
	Ultrasonic_Trigger();
	    return (g_timeHigh/ 117.6) + 1 ;
}

