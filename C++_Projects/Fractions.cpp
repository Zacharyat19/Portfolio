/*************************************************************
 ** Program: Fractions
 ** Author: Zach Taylor.
 ** Date: 2/13/2020
 ** Description: Calculates the lowest fraction based on input
 ** Input: numerator, denominator
 ** Output: gcd, fraction
 *************************************************************/
#include <iostream>
#include <cmath>

bool toLowestTerms(int &numerator, int &denominator);
int gcd(int num1, int num2);

int main() {
    int numerator = 0;
    int denominator = 0;
    if(!toLowestTerms(numerator, denominator)) {
        std::cout << "Invalid input. Please run again." << std::endl;
        return 0;
    }

    int fraction = gcd(numerator,denominator);
    numerator = numerator / fraction;
    denominator = denominator / fraction;

    std::cout << "The reduced fraction is " << numerator << "/" << denominator << std::endl;
    
}


/***************************************************************************************
** Function: toLowestTerms()
** Description: Gets an input from the user and return false if the denominator is zero
** Parameters: int &numerator, int &denominator
** Pre-conditions: Both inputs are ints
** Post-conditions: Returns false if the denominator is zero
****************************************************************************************/
bool toLowestTerms(int &numerator, int &denominator) {
    std::cout << "Enter the numerator: " << std::endl;
    std::cin >> numerator;
    std::cout << "Enter the denominator: " << std::endl;
    std::cin >> denominator;

    if(denominator == 0) {
        return false;
    }
    return true;
}


/********************************************************************************
** Function: gcd
** Description: Gets the greatest common factopr of the numerator and denominator
** Parameters: num1, num2
** Pre-conditions: accepts 2 valid integers
** Post-conditions: returns the greatest common denominator
*********************************************************************************/
int gcd(int num1, int num2) {
    int smallest = 0;
    int gcd = 0;
    
    (std::abs(num1) < std::abs(num2))? smallest = std::abs(num1) : smallest = std::abs(num2);

    for (int i = 1; i <= smallest; i++){
        if ((num1 % i == 0) && (num2 % i == 0))
        {
            gcd = i;
        }
    }

    return gcd;
}