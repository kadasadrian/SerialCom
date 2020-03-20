#include <avr/io.h>
#include "uart.h"
#include "circularbuffer.h"

extern _circularBuff buff;

int counter;
char data;
char finale[] = "\r\nThe End";
int j;

int main( void )
{
	buff.writeIndex = 0;
	buff.readIndex = 0;
	counter=0;
	j=0;
	
	USART_Init ( MYUBRR );

	while(1)
	{
		data=USART_Receive();
		pushChar(&data);
		counter++;
		if (counter == 10)
		{
			for(j;j<10;j++)USART_Transmit(popChar());
			break;
		}

	}

	for(j= 0;j<(sizeof(finale)-1);j++)USART_Transmit(finale[j]);

	return(0); 
}


