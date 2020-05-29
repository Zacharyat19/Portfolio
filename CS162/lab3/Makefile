CC=g++
EXE_FILE=prog

all: $(EXE_FILE)

$(EXE_FILE): pizza.o pizza.h prog.cpp
	$(CC) pizza.o  prog.cpp -o $(EXE_FILE)

pizza.o: pizza.h pizza.cpp
	$(CC) -c pizza.cpp

clean:
	rm -f *.o $(EXE_FILE)