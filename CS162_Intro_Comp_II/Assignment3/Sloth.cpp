#include <iostream>

#include "Sloth.h"


/**************************************
 ** Function: Sloth
 ** Description: Default constructor
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Creates an object
 **************************************/
Sloth::Sloth() {}


/*********************************************************
 ** Function: Sloth
 ** Description: Non-default constructor
 ** Parameters: Age, Price, Num_babies, Food_cost, Revenue
 ** Pre-Conditions: All parameters are of type int
 ** Post-Conditions: Creates an object through inheritance
 *********************************************************/
Sloth::Sloth(int age, int price, int num_babies, int food_cost, int revenue)
:Animal(age,price,num_babies,food_cost,revenue) {}


/**************************************
 ** Function: Sloth
 ** Description: Destructor
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Deletes the object
 **************************************/
Sloth::~Sloth() {}