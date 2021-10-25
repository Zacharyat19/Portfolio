/*******************************
 ** Program: Zoo Tycoon
 ** Author: Zach Taylor.
 ** Date: 5/10/2020.
 ** Description: Zoo tycoon game
 ** Input: User selections
 ** Output: Game interface
 *******************************/
#include <iostream>

#include "Zoo.h"
#include "Animal.h"

int main() {
    Zoo z;
    std::cout << "\nWelcome to Zoo Tycoon!" << std::endl;
    while(z.get_bank() > 0) {
        std::cout << "\nIt's month " << z.get_month() << " and you have " << z.get_bank() <<
                     " dollars, what would you like to do?" << std::endl;
        std::cout << "1) Buy monkeys\n2) Buy sea otters\n3) Buy sloths\n4) Buy none" << std::endl;
        z.display_monkeys();
        z.display_sea_otters();
        z.display_sloths();

        if(z.get_month() > 0) {
            z.increase_age();
            z.monkey_revenue();
            z.sea_otter_revenue();
            z.sloth_revenue();
            z.event();
        }
        z.buy_sell();
        ++z;
    }
    std::cout << "Ran out of money, game over." << std::endl;
    return 0;
}