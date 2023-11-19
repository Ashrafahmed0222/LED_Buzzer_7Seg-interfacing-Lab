/*
 * main.c
 *
 *  Created on: Nov 13, 2023
 *      Author: Ashraf Ahmed
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "DIO_private.h"

#include "LED_interface.h"
#include "SSD_interface.h"
#include "Buzzer_interface.h"
#include <util/delay.h>

int main(void) {

	SSD_CONFIG SSD1 = { COMMON_CATHODE, SSD_PORTC, 0xFF, DIO_PIN7 };
	SSD_voidInitialDataPort(SSD1);
	SSD_voidEnable(SSD1);

	LED_CONF ARR [] = {
	{ LED_PORTA, LED_PIN0, ACTIVE_HIGH },
	{ LED_PORTA, LED_PIN1, ACTIVE_HIGH },
	{ LED_PORTA, LED_PIN2, ACTIVE_HIGH },
	{ LED_PORTA, LED_PIN3, ACTIVE_HIGH },
	{ LED_PORTA, LED_PIN4, ACTIVE_HIGH },
	{ LED_PORTA, LED_PIN5, ACTIVE_HIGH },
	{ LED_PORTA, LED_PIN6, ACTIVE_HIGH },
	{ LED_PORTA, LED_PIN7, ACTIVE_HIGH }
	};

	for(u8 i=0; i<=7;i++){
		LED_voidInIt(ARR[i]);
	}



	BUZZER_CONF BUZZER1 = { BUZZER_PORTB, BUZZER_PIN0, ACTIVE_HIGH};
	BUZZER_voidInit(BUZZER1);

	while (1) {
		for(int i = 0; i<=7; i++){
			LED_voidON(ARR[i]);
			SSD_voidSendNumber(SSD1 ,(i+1));
			_delay_ms(250);
			if(i==7){
				BUZZER_voidOn(BUZZER1);
			}
		}
		while(1){
		}
	}

	return 0;
}
