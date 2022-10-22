CC=gcc
CURRENTFLAGS=-ansi -pedantic-errors -Wall -Wextra -DNDEBUG -O3
GDFLAGS=-ansi -pedantic-errors -Wall -Wextra -g
INCLUDE=-I ./include

VPATH = ./src:./include:./test

HEADER=algo.h
SOURCE_FILE=algo.c
TEST_FILE=algo_test.c




OBJECTS = algo.o algo_test.o 

PROD = algo_prod
DEV = algo_dev


prod : $(OBJECTS)
	$(CC) $(CURRENTFLAGS) $(OBJECTS) -o $(PROD)


debug : $(OBJECTS)
	$(CC) $(GDFLAGS) $(OBJECTS) -o $(DEV)


algo.o: $(SOURCE_FILE) $(HEADER)   
	$(CC) $(INCLUDE) $(GDFLAGS) -c $?

algo_test.o: $(TEST_FILE) $(HEADER)
	 $(CC) $(INCLUDE) $(GDFLAGS) -c $?


.PHONY: clean cleanobj all
clean:
	rm -f $(PROD) $(DEV) $(OBJECTS) 

cleanobj: 
	rm -f $(OBJECTS)
	
all: prod debug cleanobj


