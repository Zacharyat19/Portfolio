#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

#include "restaurant.h"
#include "menu.h"


/****************************************************
 ** Function: Restaurant
 ** Description: default constructor
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: sets default values to variables
 ****************************************************/
Restaurant::Restaurant() {
    this->menu;
    this->employees = NULL;
    this->week = NULL;
    this->name = "";
    this->phone = "";
    this->address = "";
    this->num_employees = 0;
    this->num_days_open = 0;
}


/************************************************
 ** Function: Restaurant
 ** Description: Non-default constructor
 ** Parameters: const Restaurant &old_obj
 ** Pre-Conditions: old_obj is an object
 ** Post-Conditions: creates a ccopy of an object
 ************************************************/
Restaurant::Restaurant(const Restaurant &old_obj) {
	this->menu = old_obj.menu;
    this->employees = old_obj.employees;
    this->week = old_obj.week;
    this->name = old_obj.name;
    this->phone = old_obj.phone;
    this->address = old_obj.address;
    this->num_employees = old_obj.num_employees;
    this->num_days_open = old_obj.num_days_open;
	
	this->employees = new employee [this->num_employees];
	for (int i = 0; i < this->num_employees; i++) {
		this->employees[i] = old_obj.employees[i];
    }

    this->week = new hours [this->num_days_open];
	for (int i = 0; i < this->num_days_open; i++) {
		this->week[i] = old_obj.week[i];
    }
}


/***************************************************
 ** Function: Restaurant
 ** Description: AOO for restaurant class
 ** Parameters: const Restaurant &old_obj
 ** Pre-Conditions: old_obj is an object
 ** Post-Conditions: sets an object equal to another
 ***************************************************/
Restaurant &Restaurant::operator=(const Restaurant &old_obj) {
	if (this != &old_obj) {
		this->employees = old_obj.employees;
		
		if (this->employees != NULL) {
			delete [] this->employees;
        }
		this->employees = new employee [this->num_employees];
		for (int i = 0; i < this->num_employees; i++) {
			this->employees[i] = old_obj.employees[i];
        }

        if (this->week != NULL) {
			delete [] this->week;
        }
		this->week = new hours [this->num_days_open];
		for (int i = 0; i < this->num_days_open; i++) {
			this->week[i] = old_obj.week[i];
        }
	}
	return *this;
}


/****************************************************
 ** Function: Restaurant
 ** Description: Destructor
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: deletes object
 ****************************************************/
Restaurant::~Restaurant() {
	if (this->employees != NULL) {
		delete [] this->employees;
		this->employees = NULL;
	}

    if (this->week != NULL) {
		delete [] this->week;
		this->week = NULL;
	}
}


/**********************************************
 ** Function: setters
 ** Description: sets variables
 ** Parameters: employee, week, string, int
 ** Pre-Conditions: parameters are correct type
 ** Post-Conditions: sets varaibles
 **********************************************/
void Restaurant::set_employee(employee *employees) {
    this->employees = employees;
}

void Restaurant::set_hours(hours *week) {
    this->week = week;
}

void Restaurant::set_name(std::string name) {
    this->name = name;
}

void Restaurant::set_phone(std::string phone) {
    this->phone = phone;
}

void Restaurant::set_address(std::string address) {
    this->address = address;
}

void Restaurant::set_num_employees(int num) {
    this->num_employees = num;
}

void Restaurant::set_num_days_open(int num) {
    this->num_days_open = num;
}


/****************************************************
 ** Function: getters
 ** Description: returns variables
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: returns variables
 ****************************************************/
Menu Restaurant::get_menu() const {
    return this->menu;
}

employee *Restaurant::get_employee() const {
    return employees;
}

hours *Restaurant::get_hours() const {
    return week;
}

std::string Restaurant::get_name() const {
    return this->name;
}

std::string Restaurant::get_phone() const {
    return this->phone;
}

std::string Restaurant::get_address() const {
    return this->address;
}

int Restaurant::get_num_employees() const {
    return this->num_employees;
}

int Restaurant::get_num_days_open() const {
    return this->num_days_open;
}


/*************************************
 ** Function: load_data
 ** Description: loads data from files
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: sets varaibles
 *************************************/
void Restaurant::load_data() {
    std::ifstream fin;
    fin.open("restaurant_info.txt");
    if(!fin.is_open()) {
        std::cout << "Error opening file to read." << std::endl;
        return;
    }
    std::string name, phone, address;
    int num_days_open;
    std::getline(fin, name);
    std::getline(fin, phone);
    std::getline(fin, address);
    fin >> num_days_open;
    Restaurant::set_name(name);
    Restaurant::set_phone(phone);
    Restaurant::set_address(address);
    Restaurant::set_num_days_open(num_days_open);
    week = new hours[this->num_days_open];
    for(int i = 0; i < this->num_days_open; i++) {
        fin >> week[i].day >> week[i].open_hour >> week[i].close_hour;  
    }
    fin.clear();
    fin.close();

    fin.open("employee.txt");
    if(!fin.is_open()) {
        std::cout << "Error opening file to read." << std::endl;
        return;
    }
    int num_employees;
    fin >> num_employees;
    Restaurant::set_num_employees(num_employees);
    employees = new employee[this->num_employees];
    for(int i = 0; i < this->num_employees; i++) {
        fin >> employees[i].id >> employees[i].password >> employees[i].first_name >> employees[i].last_name;   
    }
    fin.clear();
    fin.close();

    menu.load_data(fin);
}


/****************************************************
 ** Function: login
 ** Description: login for employees
 ** Parameters: string
 ** Pre-Conditions: both id and password are strings
 ** Post-Conditions: returns true if it's an employee
 ****************************************************/
bool Restaurant::login(std::string id, std::string password) {
    int a = atoi(id.c_str());
    for(int i = 0; i < num_employees; i++) {
        if(employees[i].id == a && employees[i].password == password) {
            return true;
        }
    }
    return false;
}


/*****************************************
 ** Function: view_menu
 ** Description: prints the menu
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: prints menu to screen
 *****************************************/
void Restaurant::view_menu() {
    for(int i = 0; i < menu.get_num_pizzas(); i++) {
        std::cout << i + 1 << ". " << menu.get_pizzas()[i].get_name() << " " << menu.get_pizzas()[i].get_small_cost() << " "
                  << menu.get_pizzas()[i].get_medium_cost() << " " << menu.get_pizzas()[i].get_large_cost() << " "
                  << menu.get_pizzas()[i].get_num_ingredients() << " ";
        for(int j = 0; j < menu.get_pizzas()[i].get_num_ingredients(); j++) {
                std::cout << menu.get_pizzas()[i].get_ingredients()[j] << " ";
        }
        std::cout << std::endl;
    }
}


/******************************************
 ** Function: view_hours
 ** Description: prints the hours
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: prints hours to screen
 ******************************************/
void Restaurant::view_hours() {
    for(int i = 0; i < Restaurant::get_num_days_open(); i++) {
        std::cout << week[i].day << " " << week[i].open_hour << " " << week[i].close_hour << std::endl;
    }
}


/************************************************
 ** Function: view_address
 ** Description: prints address to the screen
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: prints address to the screen
 ************************************************/
void Restaurant::view_address() {
    std::cout << "\nAddress: " << this->address << std::endl;

}


/******************************************
 ** Function: view_phone
 ** Description: prints phone to screen
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: prints phone to screen
 ******************************************/
void Restaurant::view_phone() {
    std::cout << "\nPhone: " << this->phone << std::endl;

}


/***********************************
 ** Function: search_menu_by_price
 ** Description: search by price
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: search by price
 ***********************************/
void Restaurant::search_menu_by_price() {
    int a;
    std::cout << "\nEnter you upper limit: ";
    std::cin >> a;
    Menu m = menu.search_pizza_by_cost(a);
}


/************************************************
 ** Function: search_by_ingredients
 ** Description: searchs based on ingredients
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: searchs based on ingredients
 ************************************************/
void Restaurant::search_by_ingredients() {
    std::string s;
    std::cout << "\nWould you like to search for ingredients you want include (I) or exclude (E)? ";
    std::cin.ignore();
    std::getline(std::cin, s);
    if(s == "I" || s == "i") {
        int num = 1;
        std::string ingredient;
        std::cout << "\nWhat item would you like to include? ";
        std::getline(std::cin, ingredient);
        std::string *ingredients_to_include = new std::string[num];
        for(int i = 0; i < num; i++) {
            ingredients_to_include[i] = ingredient;
        }
        std::cin.ignore();
        while(true) {
            std::string choice;
            std::cout << "Do you want to include another item (Yes/No)? ";
            std::cin.ignore();
            std::getline(std::cin, choice);
            std::getline(std::cin, choice);
            if(choice == "Yes") {
                std::string *temp = new std::string[num + 1];
                std::string new_ingredient;
                std::cout << "\nWhat item would you like to include? ";
                std::cin.ignore();
                std::getline(std::cin, new_ingredient);
                for(int i = 0; i < num; i++) {
                    temp[i] = ingredients_to_include[i];
                }
                temp[num] = new_ingredient;
                num++;
                delete []ingredients_to_include;
                std::string *ingredients_to_include = new std::string[num];
                for(int i = 0; i < num; i++) {
                    ingredients_to_include[i] = temp[i];
                }
                delete[] temp;
            } else if(choice == "No") {
                break;
            }
        }
        Menu m = menu.search_pizza_by_ingredients_to_include(ingredients_to_include, num);
        std::cout << "\nHere are the pizzas that match your criteria:\n";
        m.view_menu();
    }
}


/**************************************************
 ** Function: place_order
 ** Description: writes an oder to text file
 ** Parameters: Pizza, int, int, string
 ** Pre-Conditions: all parameters are correct type
 ** Post-Conditions: prints to text file
 **************************************************/
void Restaurant::place_order(Pizza *selection, int selection_size, int *num_ordered, std::string *string) {
    std::ofstream fout;
    std::ifstream fin;
    std::string name, cc, phone, line;
    int count = 0;
    fin.open("orders.txt");
    if(!fin.is_open()) {
        std::cout << "Error opening file to read." << std::endl;
        return;
    } else if(fin.is_open()) {
        while (std::getline(fin, line)) {
        count++;
        }
    }
    fin.clear();
    fin.close();

    std::cout << "\nEnter your name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "\nEnter your credit card number: ";
    std::cin.ignore();
    std::getline(std::cin, cc);
    std::cout << "\nEnter your phone number: ";
    std::cin.ignore();
    std::getline(std::cin, phone);

    fout.open("orders.txt", std::ios::out | std::ios::app);
    if(!fout.is_open()) {
        std::cout << "Error opening file to read." << std::endl;
        return;
    } else if(fout.is_open()) {
        fout << "\n" << (count) << " " << name << " " << cc << " " << phone << " ";
        for(int i = 0; i < selection_size; i++) {
            fout << selection[i].get_name() << " " << string[i] << " " << num_ordered[i] << " ";
        }
    }
    fout.clear();
    fout.close();
}


/**********************************************
 ** Function: change_hours
 ** Description: changes hours
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: changes vales in text file
 **********************************************/
void Restaurant::change_hours() {
    std::ofstream fout;
    std::string s, to, tc;
    std::cout << "\nWhich day would you like to change the hours for? ";
    std::cin.ignore();
    std::getline(std::cin, s);
    std::cout << "What should the opening time be? ";
    std::getline(std::cin, to);
    std::cout << "What should be the closing time be? ";
    std::getline(std::cin, tc);
    for(int i = 0; i < Restaurant::get_num_days_open(); i++) {
        if(Restaurant::get_hours()[i].day == s) {
            Restaurant::get_hours()[i].open_hour = to;
            Restaurant::get_hours()[i].close_hour = tc;
        }
    }
    //change text file to match new hours
    fout.open("restaurant_info.txt");
    if(!fout.is_open()) {
        std::cout << "Error opening file to read." << std::endl;
        return;
    } else if(fout.is_open()) {
        fout << Restaurant::get_name() << "\n";
        fout << Restaurant::get_phone() << "\n";
        fout << Restaurant::get_address() << "\n";
        fout << Restaurant::get_num_days_open() << "\n";
        for(int i = 0; i < Restaurant::get_num_days_open(); i++) {
            fout << Restaurant::get_hours()[i].day << " " <<
                    Restaurant::get_hours()[i].open_hour << " " <<
                    Restaurant::get_hours()[i].close_hour << "\n";
        }
    }
    fout.clear();
    fout.close();
    std::cout << "\nUpdated hours" << std::endl;
    Restaurant::view_hours();
}


/***************************************
 ** Function: add_to_menu
 ** Description: adds an object to menu
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: adds object to menu
 ***************************************/
void Restaurant::add_to_menu() {
    std::string name, ingredient;
    int small, medium, large, num;
    std::cout <<"\nEnter a name(use _ for spaces): ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Enter small cost: ";
    std::cin >> small;
    std::cout << "Enter medium cost: ";
    std::cin >> medium;
    std::cout << "Enter large cost: ";
    std::cin >> large;
    std::cout << "Enter number of ingredients: ";
    std::cin >> num;
    std::cin.ignore();
    std::string *ingredients = new std::string[num];
    for(int i = 0; i < num; i++) {
        std::cout << "Enter an ingredient: ";
        std::getline(std::cin, ingredients[i]);
    }
    Pizza p(name, small, medium, large, num, ingredients);
    menu.add_to_menu(p);
    std::cout << "\nUpdated menu" << std::endl;
    Restaurant::view_menu();
}


/***************************************************
 ** Function: remove_from_menu
 ** Description: removes an object from menu
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: removes an object from the menu
 ***************************************************/
void Restaurant::remove_from_menu() {
    Restaurant::view_menu();
    std::cout << "\nWhich pizza would you like to remove(number): ";
    int n;
    std::cin >> n;
    menu.remove_from_menu(n);
    std::cout << "\nUpdated menu" << std::endl;
    Restaurant::view_menu();
}


/*******************************************
 ** Function: view_orders
 ** Description: prints orders to screen
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: prints orders to screen
 *******************************************/
void Restaurant::view_orders() {
    std::ifstream fin;
    int num_orders;
    std::string order = "";
    fin.open("orders.txt");
    if(!fin.is_open()) {
        std::cout << "Error opening file to read." << std::endl;
        return;
    }
    fin >> num_orders;
    while(!fin.eof()) {
        std::getline(fin, order);
        std::cout << " " << order << "\n";
    }
}


/***************************************************
 ** Function: remove_orders
 ** Description: remmoves an order
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: removes an order from text file
 ***************************************************/
void Restaurant::remove_orders() {
    Restaurant::view_orders();
    std::cout << "\nWhich order number would you like to remove: ";
    int n;
    std::cin >> n;
    n++;

    std::ifstream fin("orders.txt"); 
    std::ofstream fout; 
    fout.open("temp.txt", std::ofstream::out); 
  
    char c; 
    int line_no = 1; 
    while (fin.get(c)) { 
        if (c == '\n') 
        line_no++; 
  
        if (line_no != n) 
            fout << c; 
    } 

    fout.close(); 
    fin.close(); 
    remove("orders.txt"); 
    rename("temp.txt", "orders.txt");

    std::cout << "Updated orders\n" << std::endl;
    Restaurant::view_orders();
}


/************************************
 ** Function: run
 ** Description: runs the program
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: runs the program
 ************************************/
void Restaurant::run() {
    std::cout << "\nWelcome to Bytes Pizza!" << std::endl;
    std::cout << "Are you a customer (C) or employee (E) or would you like to quit (Q)? ";
    std::string c;
    while(true) {
        std::getline(std::cin, c);
        std::cout << c << std::endl;
        if((c != "C" && c != "c") && (c != "E" && c != "e") && (c != "Q" && c != "q")) {
            std::cout << "Invalid choice, try again" << std::endl;
        } else {
            break;
        }
    }

    if(c == "E" || c == "e") {
        std::string id;
        std::string password;
        while(true) {
            std::cout << "Please enter your ID number: ";
            std::getline(std::cin, id);
            std::cout << "Please enter your password: ";
            std::getline(std::cin, password);
            if(Restaurant::login(id, password)) {
                break;
            } else {
                std::cout << "Incorrect ID or password" << std::endl;
            }
        }

        for(int i = 0; i < Restaurant::get_num_employees(); i++) {
            if(Restaurant::get_employee()[i].id == atoi(id.c_str()) && Restaurant::get_employee()[i].password == password) {
                std::cout << "Welcome " << Restaurant::get_employee()[i].first_name << " " << Restaurant::get_employee()[i].last_name << std::endl;
            }
        }

        while(true) {
            std::cout << "\nWhat would you like to do?\n" << "1. Change Hours\n" << "2. View Orders\n";
            std::cout << "3. Remove Order\n" << "4. Add Item To Menu\n" << "5. Remove Item From Menu\n";
            std::cout << "6. View Menu\n" << "7. View Hours\n" << "8. View Address\n";
            std::cout << "9. View Phone\n" << "10. Log Out\n" << "Selection: ";

            int selection = 0;
            std::cin >> selection;

            if(selection == 1) {
                Restaurant::change_hours();
            } else if(selection == 2) {
                Restaurant::view_orders();
            } else if(selection == 3) {
                Restaurant::remove_orders();
            } else if(selection == 4) {
                Restaurant::add_to_menu();
            } else if(selection == 5) {
                Restaurant::remove_from_menu();
            } else if(selection == 6) {
                std::cout << "Menu options" << std::endl;
                Restaurant::view_menu();
            } else if(selection == 7) {
                std::cout << "\nDays open" << std::endl;
                Restaurant::view_hours();
            } else if(selection == 8) {
                Restaurant::view_address();
            } else if(selection == 9) {
                Restaurant::view_phone();
            } else if(selection == 10) {
                break;
            }
        }
        Restaurant::run();
    } else if(c == "C" || c == "c") {
        while(true) {
            std::cout << "\nWhat would you like to do?\n" << "1. View Menu\n" << "2. Search by Cost\n";
            std::cout << "3. Search by Ingredients\n" << "4. Place Order\n" << "5. View Hours\n";
            std::cout << "6. View Address\n" << "7. View Phone\n" << "8. Log Out\n" << "Selection: ";

            int selection = 0;
            std::cin >> selection;

            if(selection == 1) {
                std::cout << "\nMenu options" << std::endl;
                Restaurant::view_menu();
            } else if(selection == 2) {
                Restaurant::search_menu_by_price();
            } else if(selection == 3) {
                Restaurant::search_by_ingredients();
            } else if(selection == 4) {
                int a, b, d;
                std::string s;
                std::cout << "How many pizzas would you like to order? ";
                std::cin >> a;
                Restaurant::view_menu();
                Pizza *p = new Pizza[a];
                int *num = new int[a];
                std::string *string = new std::string[a];
                for(int i = 0; i < a; i++) {
                    std::cout << "\nSelect a pizza(number): ";
                    std::cin >> b;
                    std::cout << "\nSelect a size(S,M,L): ";
                    std::cin.ignore();
                    std::getline(std::cin, s);
                    std::cout << "\nHow many of this size: ";
                    std::cin >> d;
                    p[i] = menu.get_pizzas()[b - 1];
                    string[i] = s;
                    num[i] = d;
                }
                Restaurant::place_order(p, a, num, string);
                delete[] p;
                delete[] num;
                delete[] string;
            } else if(selection == 5) {
                std::cout << "\nDays open" << std::endl;
                Restaurant::view_hours();
            } else if(selection == 6) {
                Restaurant::view_address();
            } else if(selection == 7) {
                Restaurant::view_phone();
            } else if(selection == 8) {
                break;
            }
        }
        Restaurant::run();
    } else if(c == "Q" || c == "q") {
        return;
    }
}