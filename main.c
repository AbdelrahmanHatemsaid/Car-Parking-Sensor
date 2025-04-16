#include "common_macros.h"
#include "buzzer.h"
#include "lcd.h"
#include "led.h"
#include "icu.h"
#include "ultrasonic.h"
#include <util/delay.h>
#include <avr/interrupt.h>

uint16 distance_cm = 0 ;

void lcd(void) {
    LCD_moveCursor(0, 0);
    LCD_displayString("Distance=");
    LCD_moveCursor(0, 9);

    LCD_intgerToString((uint32)distance_cm);

    if(distance_cm < 100)
    {
        LCD_displayCharacter(' ');
    }

    LCD_moveCursor(1, 6);

    if(distance_cm <= 5)
    {
        LCD_displayString("STOP");
    }
    else
    {
        LCD_displayString("    ");
    }
    LCD_moveCursor(0, 12);
    LCD_displayString("CM");

}

int main(void){

	BUZZER_init();
	LCD_init();
	LEDS_init();
	Ultrasonic_init();
    sei();





	while(1){
	 distance_cm = Ultrasonic_readDistance();
	 lcd();

	if(distance_cm <= 5){

		        BUZZER_on();
		        LED_on(LED_RED);
		        LED_on(LED_GREEN);
		        LED_on(LED_BLUE);
		        _delay_ms(500);
		        LED_off(LED_RED);
		        LED_off(LED_GREEN);
		        LED_off(LED_BLUE);
		        _delay_ms(500);


	}
	else if(distance_cm > 5 && distance_cm <= 10){
		                LED_on(LED_RED);
				        LED_on(LED_GREEN);
				        LED_on(LED_BLUE);
				        BUZZER_off();
	}
	else if(distance_cm > 10 && distance_cm <= 15){
		                LED_on(LED_RED);
				        LED_on(LED_GREEN);
				        LED_off(LED_BLUE);
				        BUZZER_off();
	}
	else if(distance_cm > 15 && distance_cm <= 20){

		               LED_on(LED_RED);
		               LED_off(LED_GREEN);
		               LED_off(LED_BLUE);
		               BUZZER_off();
	}
	else if(distance_cm > 20){
		                LED_off(LED_RED);
				        LED_off(LED_GREEN);
				        LED_off(LED_BLUE);
				        BUZZER_off();

	}
	}
}
