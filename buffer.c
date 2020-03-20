/*
 ============================================================================
 Name        : buffer.c
 Author      : Adrian Kadas
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


//  LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include "circularbuffer.h"
#include "UART.h"


_circularBuff buff;

void pushChar(char *pChar)
{
    buff.circularBuffer[buff.writeIndex] = *pChar ;
    buff.bufferLength++;	 //	Increase buffer size after writing
    buff.writeIndex++;	 //	Increase writeIndex position to prepare for next write
	if (SIZE_OF_BUFFER == buff.writeIndex) buff.writeIndex = 0; // If at last index in buffer, set writeIndex back to 0
}
char popChar(void)
{
    char ret;
    ret = buff.circularBuffer[buff.readIndex];
    buff.bufferLength--;	 //	Decrease buffer size after reading
    buff.readIndex++;	//	Increase readIndex position to prepare for next read
	if (SIZE_OF_BUFFER == buff.readIndex) buff.readIndex = 0; // If at last index in buffer, set readIndex back to 0
    return ret;
}

