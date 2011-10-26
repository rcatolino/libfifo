#include "fifo.h"
#include <stdint.h>
#include <stdio.h>
int writeFifo(fifo * wFifo, uint16_t data )
{
	//write data at end of fifo
	wFifo->mem[wFifo->stop]=data;
	//inc stop pointer
	wFifo->stop++;
	wFifo->stop=(wFifo->stop)%(SIZE_FIFO+1);
	if (wFifo->stop == wFifo->start)
	{
		//fifo full, discard first message : inc start pointer
		wFifo->start++;
		wFifo->start=(wFifo->start)%(SIZE_FIFO+1);
		return 1;
	}
	return 0;
}
int readFifo(fifo * rFifo, uint16_t * data)
{
	if (rFifo->start == rFifo->stop)
	{
		//fifo empty, nothing to read : exit and cry
		return -1;
	}//otherwise :
	//Read data
	*data = rFifo->mem[rFifo->start];
	rFifo->start++;
	rFifo->start=(rFifo->start)%(SIZE_FIFO+1);
	return 0;
}
