#include <iostream>

#include "Sea_otter.h"

/*************************************************
 ** Function: Sea_otter
 ** Description: Default constructor for sea_otter
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Sea_otter is initialized
 *************************************************/
Sea_otter::Sea_otter() {}


/***********************************************************
 ** Function: Sea_otter
 ** Description: Non-default constructor
 ** Parameters: Age, Price, Num_babies, Food_cost, Revenue
 ** Pre-Conditions: All parameters are type int
 ** Post-Conditions: Creates a sea_otter through inheritance
 ***********************************************************/
Sea_otter::Sea_otter(int age, int price, int num_babies, int food_cost, int revenue)
:Animal(age,price,num_babies,food_cost,revenue) {}


/**************************************
 ** Function: Sea_otter
 ** Description: Destructor
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Deletes the object
 **************************************/
Sea_otter::~Sea_otter() {}