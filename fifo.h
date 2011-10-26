#ifndef __LIBFIFOH__
#define __LIBFIFOH__

#include <stdint.h>
#define SIZE_FIFO 20
typedef struct fifo
{
	int start;
	int stop;
	uint16_t mem[SIZE_FIFO+1];
	struct fifo * nextFifo;
	int taskId;
} fifo;

int writeFifo(fifo * wFifo, uint16_t data );
int readFifo(fifo * rFifo, uint16_t * data );
#endif
