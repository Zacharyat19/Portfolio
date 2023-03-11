CC=g++
EXE_FILE=prog

all: $(EXE_FILE)

$(EXE_FILE): Shape.o Shape.h Rectangle.h Rectangle.o Circle.o Circle.h Square.o Square.h application.cpp
	$(CC) Shape.o Rectangle.o Circle.o Square.o application.cpp -o $(EXE_FILE)

Shape.o: Shape.h Shape.cpp
	$(CC) -c Shape.cpp

Rectangle.o: Rectangle.h Rectangle.cpp
	$(CC) -c Rectangle.cpp

Circle.o: Circle.h Circle.cpp
	$(CC) -c Circle.cpp

Square.o: Square.h Square.cpp
	$(CC) -c Square.cpp

clean:
	rm -f *.o $(EXE_FILE)