### Compile options
CC=gcc
IC=icc
CL=clang

### Flah options 
FLAGS= -Wall -Wextra -flto

### include
INCH= -I ./include 
INCS= ./src

### Files
FIL= file.o 
REG= reg.o 
RUN= main.o

all: bin/main


main.o: $(INCS)/main.c 
	$(CC) $(FLAGS) -c $(INCH) $(INCS)/main.c 

file.o: $(INCS)/file.c 
	$(CC) $(FLAGS) -c $(INCH) $(INCS)/file.c 

reg.o: $(INCS)/reg.c 
	$(CC) $(FLAGS) -c $(INCH) $(INCS)/reg.c 

###
bin/main: $(RUN) $(FIL) $(REG)
	$(CC) -o main $(FLAGS) $(RUN) $(FIL) $(REG)

solve:
	bin/main

clean:
	rm bin/* *.o



