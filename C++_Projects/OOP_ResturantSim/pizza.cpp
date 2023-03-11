#include <iostream>
#include <fstream>
#include <string>

#include "pizza.h"


/*******************************************************
 ** Function: Pizza
 ** Description: Pizza class constructor
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: sets default values to pizza object
 *******************************************************/
Pizza::Pizza() {
    this->name = "";
    this->small_cost = 0;
    this->medium_cost = 0;
    this->large_cost = 0;
    this->num_ingredients = 0;
    this->ingredients = NULL;
}


/**************************************************************************************
 ** Function: Pizza
 ** Description: Non-default pizza constructor
 ** Parameters: name, small_cost, medium_cost, large_cost, num_ingredients, ingredients
 ** Pre-Conditions: name is string, all costs and num_ingredietns are ints, 
                    ingredients is a string array
 ** Post-Conditions: creates pizza object
 **************************************************************************************/
Pizza::Pizza(std::string name, int small_cost, int medium_cost, int large_cost, int num_ingredients, std::string *ingredients) {
    this->name = name;
    this->small_cost = small_cost;
    this->medium_cost = medium_cost;
    this->large_cost = large_cost;
    this->num_ingredients = num_ingredients;
    this->ingredients = ingredients;
}


/************************************************
 ** Function: Pizza
 ** Description: copy constructor
 ** Parameters: const Pizza &old_obj
 ** Pre-Conditions: old_obj is an object
 ** Post-Conditions: creates a copy of old_object
 ************************************************/
Pizza::Pizza(const Pizza &old_obj) {
	this->name = old_obj.name;
	this->small_cost = old_obj.small_cost;
	this->medium_cost = old_obj.medium_cost;
	this->large_cost = old_obj.large_cost;
    this->num_ingredients = old_obj.num_ingredients;
	
	this->ingredients = new std::string [this->num_ingredients];
	for (int i = 0; i < this->num_ingredients; i++) {
		this->ingredients[i] = old_obj.ingredients[i];
    }
}


/************************************************
 ** Function: Pizza
 ** Description: AOO of pizza class
 ** Parameters: const Pizza &old_obj
 ** Pre-Conditions: old_obj is an object
 ** Post-Conditions: Assigns an object to another
 ************************************************/
Pizza &Pizza::operator=(const Pizza &old_obj) {
	if (this != &old_obj){
		this->name = old_obj.name;
		this->small_cost = old_obj.small_cost;
		this->medium_cost = old_obj.medium_cost;
		this->large_cost = old_obj.large_cost;
        this->num_ingredients = old_obj.num_ingredients;
		
		if (this->ingredients != NULL) {
			delete [] this->ingredients;
        }
		this->ingredients = new std::string [this->num_ingredients];
		for (int i = 0; i < this->num_ingredients; i++) {
			this->ingredients[i] = old_obj.ingredients[i];
        }
	}
	return *this;
}


/**************************************
 ** Function: Pizza
 ** Description: pizza class destructor
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: object is deleted
 **************************************/
Pizza::~Pizza() {
	if (this->ingredients != NULL) {
		delete [] this->ingredients;
		this->ingredients = NULL;
	}
}


/*******************************************************
 ** Function: setters
 ** Description: sets the private variables of the class
 ** Parameters: string, int
 ** Pre-Conditions: ints are int and strings are strings
 ** Post-Conditions: private variables have values
 *******************************************************/
void Pizza::set_name(std::string name) {
    this->name = name;
}

void Pizza::set_ingredients(std::string *ingredients) {
    this->ingredients = ingredients;
}

void Pizza::set_num_ingredients(int num) {
    this->num_ingredients = num;
}

void Pizza::set_small_cost(int cost) {
    this->small_cost = cost;
}

void Pizza::set_medium_cost(int cost) {
    this->medium_cost = cost;
}

void Pizza::set_large_cost(int cost) {
    this->large_cost = cost;
}


/************************************************
 ** Function: getters
 ** Description: return a private variable
 ** Parameters: string, int
 ** Pre-Conditions: private variables are defined
 ** Post-Conditions: returns variable
 ************************************************/
int Pizza::get_small_cost() const {
    return this->small_cost;
}

int Pizza::get_medium_cost() const {
    return this->medium_cost;
}

int Pizza::get_large_cost() const {
    return this->large_cost;
}

std::string Pizza::get_name() const {
    return this->name;
}

std::string *Pizza::get_ingredients() const {
    return ingredients;
}

int Pizza::get_num_ingredients() const {
    return this->num_ingredients;
}


/******************************************************
 ** Function: load_pizza
 ** Description: loads data from menu.txt
 ** Parameters: ifstream
 ** Pre-Conditions: fin is defined and menu.txt is open
 ** Post-Conditions: class variables are filled
 ******************************************************/
void Pizza::load_pizza(std::ifstream &fin) {
    std::string name;
    int small_cost, medium_cost, large_cost , num_ingredients;
    fin >> name >> small_cost >> medium_cost >> large_cost >> num_ingredients;
    Pizza::set_name(name);
    Pizza::set_small_cost(small_cost);
    Pizza::set_medium_cost(medium_cost);
    Pizza::set_large_cost(large_cost);
    Pizza::set_num_ingredients(num_ingredients);
    ingredients = new std::string[num_ingredients];

    for(int i = 0; i < num_ingredients; i++) {
        fin >> ingredients[i];
    }
    
}