/*************************************************************
 ** Program: Fractals
 ** Author: Zach Taylor.
 ** Date: 2/13/2020
 ** Description: Prints a fractal design with recursion
 ** Input: num, col
 ** Output: fractal pattern
 *************************************************************/
#include <iostream>

void pattern(int num, int col);

int main() {
    int userNum = 0;
    int userCol = 0;

    std::cout << "Enter number of center stars: " << std::endl;
    std::cin >> userNum;
    std::cout << "Enter column spacing: ";
    std::cin >> userCol;
    pattern(userNum, userCol);
}


/*******************************************************************
** Function: pattern
** Description: Gets two integer inputs
** Parameters: int num, int col
** Pre-conditions: accepts 2 valid integers
** Post-conditions: prints out the fractal recursively
*******************************************************************/
void pattern(int num, int col) {
    if (num > 0) {
        pattern(num - 2, col + 1);
        for (int i = 0; i < col; i++) {
            std::cout << "  ";
        }
        for (int i = 0; i < num; i++) {
            std::cout << "* ";
        }
        std::cout << std::endl;
        pattern(num - 2, col + 1);
    }
}