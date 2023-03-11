#include <iostream>
#include <fstream>

#include "pizza.h"

void Pizza::set_name(std::string name) {
    this->name = name;
}

std::string Pizza::get_name() const {
    return this->name;
}

void Pizza::set_num_ingredients(int num) {
    this->num_ingredients = num;
}

int Pizza::get_num_ingredients() const {
    return this->num_ingredients;
}

int Pizza::set_small_cost(int cost) {
    this->small_cost = cost;
}

int Pizza::set_medium_cost(int cost) {
    this->medium_cost = cost;
}

int Pizza::set_large_cost(int cost) {
    this->large_cost = cost;
}

int Pizza::get_small_cost() const {
    return this->small_cost;
}

int Pizza::get_medium_cost() const {
    return this->medium_cost;
}

int Pizza::get_large_cost() const {
    return this->large_cost;
}

std::string Pizza::set_ingredients(std::string *ingredients) {
    this->ingredients = ingredients;
}

std::string *Pizza::get_ingredients() const {
    return ingredients;
}

void Pizza::populate_pizza(std::ifstream &fin) {
    std::string name;
    int small_cost, medium_cost, large_cost , num_ingredients;
    std::string *ingredients = new std::string[num_ingredients];
    
    fin >> name >> small_cost >> medium_cost >> large_cost >> num_ingredients;
    Pizza::set_name(name);
    Pizza::set_small_cost(small_cost);
    Pizza::set_medium_cost(medium_cost);
    Pizza::set_large_cost(large_cost);
    Pizza::set_num_ingredients(num_ingredients);

    for(int i = 0; i < num_ingredients; i++) {
        fin >> ingredients[i];
    }
    
    Pizza::set_ingredients(ingredients);
}