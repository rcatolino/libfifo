#Very simple 16-bit-int circular buffer implementation

by raph github.com/rcatolino

libfifo used by vxworks dummy driver. Including auto testing utility. 
To compile under VxWorks change include <stdint.h> to <types.h>
It's usualy better to use directly sources rather than libfifo.a.
