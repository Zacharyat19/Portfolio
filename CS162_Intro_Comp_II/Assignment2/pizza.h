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
    Pizza();
    Pizza(std::string, int, int, int, int, std::string *);
    Pizza(const Pizza &);
    Pizza &operator=(const Pizza &);
    ~Pizza();

    void set_name(std::string);
    void set_small_cost(int);
    void set_medium_cost(int);
    void set_large_cost(int);
    void set_ingredients(std::string *);
    void set_num_ingredients(int);
    std::string get_name() const;
    int get_num_ingredients() const;
    int get_small_cost() const;
    int get_medium_cost() const;
    int get_large_cost() const;
    std::string *get_ingredients() const;
    void load_pizza(std::ifstream &);
};

#endif