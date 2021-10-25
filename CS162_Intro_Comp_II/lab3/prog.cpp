#include <iostream>
#include <fstream>
#include <cstdlib>

#include "pizza.h"

int main(int argc, char *argv[]) {
	std::ifstream fin;
    fin.open("menu.txt");

    if(!fin.is_open()) {
        std::cout << "Error opening file to read." << std::endl;
        return 1;
    }

    std::string temp;
    int num;
    std::getline(fin, temp);
    num = atoi(temp.c_str());

	return 0;
}