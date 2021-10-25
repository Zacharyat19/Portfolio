#include <iostream>

#include "Animal.h"


/**************************************
 ** Function: Animal
 ** Description: Default constructor
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Creates an object
 **************************************/
Animal::Animal() {
    this->age = 0;
    this->price = 0;
    this->num_babies = 0;
    this->food_cost = 0;
    this->revenue = 0;
}


/*********************************************************
 ** Function: Animal
 ** Description: Non-default constructor
 ** Parameters: Age, Price, Num_babies, Food_cost, Revenue
 ** Pre-Conditions: All parameters are of type int
 ** Post-Conditions: Creates an object
 *********************************************************/
Animal::Animal(int age, int price, int num_babies, int food_cost, int revenue) {
    this->age = age;
    this->price = price;
    this->num_babies = num_babies;
    this->food_cost = food_cost;
    this->revenue = revenue;
}


/***********************************************
 ** Function: Animal
 ** Description: Copy constructor
 ** Parameters: const Animal &old_obj
 ** Pre-Conditions: Old_obj is type Animal
 ** Post-Conditions: Creates a copy of an object
 ***********************************************/
Animal::Animal(const Animal &old_obj) {
    this->age = old_obj.age;
    this->price = old_obj.price;
    this->num_babies = old_obj.num_babies;
    this->food_cost = old_obj.food_cost;
    this->revenue = old_obj.revenue;
}


/**************************************
 ** Function: Animal
 ** Description: Destructor
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Deletes the object
 **************************************/
Animal::~Animal() {}


/******************************************
 ** Function: Getters
 ** Description: Return protected variables
 ** Parameters: None
 ** Pre-Conditions: Object is initialized
 ** Post-Conditions: Returns variable
 ******************************************/
int Animal::get_age() const {
    return this->age;
}

int Animal::get_price() const {
    return this->price;
}

int Animal::get_num_babies() const {
    return this->num_babies;
}

int Animal::get_food_cost() const {
    return this->food_cost;
}

int Animal::get_revenue() const {
    return this->revenue;
}


/******************************************************
 ** Function: Setters
 ** Description: Set value of protected variables
 ** Parameters: Int
 ** Pre-Conditions: All parameters are o type int
 ** Post-Conditions: Sets values to protected variables
 ******************************************************/
void Animal::set_age(int age) {
    this->age = age;
}

void Animal::set_price(int price) {
    this->price = price;
}

void Animal::set_num_babies(int babies) {
    this->num_babies = babies;
}

void Animal::set_food_cost(int food) {
    this->food_cost = food;
}

void Animal::set_revenue(int rev) {
    this->revenue = rev;
}