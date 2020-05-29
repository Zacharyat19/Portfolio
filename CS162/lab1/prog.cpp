#include <iostream>
#include <stdlib.h>
#include "multdiv.h"

int main(int argc, char *argv[]) {
    int rows = 0;
    int col = 0;

    if(argc != 3) {
        std::cout << "Invalid number of arguments, try again" << std::endl;
        return 0;
    }

    char *temp = argv[1];
    char *temp2 = argv[2];

    if(!(isValidDimensions(temp, temp2))) {
        std::cout << "Invalid type." << std::endl;
        std::cout << "Enter an integer greater than 0 for rows: ";
        std::cin >> rows;
        std::cout << "Enter an integer greater than 0 for col: ";
        std::cin >> col;
    } else {
        rows = atoi(argv[1]);
        col = atoi(argv[2]);
    }

    multdivEntry **table = createTable(rows, col);
    printTable(table, rows, col);
    deleteTable(table, rows);

    while(true) {
        int choice;
        std::cout << "Would you like to see a different size matrix (0-no, 1-yes): ";
        std::cin >> choice;
        if(choice == 0) {
            break;
        } else if(choice == 1) {
            std::cout << "Enter an integer greater than 0 for rows: ";
            std::cin >> rows;
            std::cout << "Enter an integer greater than 0 for col: ";
            std::cin >> col;
            multdivEntry **table = createTable(rows, col);
            printTable(table, rows, col);
            deleteTable(table, rows);
        } else {
            std::cout << "Invalid input, try again" << std::endl;
        }
    }

    return 0;
}