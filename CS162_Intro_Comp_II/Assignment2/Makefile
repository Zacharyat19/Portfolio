CC=g++
EXE_FILE=prog

all: $(EXE_FILE)

$(EXE_FILE): pizza.o pizza.h menu.o menu.h emp_hours.o emp_hours.h restaurant.o restaurant.h prog.cpp
	$(CC) pizza.o menu.o emp_hours.o restaurant.o prog.cpp -o $(EXE_FILE)

pizza.o: pizza.h pizza.cpp
	$(CC) -c pizza.cpp

menu.o: menu.h menu.cpp
	$(CC) -c menu.cpp

emp_hours.o: emp_hours.h emp_hours.cpp
	$(CC) -c emp_hours.cpp

restaurant.o: restaurant.h restaurant.cpp
	$(CC) -c restaurant.cpp

clean:
	rm -f *.o $(EXE_FILE)