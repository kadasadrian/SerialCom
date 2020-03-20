#include "fifo.h"

inline uint8_t FIFO_Pushu8(_FIFOu8 *fifo, uint8_t data){
  if(fifo->MaxNumber==fifo->Number){
          return 0;
  }
  fifo->FiFo[fifo->Head++] = data;
  if(fifo->Head == fifo->MaxNumber){
          fifo->Head = 0;
  }
  fifo->Number++;
  return 1;
}

uint8_t FIFO_Popu8(_FIFOu8 *fifo,uint8_t *data){
  if(fifo->Number == 0){
    return 0;
  }

  *data = fifo->FiFo[fifo->Tail];
  if(++fifo->Tail == fifo->MaxNumber){
    fifo->Tail = 0;
  }
  fifo->Number--;

  return 1;
}


uint8_t* FIFO_PeekLastu8(_FIFOu8 *fifo){
  if(fifo->Number == 0){
          return 0;
  }
  return &(fifo->FiFo[fifo->Tail]);
}

uint8_t FIFO_Clear(_FIFOu8 *fifo){
  if(fifo != 0){
    fifo->Head = 0;
    fifo->Tail = 0;
    fifo->Number = 0;
    return 1;
  }
  else return 0;
}

void FIFO_Init(_FIFOu8 *fifo, FIFOtype *p, uint16_t size){
  fifo->FiFo = p;
  fifo->Head = 0;
  fifo->Tail = 0;
  fifo->Number = 0;  
  fifo->MaxNumber = (size - 1);
}


