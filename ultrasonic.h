/*
 * ultrasonic.h
 *
 *  Created on: Oct 11, 2024
 *      Author: YAS
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "std_types.h"

#define TRIG_PORT_ID            PORTD_ID
#define TRIG_PIN_ID             PIN7_ID

#define ECHO_PORT_ID            PORTD_ID
#define ECHO_PIN_ID             PIN6_ID

void Ultrasonic_init(void);
void Ultrasonic_Trigger(void);
uint16 Ultrasonic_readDistance(void);

#endif /* ULTRASONIC_H_ */
