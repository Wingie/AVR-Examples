/*
 * ADC.c
 *
 * Created: 22-5-2011 8:22:10 PM
 *  Author: Wingston
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>

uint16_t ReadChannel(int mux);

int main (void)
{
	DDRC = 0xFF;
	uint16_t adcval = 0;
	while(1){
		adcval = ReadChannel(0);
		if(adcval <400)
		{
				PORTC = 0;
		}
		else
		{
			PORTC = 0xFF;
		}
	}		
} 

uint16_t ReadChannel(int mux)
{
	uint8_t i;
	uint16_t result = 0; 

	ADCSRA = (1<<ADEN) | (1<<ADPS1) | (1<<ADPS0); 
	ADMUX = mux; // channel select
	ADMUX |= (1<<REFS1) | (1<<REFS0); // VCC

	ADCSRA |= (1<<ADSC); // start ADC
	while ( ADCSRA & (1<<ADSC) ) {
	; 
	}

	for(i=0;i<4;i++)
	{
		ADCSRA |= (1<<ADSC); 
		while ( ADCSRA & (1<<ADSC) ) {
		; 
		}
		result += ADCW; 
	}
	
	ADCSRA &= ~(1<<ADEN); // ADC deactivate (2)
	result /= 4; 
	return result;
}