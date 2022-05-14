
## Compile options
CC=gcc
IC=icc
CL=clang

### Flah options 
FLAGS= -Wall -Wextra -flto -g -mavx2 -O3 

### include
INCH= -I ./include 
INCS= ./src

### Files
FIL= file.o 
SAD= sad.o 
RUN= main.o

all: bin/main

file.o: $(INCS)/file.c 
	$(CL) $(FLAGS) -c $(INCH) $(INCS)/file.c 

sad.o: $(INCS)/sad.c 
	$(CL) $(FLAGS) -c $(INCH) $(INCS)/sad.c 

main.o: $(INCS)/main.c 
	$(CL) $(FLAGS) -c $(INCH) $(INCS)/main.c 
###
bin/main: $(RUN) $(FIL) $(SAD)
	$(CL) -o bin/main $(FLAGS) $(RUN) $(FIL) $(SAD)

clean:
	rm bin/* *.o 

