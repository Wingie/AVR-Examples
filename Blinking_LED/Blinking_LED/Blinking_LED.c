/*
 * Blinking_LED.c
 *
 * Created: 19-5-2011 7:10:13 PM
 *  Author: Wingston
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 4000000

void ledblink();
void ledrun();


int main(void)
{
    ledrun();
}


void ledblink()
{
	DDRA = 0x03; // set up 0 and 1 bits as output
	PORTA = 0x02; // it
	while (1)
	{
		PORTA ^= 0x03;
		_delay_loop_2(50000);
	}
}

void ledrun()
{
	DDRA = 0xFF;
	int A = 0x00;
	int i = 0, j=1;
	A = ~(A | 0x01);
	while(1)
	{	
		PORTA = ~(0x01 << i);
		i +=j;	
		if(i>=3 || i<=0)
		{
			j*=-1;
		}	
		_delay_loop_2(50000);	
	}	
}

