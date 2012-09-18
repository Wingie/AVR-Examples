/*
 * avr_interrupt.c
 *
 * Created: 20-5-2011 11:44:55 AM
 *  Author: Wingston
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
volatile int led = 0xFE;
volatile int f = 0;

ISR(INT0_vect) { /* signal handler for external interrupt int0 */
	
	f++;
	
	if(f>3)
		f=3;
   }

ISR(INT1_vect) {    /* signal handler for external interrupt int1 */
   
	f--;
	if(f<0)
		f=0;
			
   }

int main(void) {


    DDRB = 0xFF;      
	PORTB = 0x33;
    DDRD = 0x00;     
	GIMSK = (1<<INT0)|(1<<INT1);
	MCUCR |= ( 1 << ISC01 );
	MCUCR &= ~( 1 << ISC00 ); 
	MCUCR |= ( 1 << ISC11 );
	MCUCR &= ~( 1 << ISC10 ); 

    sei();       /* enable interrupts */

    //1, 3, 7. 15
	//int arr[4] = {~1,~3,~7,~15};
		
    while(1) {
		led = 0xFE<<f;
		
	}                      /* loop forever */

}