CC=g++
EXE_FILE=prog

all: $(EXE_FILE)

$(EXE_FILE): test_linked_list.cpp linked_list.o linked_list.h node.h
	$(CC) test_linked_list.cpp linked_list.o -o $(EXE_FILE)

linked_list.o: linked_list.h linked_list.cpp
	$(CC) -c linked_list.cpp
	
clean:
	rm -f *.o $(EXE_FILE)