/*
 * buzzer.h
 *
 *  Created on: Oct 6, 2024
 *      Author: YAS
 */

#ifndef BUZZER_H_
#define BUZZER_H_
#include "std_types.h"
#define BUZZER_PORT_ID       PORTC_ID
#define BUZZER_PIN_ID        PIN5_ID


void BUZZER_init(void);
void BUZZER_on(void);
void BUZZER_off(void);
#endif /* BUZZER_H_ */
