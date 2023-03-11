#include <iostream>

/********************************************************************
** Function: a_to_i
** Description: turns a character into a decimal value
** Parameters: char character
** Pre-Conditions: the input is a character
** Post-Conditions: returned the decimal value of the character
********************************************************************/ 
int a_to_i(char character) {
    return (int)character;
}

/********************************************************************
** Function: i_to_a
** Description: turns a decimal value into a character value
** Parameters: int decimal
** Pre-Conditions: the input is an integer
** Post-Conditions: returned the character which represents the
decimal value
********************************************************************/
char i_to_a(int decimal) {
    return static_cast<char>(decimal);

}

int main() {
    std::cout << a_to_i('a') << std::endl;
    std::cout << i_to_a(97) << std::endl;
    return 0;
}