#Variables utilisées :
CC=gcc #Compilateur
EDL=ar #Linker
CCFLAGS=-Wall #Options de compilations
EDLFLAGS=rcs
BIN=libfifo.a #Nom du binaire à construire

OBJ=fifo.o
TOBJ=testfifo.o
LIBS=$(BIN)

$(BIN): $(OBJ) testfifo
	@echo building $<
	$(EDL) $(EDLFLAGS) $(BIN) $(OBJ) $(LIBS)
	@echo done.
	@echo testing libfifo...
	@./testfifo

%.o : %.c *.h
	@echo building $< ...
	$(CC) $(CCFLAGS) -c $< 
	@echo done
	
test : testfifo
	@echo testing libfifo...
	@./testfifo

testfifo : $(TOBJ) $(OBJ)
	@echo building $<
	$(CC) $(CCFLAGS) -o testfifo $(TOBJ) $(OBJ)

clean: 
	@echo -n cleaning repository... 
	@rm -f *.o
	@rm -f .*.swp
	@rm -f *~
	@rm -f *.log
	@rm -f *.pid
	@rm -f *.out
	@echo cleaned.
	
