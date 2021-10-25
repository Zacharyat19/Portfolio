#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>
#include <fstream>
#include "menu.h"
#include "emp_hours.h"

class Restaurant {
  private:
    Menu menu;
    employee  *employees;
    hours *week;
    std::string name;
    std::string phone;
    std::string address;
    /*
      employees can change throughout the program
      Therefore a variable is needed to get the current number of employees
    */
    int num_employees;
    /*
      The restaurant may not be open for seven days a week 
      Therefore a variable is needed to represent how mnay days
      the restaurant is open
    */
    int num_days_open;
  public:
    Restaurant();
    Restaurant(const Restaurant &);
    Restaurant &operator=(const Restaurant &);
    ~Restaurant();

    Menu get_menu() const;
    employee *get_employee() const;
    hours *get_hours() const;
    std::string get_name() const;
    std::string get_phone() const;
    std::string get_address() const;
    int get_num_employees() const;
    int get_num_days_open() const;

    void set_employee(employee *);
    void set_hours(hours *);
    void set_name(std::string);
    void set_phone(std::string);
    void set_address(std::string);
    void set_num_employees(int);
    void set_num_days_open(int);

    void load_data();
    bool login(std::string id, std::string password);
    void view_menu();
    void view_hours();
    void view_address();
    void view_phone();
    void search_menu_by_price();
    void search_by_ingredients();
    void place_order(Pizza *selection, int selection_size, int *num_ordered, std::string *string);
    void change_hours();
    void add_to_menu();
    void remove_from_menu();
    void view_orders();
    void remove_orders();
    void run();
};

#endif