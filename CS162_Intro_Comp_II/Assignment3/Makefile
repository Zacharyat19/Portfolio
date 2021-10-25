CC=g++
EXE_FILE=prog

all: $(EXE_FILE)

$(EXE_FILE): Animal.o Animal.h Monkey.o Monkey.h Sea_otter.o Sea_otter.h Sloth.o Sloth.h Zoo.h Zoo.o prog.cpp
	$(CC) Animal.o Monkey.o Sea_otter.o Sloth.o Zoo.o prog.cpp -o $(EXE_FILE)

Animal.o: Animal.h Animal.cpp
	$(CC) -c Animal.cpp

Monkey.o: Monkey.h Monkey.cpp
	$(CC) -c Monkey.cpp

Sea_otter.o: Sea_otter.h Sea_otter.cpp
	$(CC) -c Sea_otter.cpp

Sloth.o: Sloth.h Sloth.cpp
	$(CC) -c Sloth.cpp

Zoo.o: Zoo.h Zoo.cpp
	$(CC) -c Zoo.cpp

clean:
	rm -f *.o $(EXE_FILE)