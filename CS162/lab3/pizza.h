#ifndef PIZZA_H
#define PIZZA_H

#include <string>
#include <fstream>

class Pizza {
  private:
    std::string name;
    int small_cost;
    int medium_cost;
    int large_cost;
    int num_ingredients;
    std::string *ingredients;
  public:
    //need to include accessor functions and mutator functions for each private member
    //need to include constructors, copy constructors, assignment operator overload,
    //and destructors where appropriate
    Pizza();
    ~Pizza();

    void set_name(std::string);
    std::string get_name() const;
    void set_num_ingredients(int);
    int get_num_ingredients() const;
    void populate_pizza(std::ifstream &);
    int set_small_cost(int);
    int set_medium_cost(int);
    int set_large_cost(int);
    int get_small_cost() const;
    int get_medium_cost() const;
    int get_large_cost() const;
    std::string set_ingredients(std::string *);
    std::string *get_ingredients() const;
};

#endif