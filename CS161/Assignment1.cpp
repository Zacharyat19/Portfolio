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
 ** Post-Conditions: main outputs taxes and gross income.
 ***************************************************************************************/

int main() {
    //Declare variables and get input
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

    std::cout.flush();

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
    std::cout << "Your gross income is "<< grossIncome << "$" << std::endl;

    //Calculate taxes
    if(taxYear == 2017) {
        if(state == 'A' || state == 'a') {
            std::cout << "Your total taxes are " << (0.06 * grossIncome) << "$" << std::endl; 
        } else if(state == 'B' || state == 'b') {
            if(grossIncome < 2000) {
                std::cout << "Your taxes are " << 0 << "$" << std::endl;
            } else if(grossIncome >= 2000 && grossIncome <= 10000) {
                std::cout << "Your taxes are " << 100 << "$" << std::endl;
            } else if(grossIncome > 100000) {
                std::cout << "Your taxes are " << (0.1 * (grossIncome - 10000)) + 100 << "$" << std::endl;
            }
        } else if(state == 'C' || state == 'c') {
            if(grossIncome < 3500) {
                std::cout << "Your taxes are " << 0.05 * grossIncome << "$" << std::endl;
            } else if(grossIncome >= 3500 && grossIncome <= 9000) {
                std::cout << "Your taxes are " << (0.07 * (grossIncome - 3500)) + 175 << "$" << std::endl;
            } else if(grossIncome > 9000 && grossIncome <= 125000) {
                std::cout << "Your taxes are "  << (0.09 * (grossIncome - 9000)) + 560 << "$" << std::endl;
            } else if(grossIncome > 125000) {
                std::cout << "Your taxes are " << (0.099 * (grossIncome - 125000)) + 11000 << "$" << std::endl;
            }
        }
    } else if(taxYear == 2018) {
        if(state == 'A' || state == 'a') {
            if(grossIncome < 2500) {
                std::cout << "Your taxes are " << (0.08 * grossIncome) << "$" << std::endl;
            }
        } else if(state == 'B' || state == 'b') {
            if(grossIncome < 2500) {
                std::cout << "Your taxes are " << 0 << "$" << std::endl;
            } else if(grossIncome >= 2500 && grossIncome <= 10000) {
                std::cout << "Your taxes are " << 115 << "$" << std::endl;
            } else if(grossIncome > 10000) {
                std::cout << "Your taxes are " <<  (0.105 * (grossIncome - 10000)) + 115 << "$" << std::endl;
            }
        } else if(state == 'C' || state == 'c') {
            if(grossIncome < 3450) {
                std::cout << "Your taxes are " << 0.05 * grossIncome << "$" << std::endl;
            } else if(grossIncome >= 3450 && grossIncome <= 8700) {
                std::cout << "Your taxes are " << (0.07 * (grossIncome - 3450)) + 172.5 << "$" << std::endl;
            } else if(grossIncome > 8700 && grossIncome <= 125000) {
                std::cout << "Your taxes are " << (0.09 * (grossIncome - 8700)) + 540 << "$" << std::endl;
            } else if(grossIncome > 125000) {
                std::cout << "Your taxes are " << (0.099 * (grossIncome - 12500)) + 11007 << "$" << std::endl;
            }
        }
    }
    return 0;
}