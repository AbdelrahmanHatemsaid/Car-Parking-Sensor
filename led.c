/*
 * led.c
 *
 *  Created on: Oct 6, 2024
 *      Author: YAS
 */
#include <util/delay.h> /* For the delay functions */
#include "common_macros.h" /* For GET_BIT Macro */
#include "led.h"
#include "gpio.h"
#if(LED_LOGIC == positive)
void LEDS_init(void){
	GPIO_setupPinDirection(RED_LED_PORT_ID,RED_LED_PIN_ID ,PIN_OUTPUT);
	GPIO_setupPinDirection(GREEN_LED_PORT_ID,GREEN_LED_PIN_ID ,PIN_OUTPUT);
	GPIO_setupPinDirection(BLUE_LED_PORT_ID,BLUE_LED_PIN_ID ,PIN_OUTPUT);
	GPIO_writePin(RED_LED_PORT_ID,RED_LED_PIN_ID,LOGIC_LOW);
	GPIO_writePin(GREEN_LED_PORT_ID,GREEN_LED_PIN_ID,LOGIC_LOW);
	GPIO_writePin(BLUE_LED_PORT_ID,BLUE_LED_PIN_ID,LOGIC_LOW);
}
#endif

#if(LED_LOGIC == negative)
void LEDS_init(void){
	GPIO_setupPinDirection(RED_LED_PORT_ID,RED_LED_PIN_ID ,PIN_OUTPUT);
	GPIO_setupPinDirection(GREEN_LED_PORT_ID,GREEN_LED_PIN_ID ,PIN_OUTPUT);
	GPIO_setupPinDirection(BLUE_LED_PORT_ID,BLUE_LED_PIN_ID ,PIN_OUTPUT);
	GPIO_writePin(RED_LED_PORT_ID,RED_LED_PIN_ID,LOGIC_HIGH);
	GPIO_writePin(GREEN_LED_PORT_ID,GREEN_LED_PIN_ID,LOGIC_HIGH);
	GPIO_writePin(BLUE_LED_PORT_ID,BLUE_LED_PIN_ID,LOGIC_HIGH);
}
#endif
#if(LED_LOGIC == positive)
void LED_on(LED_ID id){

	if(id == LED_RED){

	    GPIO_writePin(RED_LED_PORT_ID,RED_LED_PIN_ID,LOGIC_HIGH);
	}
	else if(id == LED_GREEN){
	    GPIO_writePin(GREEN_LED_PORT_ID,GREEN_LED_PIN_ID,LOGIC_HIGH);
	}
	else if(id == LED_BLUE){
	    GPIO_writePin(BLUE_LED_PORT_ID,BLUE_LED_PIN_ID,LOGIC_HIGH);
	}
}
#endif

#if(LED_LOGIC == negative)
void LED_on(LED_ID id){
if(id == 0){

	GPIO_writePin(RED_LED_PORT_ID,RED_LED_PIN_ID,LOGIC_LOW);
}
else if(id == 1){
	GPIO_writePin(GREEN_LED_PORT_ID,GREEN_LED_PIN_ID,LOGIC_LOW);
}
else if(id == 2){
	GPIO_writePin(BLUE_LED_PORT_ID,BLUE_LED_PIN_ID,LOGIC_LOW);
}
}
#endif

#if(LED_LOGIC == positive)
void LED_off(LED_ID id){

	if(id == 0){

	    GPIO_writePin(RED_LED_PORT_ID,RED_LED_PIN_ID,LOGIC_LOW);
	}
	else if(id == 1){
	    GPIO_writePin(GREEN_LED_PORT_ID,GREEN_LED_PIN_ID,LOGIC_LOW);
	}
	else if(id == 2){
	    GPIO_writePin(BLUE_LED_PORT_ID,BLUE_LED_PIN_ID,LOGIC_LOW);
	}
}
#endif

#if(LED_LOGIC == negative)
void LED_off(LED_ID id){
if(id == 0){

	GPIO_writePin(RED_LED_PORT_ID,RED_LED_PIN_ID,LOGIC_HIGH);
}
else if(id == 1){
	GPIO_writePin(GREEN_LED_PORT_ID,GREEN_LED_PIN_ID,LOGIC_HIGH);
}
else if(id == 2){
	GPIO_writePin(BLUE_LED_PORT_ID,BLUE_LED_PIN_ID,LOGIC_HIGH);
}
}
#endif



