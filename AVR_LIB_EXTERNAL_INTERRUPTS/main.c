/*
 * main.c
 *
 *  Created on: Nov 5, 2015
 *      Author: Mohamed
 */

#include "common.h"

int main (void)
{
	DIO_init();
	DIO_set_port_direction(PORT1,OUTPUT);
	DIO_set_port(PORT1,0x00);

	DIO_set_port_direction(PORT3,OUTPUT);
	DIO_set_port(PORT3,0x00);

	Configure_Interrupt(INTRRUPT_0,FALLING_EDGE,PULLUP);
	Configure_Interrupt(INTRRUPT_1,FALLING_EDGE,PULLUP);
	Configure_Interrupt(INTRRUPT_2,FALLING_EDGE,PULLUP);

	Enable_Interrupt(INTRRUPT_0);
	Enable_Interrupt(INTRRUPT_1);
	Enable_Interrupt(INTRRUPT_2);

	Enable_Global_ISR();

	while(1)
	{
		DIO_toggle_port(PORT3);
		TO_DELAY(500);
	}

	return(0);

}

ISR(INT0_vect)
{
	int i=0;
	for(i=0;i<=5;i++)
	{
		DIO_toggle_pin(PIN8);
		TO_DELAY(500);
	}
}


/**
ISR (INT0_vect)
{
	int i=0;
	for(i=0;i<=5;i++)
	{
		DIO_toggle_pin(PIN8);
		TO_DELAY(500);
	}
}

ISR (INT1_vect)
{
	int i=0;
	for(i=0;i<=5;i++)
	{
		DIO_toggle_pin(PIN9);
		TO_DELAY(500);
	}
}

ISR (INT2_vect)
{
	int i=0;
	for(i=0;i<=5;i++)
	{
		DIO_toggle_pin(PIN10);
		TO_DELAY(500);
	}
}

**/

