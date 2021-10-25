/************************************************
 ** Program: Bytes Pizza
 ** Author: Zach Taylor.
 ** Date: 4/26/2020.
 ** Description: Models a pizza restaurant
 ** Input: resturant_info, menu, employee, orders
 ** Output: output file or terminal
 ************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include "restaurant.h"

int main() {
	Restaurant r;
    r.load_data();
    r.run();
	return 0;
}