#include "fifo.h"
#include <stdio.h>
#include <stdint.h>
int main(int argc, char * argv[])
{
	uint16_t data;
	int i = 0;
	fifo tfifo = {
		.start = 0,
		.stop = 0,
		.nextFifo = (void*)0,
	};

	printf("test read on empty fifo, with start=stop=0... ");
	if (readFifo(&tfifo,&data)==-1)
	{
		printf("Ok.\n");
	} else {
		printf("Fail, start = %d, stop = %d, data = %d.\n",tfifo.start,tfifo.stop,data);
		return -1;
	}

	printf("test write on empty fifo... ");
	if (writeFifo(&tfifo,42)==-1)
	{
		printf("Fail.\n");
		return -1;	
	} else {
		printf("Ok.\n");
	}
	printf("test read on non-empty fifo... ");
	if (readFifo(&tfifo,&data)==-1 || data!=42)
	{
		printf("Fail.\n");
		return -1;
	} else {
		printf("Ok.\n");
	}
	printf("test read on empty fifo... ");
	if (readFifo(&tfifo,&data)==-1)
	{
		printf("Ok.\n");
	} else {
		printf("Fail, start = %d, stop = %d, data = %d.\n",tfifo.start,tfifo.stop,data);
		return -1;
	}
	printf("test filling up empty fifo...");
	for (i=0; i<SIZE_FIFO ;i++)
	{
		if(writeFifo(&tfifo,i)==1)
		{
			printf("Fail, fifo unexpectedly filled up, i = %d, start = %d, stop = %d\n",\
					i,tfifo.start,tfifo.stop);	
			return -1;
		}
	}
	printf("Ok. \n");
	printf("test write on full fifo...");
	if(writeFifo(&tfifo,i+1)==1)
	{
		printf("Ok\n");
	} else {
		printf("Fail, fifo not full, start = %d, stop = %d, data = %d.\n",\
				tfifo.start,tfifo.stop,data);
		return -1;
	}
	printf("test read all fifo...");
	while (readFifo(&tfifo,&data)!=-1)
	{
		printf(" %d ",data);
	}
	printf("\nAll test succesfuls.\n");
	return 0;
}
