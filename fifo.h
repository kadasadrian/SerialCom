#ifndef __FIFO_H_
#define __FIFO_H_

#include <stdint.h>
#include <stdbool.h>

#define FIFOSize        256
typedef unsigned char  FIFOtype;

typedef struct FIFOu8{
	uint8_t *FiFo;
	uint32_t Head,Tail,Number;
	uint32_t MaxNumber;
}_FIFOu8;

extern uint8_t	FIFO_Pushu8(_FIFOu8 *fifo, uint8_t data);
extern uint8_t	FIFO_Popu8(_FIFOu8 *fifo,uint8_t *data);
extern uint8_t	FIFO_Clear(_FIFOu8 *fifo);
extern void FIFO_Init(_FIFOu8 *fifo, FIFOtype *p, uint16_t size);

#endif
