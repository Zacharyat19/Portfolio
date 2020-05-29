#include <iostream>

#include "linked_list.h"

void pause() {
        std::cout << "\n\nPress <enter> to continue...";
        std::cin.clear();
        std::cin.ignore(256, '\n');
}


int main(int argc, char const *argv[]) {
	Linked_List l;
	std::cout << "\n\nList successfully created!!\n\n";;

	std::cout << "**********Test 1***********\n";
	std::cout << "Before adding nodes...\n";
	std::cout << "Testing get_length()\n";
	std::cout << "Expected: 0\n";
	std::cout << "Actual  : " << l.get_length() << "\n";
	if (l.get_length() == 0)
		std::cout << "Test 1 PASSED\n\n";
	else
		std::cout << "Test 1 FAILED\n\n";


	std::cout << "**********Test 2***********\n";
	std::cout << "Adding nodes...\n";
	std::cout << "Test 2.1: Testing push_front()\n";
	l.push_front(5);
	l.push_front(100);
	l.push_front(0);
	l.push_front(-8);
	l.push_front(16);
	std::cout << "Expected: 16 -8 0 100 5\n";
	std::cout << "Actual  : "; 
	l.print();
	std::cout << "Expected length: 5\n";
	std::cout << "Actual length  : " << l.get_length() << "\n";
	std::cout << "Test 2.1 completed.\n";
	pause();

	std::cout << "Test 2.2: Testing push_back()\n";
	l.push_back(5);
	l.push_back(1);
	l.push_back(2);
	l.push_back(7);
	l.push_back(7919);
	std::cout << "Expected: 16 -8 0 100 5 5 1 2 7 7919\n";
	std::cout << "Actual  : "; 
	l.print();
	std::cout << "Expected length: 10\n";
	std::cout << "Actual length  : " << l.get_length() << "\n";
	std::cout << "Test 2.2 completed.\n";
	pause();

	std::cout << "Test 2.3: Testing insert()\n";
	l.insert(11, 0);
	l.insert(20, 100);
	l.insert(20, l.get_length()-1);
	l.insert(9, 5);
	std::cout << "Expected: 11 16 -8 0 100 9 5 5 1 2 7 7919 20\n";
	std::cout << "Actual  : "; 
	l.print();
	std::cout << "Expected length: 13\n";
	std::cout << "Actual length  : " << l.get_length() << "\n";
	std::cout << "Test 2.3 completed.\n";
	pause();

	std::cout << "**********Test 3***********\n";
	std::cout << "Sorting...\n";
	std::cout << "Test 3.1: Testing sort_ascending()\n";
	l.sort_ascending();
	std::cout << "Expected: -8 0 1 2 5 5 7 9 11 16 20 100 7919\n";
	std::cout << "Actual  : "; 
	l.print();
	std::cout << "Test 3.1 completed.\n";
	pause();

	std::cout << "Test 3.2: Testing sort_descending()\n";
	l.sort_descending();
	std::cout << "Expected: 7919 100 20 16 11 9 7 5 5 2 1 0 -8\n";
	std::cout << "Actual  : "; 
	l.print();
	std::cout << "Test 3.2 completed.\n";
	pause();

	std::cout << "**********Test 4***********\n";
	std::cout << "Tesing count_prime()\n";
	std::cout << "Expected: 6\n";
	std::cout << "Actual  : " << l.count_prime() << "\n";
	if (l.count_prime() == 6)
		std::cout << "Test 4 PASSED\n";
	else
		std::cout << "Test 4 FAILED\n";


	std::cout << "**********Test 5***********\n";
	std::cout << "Tesing clear()\n";
	l.clear();
	std::cout << "Expected length: 0\n";
	std::cout << "Actual length  : " << l.get_length() << "\n";
	if (l.get_length() == 0)
		std::cout << "Test 5 PASSED\n";
	else
		std::cout << "Test 5 FAILED\n";

	return 0;
}