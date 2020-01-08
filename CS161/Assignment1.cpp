/**************************************************************************************
 ** Program: Calculate Gross Income and Taxes for a Salesperson.
 ** Author: Zach Taylor.
 ** Date: 1/6/2020.
 ** Description: Calculates taxes and gross pay by year.
 ** Input: monthlySalary, monthsWorked, costCar, carsSold, misconducts, taxYear, state.
 ** Output: grossIncome, taxes.
 **************************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>

/**************************************************************************************
 ** Function: main.
 ** Description: Main function that calculates gross income.
 ** Parameters: none.
 ** Pre-Conditions: All inputs are appropriate types.
 ** Post-Conditions: 
 ***************************************************************************************/

int main() {
    //Declare variables
    int monthlySalary;
    int monthsWorked;
    int costCar;
    int carsSold;
    int misconducts;
    int taxYear;
    char state;

    std::cout << "What is your monthly salary: ";
    std::cin >> monthlySalary;

    std::cout << "How many months have you worked this year: ";
    std::cin >> monthsWorked;

    std::cout << "What is the cost of the car: ";
    std::cin >> costCar;

    std::cout << "How many cars have been sold: ";
    std::cin >> carsSold;

    std::cout << "How many misconducts have been observed: ";
    std::cin >> misconducts;

    std::cout << "What is the tax year, 2017 or 2018: ";
    std::cin >> taxYear;

    std::cout << "What state do you live in (A,B,C): ";
    std::cin >> state;

    //Annual Salary
    int annualSalary = monthlySalary * monthsWorked;

    //Profit
    srand(time(NULL));
    double r = ((rand() % 5 + 6.0)/100.0) + 1.0;
    double profit = carsSold * ((costCar * r) - costCar);

    //Deductions
    int deductions;
    if(misconducts == 0) {
        deductions = 0;
    } else {
        deductions = 100 * (pow(2,misconducts - 1));
    }

    //Calculate gross income
    double grossIncome = annualSalary + (0.02 * profit) - deductions;

    std::cout << "Your gross income is ", grossIncome;

    return 0;
}


/**************************************************************************************
 ** Function: taxes.
 ** Description: Calculates taxes for 2017 or 2018.
 ** Parameters: state, year
 ** Pre-Conditions: state is a char and year is an int.
 ** Post-Conditions: taxes outputs a value for the taxes owed.
 ***************************************************************************************/

int taxes(char state, int year, double income) {
    double taxes;

    if(year == 2017) {
        if(state == 'A' || state == 'a') {
            std::cout << "Your total taxes are: ", (0.06 * income); 
        } else if(state == 'B' || state == 'b') {
            if(income < 2000) {
                taxes = 0;
            } else if(income >= 2000 && income <= 10000) {
                taxes = 100;
            } else if(income > 100000) {
                taxes = (0.1 * (income - 10000)) + 100;
            }
        } else if(state == 'C' || state == 'c') {
            if(income < 3500) {
                taxes = 0.05 * income;
            } else if(income >= 3500 && income <= 9000) {
                taxes = (0.07 * (income - 3500)) + 175;
            } else if(income > 9000 && income <= 125000) {
                taxes = (0.09 * (income - 9000)) + 560;
            } else if(income > 125000) {
                taxes = (0.099 * (income - 125000)) + 11000;
            }
        }
    } else if(year == 2018) {
        if(state == 'A' || state == 'a') {
            if(income < 2500) {
                taxes = (0.08 * income);
            }
        } else if(state == 'B' || state == 'b') {
            if(income < 2500) {
                taxes = 0;
            } else if(income >= 2500 && income <= 10000) {
                taxes = 115;
            } else if(income > 10000) {
                taxes = (0.105 * (income - 10000)) + 115;
            }
        } else if(state == 'C' || state == 'c') {
            if(income < 3450) {
                taxes = 0.05 * income;
            } else if(income >= 3450 && income <= 8700) {
                taxes = (0.07 * (income - 3450)) + 172.5;
            } else if(income > 8700 && income <= 125000) {
                taxes = (0.09 * (income - 8700)) + 540;
            } else if(income > 125000) {
                taxes = (0.099 * (income - 12500)) + 11007;
            }
        }
    }
}