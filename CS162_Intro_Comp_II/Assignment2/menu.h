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
    Menu();
    Menu(int, Pizza *);
    Menu(const Menu &);
    Menu &operator=(const Menu &);
    ~Menu();

    int get_num_pizzas() const;
    Pizza *get_pizzas() const;
    void set_num_pizzas(int);
    void set_pizzas(Pizza *);


    Menu search_pizza_by_cost(int upper_bound);

    Menu search_pizza_by_ingredients_to_include(std::string *ingredients, int num_ingredients);
    Menu search_pizza_by_ingredients_to_exclude(std::string *ingredients, int num_ingredients);
    void add_to_menu(Pizza pizza_to_add);
    void remove_from_menu(int index_of_pizza_on_menu);
    void load_data(std::ifstream &);
    void view_menu();
};

#endif