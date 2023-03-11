#ifndef MENU_H
#define MENU_H 

#include <string>
#include <fstream>
#include "pizza.h"


class Menu {
  private:
    int num_pizzas;
    Pizza *pizzas;
  public:
    //need to include accessor functions and mutator functions for each private member
    //need to include constructors, copy constructors, assignment operator overload,
    //and destructors where appropriate

    // Only one of the following two prototypes should be used:
    Menu search_pizza_by_cost(int upper_bound);
    //Menu search_pizza_by_cost(int upper_bound, string size);

    Menu search_pizza_by_ingredients_to_include(std::string *ingredients, int num_ingredients);
    Menu search_pizza_by_ingredients_to_exclude(std::string *ingredients, int num_ingredients);
    void add_to_menu(Pizza pizza_to_add);
    void remove_from_menu(int index_of_pizza_on_menu);
};

#endif