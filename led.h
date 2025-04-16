/*
 * led.h
 *
 *  Created on: Oct 6, 2024
 *      Author: YAS
 */

#ifndef LED_H_
#define LED_H_
#include "std_types.h"
typedef enum {
    LED_RED,
    LED_GREEN,
    LED_BLUE,
    LED_COUNT
} LED_ID;
#define positive 1
#define negative 0
#define LED_LOGIC           positive
#if((LED_LOGIC != positive) && (LED_LOGIC != negative))

#error "LOGIC SHOULD BE positive or negative"

#endif
#if(LED_LOGIC == positive)
#define LED_ON              LOGIC_HIGH
#define LED_OFF             LOGIC_LOW
#endif
#if(LED_LOGIC == negative)
#define LED_ON              LOGIC_LOW
#define LED_OFF             LOGIC_HIGH
#endif
#define RED_LED_PORT_ID     PORTC_ID
#define RED_LED_PIN_ID      PIN0_ID
#define GREEN_LED_PORT_ID   PORTC_ID
#define GREEN_LED_PIN_ID    PIN1_ID
#define BLUE_LED_PORT_ID    PORTC_ID
#define BLUE_LED_PIN_ID     PIN2_ID

void LEDS_init(void);
void LED_on(LED_ID id);
void LED_off(LED_ID id);




#endif /* LED_H_ */
