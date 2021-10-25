#include <iostream>
#include <fstream>
#include <string>

#include "menu.h"


/****************************************************
 ** Function: Menu
 ** Description: class constructor
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: sets default values to variables
 ****************************************************/
Menu::Menu() {
    this->num_pizzas = 0;
    this->pizzas = NULL;
}


/*********************************************************************
 ** Function: Menu
 ** Description: Non-default constructor
 ** Parameters: num_pizzas, pizzas
 ** Pre-Conditions: num_pizzas is an int, pizzas is an array of pizzas
 ** Post-Conditions: sets values to private variables
 *********************************************************************/
Menu::Menu(int num_pizzas, Pizza *pizzas) {
    this->num_pizzas = num_pizzas;
    this->pizzas = pizzas;
}


/************************************************
 ** Function: Menu
 ** Description: copy constructor
 ** Parameters: const Menu &old_obj
 ** Pre-Conditions: old_obj is an object
 ** Post-Conditions: creates a copy of the object
 ************************************************/
Menu::Menu(const Menu &old_obj) {
	this->num_pizzas = old_obj.num_pizzas;
	
	this->pizzas = new Pizza [this->num_pizzas];
	for (int i = 0; i < this->num_pizzas; i++) {
		this->pizzas[i] = old_obj.pizzas[i];
    }
}


/*************************************************
 ** Function: Menu
 ** Description: AOO for Menu class
 ** Parameters: const Menu &old_obj
 ** Pre-Conditions: old_obj is an object
 ** Post-Conditions: Assigns old_obj to new object
 *************************************************/
Menu &Menu::operator=(const Menu &old_obj) {
	if (this != &old_obj){
		this->num_pizzas = old_obj.num_pizzas;
		
		if (this->pizzas != NULL) {
			delete [] this->pizzas;
        }

		this->pizzas = new Pizza [this->num_pizzas];
		for (int i = 0; i < this->num_pizzas; i++) {
			this->pizzas[i] = old_obj.pizzas[i];
        }
	}
	return *this;
}


/*************************************
 ** Function: Menu
 ** Description: Destructor
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: object is deleted
 *************************************/
Menu::~Menu() {
	if (this->pizzas != NULL) {
		delete [] this->pizzas;
		this->pizzas = NULL;
	}
}


/*********************************************
 ** Function: getters
 ** Description: returns the private variables 
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: returns variables
 *********************************************/
int Menu::get_num_pizzas() const {
    return this->num_pizzas;
}

Pizza *Menu::get_pizzas() const {
    return pizzas;
}


/*******************************************************
 ** Function: setters
 ** Description: sets the private variables of the class
 ** Parameters: string, int
 ** Pre-Conditions: ints are int and strings are strings
 ** Post-Conditions: private variables have values
 *******************************************************/
void Menu::set_num_pizzas(int num_pizzas) {
    this->num_pizzas = num_pizzas;
}

void Menu::set_pizzas(Pizza *pizzas) {
    this->pizzas = pizzas;
}


/*************************************************
 ** Function: search_pizza_by_cost
 ** Description: prints pizzas within a cost range
 ** Parameters: int
 ** Pre-Conditions: upper_bound is an int
 ** Post-Conditions: returns an object
 *************************************************/
Menu Menu::search_pizza_by_cost(int upper_bound) {
    Menu temp;
	for (int i = 0; i < this->num_pizzas; ++i) {
		if((this->pizzas[i].get_small_cost() < upper_bound) || (this->pizzas[i].get_medium_cost() < upper_bound) || (this->pizzas[i].get_large_cost() < upper_bound)) {
			temp.add_to_menu(this->pizzas[i]);
		}
	}
	return temp;
}


/***************************************************************************
 ** Function: search_pizza_by_ingredients_to_include
 ** Description: searchs based on ingredients
 ** Parameters: std::string *, int
 ** Pre-Conditions: ingredients is a string array, num_ingredients is an int
 ** Post-Conditions: returns an object
 ***************************************************************************/
Menu Menu::search_pizza_by_ingredients_to_include(std::string *ingredients, int num_ingredients) {
    int a = 0, b = 0, c = 0;

    for(int i = 0; i < this->num_pizzas; i++) {
        for(int j = 0; j < pizzas[i].get_num_ingredients(); j++) {
            for(int k = 0; k < num_ingredients; k++) {
                if(pizzas[i].get_ingredients()[j] == ingredients[k]) {
                    a++;
                    if(a == num_ingredients) {
                        b++;
                    }
                }
            }
        }
    }
    Pizza *p = new Pizza[b];
    Menu temp(b, p);
    for(int i = 0; i < this->num_pizzas; i++) {
        for(int j = 0; j < pizzas[i].get_num_ingredients(); j++) {
            for(int k = 0; k < num_ingredients; k++) {
                if(pizzas[i].get_ingredients()[j] == ingredients[k]) {
                    c++;
                    if(c == num_ingredients) {
                        temp.get_pizzas()[i] = this->pizzas[i];
                    }
                }
            }
        }
    }
    return temp;
}


/***************************************************************************
 ** Function: search_pizza_by_ingredients_to_exclude
 ** Description: searchs based on ingredients
 ** Parameters: std::string *, int
 ** Pre-Conditions: ingredients is a string array, num_ingredients is an int
 ** Post-Conditions: returns an object
 ***************************************************************************/
Menu Menu::search_pizza_by_ingredients_to_exclude(std::string *ingredients, int num_ingredients) {
    //wish  i wasn't dumb
}


/*************************************************
 ** Function: add_to_mneu
 ** Description: Adds a pizza object to menu
 ** Parameters: Pizza
 ** Pre-Conditions: pizza_to_add is an object
 ** Post-Conditions: adds an object to pizza array
 *************************************************/
void Menu::add_to_menu(Pizza pizza_to_add) {
    Pizza *pizza_temp = new Pizza[this->num_pizzas + 1];
    for(int i = 0; i < num_pizzas; i++) {
        pizza_temp[i] = this->pizzas[i];
    }
    pizza_temp[this->num_pizzas] = pizza_to_add;
    if(this->pizzas != NULL) {
        delete []this->pizzas;
    }
    this->pizzas = pizza_temp;
    this->num_pizzas++;

}


/****************************************************
 ** Function: remove_from_menu
 ** Description: removes an object from menu
 ** Parameters: int 
 ** Pre-Conditions: index_of_pizza_on_menu is an int 
 ** Post-Conditions: object is removed from the array
 ****************************************************/
void Menu::remove_from_menu(int index_of_pizza_on_menu) {
    int idx = index_of_pizza_on_menu - 1;

    if(idx < 0 || idx > this->num_pizzas) {
        std::cout << "Pizza not found" << std::endl;
        return;
    }
    for(int i = idx; i < this->num_pizzas - 1; i++) {
        this->pizzas[i] = this->pizzas[i + 1];
    }
    this->num_pizzas--;
}


/********************************************************
 ** Function: load_data
 ** Description: loads data from files
 ** Parameters: fin
 ** Pre-Conditions: fin was created and text file is open
 ** Post-Conditions: array is filled
 ********************************************************/
void Menu::load_data(std::ifstream &fin) {
    fin.open("menu.txt");
    if(!fin.is_open()) {
        std::cout << "Error opening file to read." << std::endl;
        return;
    }
    int num_pizzas;
    fin >> num_pizzas;

    Menu::set_num_pizzas(num_pizzas);
    pizzas = new Pizza[num_pizzas];
    for(int i = 0; i < num_pizzas; i++) {
        Menu::get_pizzas()[i].load_pizza(fin);
    }
    fin.clear();
    fin.close();
}


/*****************************************
 ** Function: view_menu
 ** Description: prints the menu
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: prints menu to screen
 *****************************************/
void Menu::view_menu() {
    for(int i = 0; i < Menu::get_num_pizzas(); i++) {
        std::cout << i + 1 << ". " << Menu::get_pizzas()[i].get_name() << " " << Menu::get_pizzas()[i].get_small_cost() << " "
                  << Menu::get_pizzas()[i].get_medium_cost() << " " << Menu::get_pizzas()[i].get_large_cost() << " "
                  << Menu::get_pizzas()[i].get_num_ingredients() << " ";
        for(int j = 0; j < Menu::get_pizzas()[i].get_num_ingredients(); j++) {
                std::cout << Menu::get_pizzas()[i].get_ingredients()[j] << " ";
        }
        std::cout << std::endl;
    }
}