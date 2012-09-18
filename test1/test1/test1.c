/*
 * test1.c
 *
 * Created: 17-5-2011 6:26:54 PM
 *  Author: Wingston
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
    while(1)
    {
		sei();
					
		cli();
	}
}