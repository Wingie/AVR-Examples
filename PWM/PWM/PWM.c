/*
 * PWM.c
 *
 * Created: 23-5-2011 6:13:24 PM
 *  Author: Wingston
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

volatile int duty = 10;
ISR(INT0_vect) { /* signal handler for external interrupt int0 */
	
	duty+=50;
	if(duty>300)
		duty = 300;
   }

ISR(INT1_vect) {    /* signal handler for external interrupt int1 */
   
	duty-=50;
	if(duty<1)
		duty = 1;
   }


int main(void)
{
	DDRD = 0x20;
	DDRB = 0xFF;
	PORTB = 0xFE;
	GIMSK = (1<<INT0)|(1<<INT1);
	MCUCR |= ( 1 << ISC01 );
	MCUCR &= ~( 1 << ISC00 ); 
	MCUCR |= ( 1 << ISC11 );
	MCUCR &= ~( 1 << ISC10 );
    sei();       // enable interrupts 
	int incr = 0;
    while(1)
    {
        //TODO:: Please write your application code 
		PORTA = 0;
		_delay_loop_2(duty);
		PORTA = 0xFF;
		_delay_loop_2(500-duty);
		
		duty+=incr;
		if(duty>300 || duty<3)
			incr *=-1;
    }
}