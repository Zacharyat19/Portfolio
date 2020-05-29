#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Zoo.h"

/*************************************
 ** Function: Zoo
 ** Description: Default constructor
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Creates an object
 *************************************/
Zoo::Zoo() {
    this->bank = 50000;
    this->month = 0;
    this->num_monkeys = 0;
    this->num_sea_otters = 0;
    this->num_sloths = 0;
    this->num_snakes = 0;
    this->monkeys = NULL;
    this->sea_otters = NULL;
    this->sloths = NULL;
}


/***********************************************
 ** Function: Zoo
 ** Description: Copy constructor
 ** Parameters: const Zoo &old_obj
 ** Pre-Conditions: Old_obj is type Zoo
 ** Post-Conditions: Creates a copy of an object
 ***********************************************/
Zoo::Zoo(const Zoo &old_obj) {
    this->bank = old_obj.bank;
    this->month = old_obj.month;
    this->num_monkeys = old_obj.num_monkeys;
    this->num_sea_otters = old_obj.num_sea_otters;
    this->num_sloths = old_obj.num_sloths;
    this->num_snakes = old_obj.num_snakes;
    this->monkeys = old_obj.monkeys;
    this->sea_otters = old_obj.sea_otters;
    this->sloths = old_obj.sloths;

    this->monkeys = new Monkey [this->num_monkeys];
	for (int i = 0; i < this->num_monkeys; i++) {
		this->monkeys[i] = old_obj.monkeys[i];
    }

    this->sea_otters = new Sea_otter [this->num_sea_otters];
	for (int i = 0; i < this->num_sea_otters; i++) {
		this->sea_otters[i] = old_obj.sea_otters[i];
    }

    this->sloths = new Sloth [this->num_sloths];
	for (int i = 0; i < this->num_sloths; i++) {
		this->sloths[i] = old_obj.sloths[i];
    }
}


/*************************************************
 ** Function: Zoo
 ** Description: AOO
 ** Parameters: const Zoo &old_obj
 ** Pre-Conditions: Old_obj is type Zoo
 ** Post-Conditions: Assigns one object to another
 *************************************************/
Zoo &Zoo::operator=(const Zoo &old_obj) {
    if (this != &old_obj){
		this->monkeys = old_obj.monkeys;
		
		if (this->monkeys != NULL) {
			delete [] this->monkeys;
        }
		this->monkeys = new Monkey [this->num_monkeys];
		for (int i = 0; i < this->num_monkeys; i++) {
			this->monkeys[i] = old_obj.monkeys[i];
        }

        if (this->sea_otters != NULL) {
			delete [] this->sea_otters;
        }
		this->sea_otters = new Sea_otter [this->num_sea_otters];
	    for (int i = 0; i < this->num_sea_otters; i++) {
		    this->sea_otters[i] = old_obj.sea_otters[i];
        }

        if (this->sloths != NULL) {
			delete [] this->sloths;
        }
		this->sloths = new Sloth [this->num_sloths];
	    for (int i = 0; i < this->num_sloths; i++) {
		    this->sloths[i] = old_obj.sloths[i];
        }
	}
    return *this;
}


/**************************************
 ** Function: Zoo
 ** Description: Destructor
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Deletes the object
 **************************************/
Zoo::~Zoo() {
    if (this->monkeys != NULL) {
		delete [] this->monkeys;
		this->monkeys = NULL;
	}
    if (this->sea_otters != NULL) {
		delete [] this->sea_otters;
		this->sea_otters = NULL;
	}
    if (this->sloths != NULL) {
		delete [] this->sloths;
		this->sloths = NULL;
	}
}


/****************************************************
 ** Function: Setters
 ** Description: Set value of private variables
 ** Parameters: Int
 ** Pre-Conditions: All parameters are o type int
 ** Post-Conditions: Sets values to private variables
 ****************************************************/
void Zoo::set_bank(int bank) {
    this->bank = bank;
}

void Zoo::set_month(int month) {
    this->month = month;
}

void Zoo::set_num_monkeys(int num_monkeys) {
    this->num_monkeys = num_monkeys;
}

void Zoo::set_num_sea_otters(int num_sea_otters) {
    this->num_sea_otters = num_sea_otters;
}

void Zoo::set_num_sloths(int num_sloths) {
    this->num_sloths = num_sloths;
}


void Zoo::set_monkeys(Monkey *monkeys) {
    this->monkeys = monkeys;
}

void Zoo::set_sea_otter(Sea_otter *otters) {
    this->sea_otters = otters;
}

void Zoo::set_sloths(Sloth *sloths) {
    this->sloths = sloths;
}


/****************************************
 ** Function: Getters
 ** Description: Return pivate variables
 ** Parameters: None
 ** Pre-Conditions: Object is initialized
 ** Post-Conditions: Returns variable
 ****************************************/
int Zoo::get_bank() const {
    return this->bank;
}

int Zoo::get_month() const {
    return this->month;
}

int Zoo::get_num_monkeys() const {
    return this->num_monkeys;
}

int Zoo::get_num_sea_otters() const {
    return this->num_sea_otters;
}

int Zoo::get_num_sloths() const {
    return this->num_sloths;
}

Monkey *Zoo::get_monkeys() const {
    return monkeys;
}

Sea_otter *Zoo::get_sea_otter() const {
    return sea_otters;
}

Sloth *Zoo::get_sloths() const {
    return sloths;
}


/*******************************************************
 ** Function: Add_monkey
 ** Description: Adds a monkey object to monkey array
 ** Parameters: Monkey_to_add
 ** Pre-Conditions: Monkey_to_add is of type Monkey
 ** Post-Conditions: Monkey_to_add is added to the array
 *******************************************************/
void Zoo::add_monkey(Monkey monkey_to_add) {
    if(this->monkeys == NULL) {
       Monkey *monkey_temp = new Monkey[1]; 
       monkey_temp[0] = monkey_to_add;
       Zoo::set_monkeys(monkey_temp);
       Zoo::set_num_monkeys(1);
       return;
    }
    Monkey *monkey_temp = new Monkey[this->num_monkeys + 1];
    for(int i = 0; i < this->num_monkeys; i++) {
        monkey_temp[i] = this->monkeys[i];
    }
    monkey_temp[this->num_monkeys] = monkey_to_add;
    if(this->monkeys != NULL) {
        delete []this->monkeys;
    }
    this->monkeys = monkey_temp;
    this->num_monkeys++;
}


/*********************************************************
 ** Function: Remove_monkey
 ** Description: Removes a monkey object from monkey array
 ** Parameters: Index_to_remove
 ** Pre-Conditions: Index_to_remove is of type int
 ** Post-Conditions: A monkey is removed
 *********************************************************/
void Zoo::remove_monkey(int index_to_remove) {
    int idx = index_to_remove - 1;

    if(idx < 0 || idx > this->num_monkeys) {
        std::cout << "Monkey not found" << std::endl;
        return;
    }
    for(int i = idx; i < this->num_monkeys - 1; i++) {
        this->monkeys[i] = this->monkeys[i + 1];
    }
    this->num_monkeys--;
}


/**********************************************************
 ** Function: Add_sea_otter
 ** Description: Adds a sea_otter object to sea_otter array
 ** Parameters: Sea_otter_to_add
 ** Pre-Conditions: Sea_otter_to_add is of type Sea_otter
 ** Post-Conditions: Sea_otter_to_add is added to the array
 **********************************************************/
void Zoo::add_sea_otter(Sea_otter otter_to_add) {
    if(this->sea_otters == NULL) {
       Sea_otter *otter_temp = new Sea_otter[1]; 
       otter_temp[0] = otter_to_add;
       Zoo::set_sea_otter(otter_temp);
       Zoo::set_num_sea_otters(1);
       return;
    }
   Sea_otter *otter_temp =  new Sea_otter[this->num_sea_otters + 1];
    for(int i = 0; i < this->num_sea_otters; i++) {
        otter_temp[i] = this->sea_otters[i];
    }
    otter_temp[this->num_sea_otters] = otter_to_add;
    if(this->sea_otters != NULL) {
        delete []this->sea_otters;
    }
    this->sea_otters = otter_temp;
    this->num_sea_otters++;
}


/*************************************************************
 ** Function: Remove_sea_otter
 ** Description: Removes a sea_otter object to sea_otter array
 ** Parameters: Index_to_remove
 ** Pre-Conditions: Index_to_remove is of type int
 ** Post-Conditions: A sea_otter is removed
 *************************************************************/
void Zoo::remove_sea_otter(int index_to_remove) {
    int idx = index_to_remove - 1;

    if(idx < 0 || idx > this->num_sea_otters) {
        std::cout << "Sea_otter not found" << std::endl;
        return;
    }
    for(int i = idx; i < this->num_sea_otters - 1; i++) {
        this->sea_otters[i] = this->sea_otters[i + 1];
    }
    this->num_sea_otters--;
}


/******************************************************
 ** Function: Add_sloth
 ** Description: Adds a sloth object to sloth array
 ** Parameters: Sloth_to_add
 ** Pre-Conditions: Sloth_to_add is of type Sloth
 ** Post-Conditions: Sloth_to_add is added to the array
 ******************************************************/
void Zoo::add_sloth(Sloth sloth_to_add) {
    if(this->sloths == NULL) {
      Sloth *sloth_temp = new Sloth[1]; 
       sloth_temp[0] = sloth_to_add;
       Zoo::set_sloths(sloth_temp);
       Zoo::set_num_sloths(1);
       return;
    }
    Sloth *sloth_temp = new Sloth[this->num_sloths + 1];
    for(int i = 0; i < this->num_sloths; i++) {
        sloth_temp[i] = this->sloths[i];
    }
    sloth_temp[this->num_sloths] = sloth_to_add;
    if(this->sloths != NULL) {
        delete []this->sloths;
    }
    this->sloths = sloth_temp;
    this->num_sloths++;
}


/*****************************************************
 ** Function: Remove_sloth
 ** Description: Removes a sloth object to sloth array
 ** Parameters: Index_to_remove
 ** Pre-Conditions: Index_to_remove is of type int
 ** Post-Conditions: A sloth is removed
 *****************************************************/
void Zoo::remove_sloth(int index_to_remove) {
    int idx = index_to_remove - 1;

    if(idx < 0 || idx > this->num_sloths) {
        std::cout << "Sloth not found" << std::endl;
        return;
    }
    for(int i = idx; i < this->num_sloths - 1; i++) {
        this->monkeys[i] = this->monkeys[i + 1];
    }
    this->num_sloths--;
}


/****************************************************
 ** Function: Buy_monkey
 ** Description: Adds one or two monkeys to the array
 ** Parameters: N
 ** Pre-Conditions: N is of type int
 ** Post-Conditions: Monkey is added to the array
 ****************************************************/
void Zoo::buy_monkey(int n) {
    if(n == 1) {
        Monkey m(24, 15000, 1, 100, 1500);
        Zoo::add_monkey(m);
        Zoo::display_monkeys();
        this->bank -= 15000;
    } else if(n == 2) {
        Monkey m(24, 15000, 1, 100, 1500);
        Monkey m2(24, 15000, 1, 100, 1500);
        Zoo::add_monkey(m);
        Zoo::add_monkey(m2);
        this->bank -= 30000;
    } else {
        std::cout << "Invalid entry" << std::endl;
    }
}


/*******************************************************
 ** Function: Buy_sea_otter
 ** Description: Adds one or two sea_otters to the array
 ** Parameters: N
 ** Pre-Conditions: N is of type int
 ** Post-Conditions: Sea_otter is added to the array
 *******************************************************/
void Zoo::buy_sea_otter(int n) {
    if(n == 1) {
        Sea_otter s(24, 5000, 2, 100, 250);
        Zoo::add_sea_otter(s);
        this->bank -= 5000;
    } else if(n == 2) {
        Sea_otter s(24, 5000, 2, 100, 250);
        Sea_otter s2(24, 5000, 2, 100, 250);
        Zoo::add_sea_otter(s);
        Zoo::add_sea_otter(s2);
        this->bank -= 10000;
    } else {
        std::cout << "Invalid entry" << std::endl;
    }
}


/***************************************************
 ** Function: Buy_sloth
 ** Description: Adds one or two sloths to the array
 ** Parameters: N
 ** Pre-Conditions: N is of type int
 ** Post-Conditions: Sloth is added to the array
 ***************************************************/
void Zoo::buy_sloth(int n) {
    if(n == 1) {
        Sloth s(24, 2000, 5, 100, 100);
        Zoo::add_sloth(s);
        this->bank -= 2000;
    } else if(n == 2) {
        Sloth s(24, 2000, 5, 100, 100);
        Sloth s2(24, 2000, 5, 100, 100);
        Zoo::add_sloth(s);
        Zoo::add_sloth(s2);
        this->bank -= 4000;
    } else {
        std::cout << "Invalid entry" << std::endl;
    }
}


/****************************************************
 ** Function: increase_age
 ** Description: Increases the age of all the animals
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: All ages increase by one
 ****************************************************/
void Zoo::increase_age() {
    for(int i = 0; i < this->num_monkeys; i++) {
        int x = this->monkeys[i].get_age();
        this->monkeys[i].set_age(x + 1);
    }

    for(int i = 0; i < this->num_sea_otters; i++) {
        int x = this->sea_otters[i].get_age();
        this->sea_otters[i].set_age(x + 1);
    }

    for(int i = 0; i < this->num_sloths; i++) {
        int x = this->sloths[i].get_age();
        this->sloths[i].set_age(x + 1);
    }
}


/******************************************
 ** Function: Zoo
 ** Description: Overloads the ++ operator
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Increases month by one
 ******************************************/
Zoo& Zoo::operator++() {
    ++this->month;
    return *this;
}


/*************************************************
 ** Function: Event
 ** Description: Generates a random event to occur
 ** Parameters: None
 ** Pre-Conditions: Months is greater than 0
 ** Post-Conditions: The proper event is executed
 *************************************************/
void Zoo::event() {
    srand((unsigned) time(0));
    int event = (rand() % 4) + 1;

    if(event == 1) {
        int a = (rand() % 3) + 1;
        if(a == 1) {
            if(this->num_monkeys == 0) {
                std::cout << "No event this month" << std::endl;
            } else {
                Zoo::sick_monkey();
            }
        } else if(a == 2) {
            if(this->num_sea_otters == 0) {
                std::cout << "No event this month" << std::endl;
            } else {
                Zoo::sick_sea_otter();
            }
        } else if(a == 3) {
            if(this->num_sloths == 0) {
                std::cout << "No event this month" << std::endl;
            } else {
                Zoo::sick_sloth();
            }
        }
    } else if(event == 2) {
        int b = (rand() % 3) + 1;
        if(b == 1) {
            if(this->num_monkeys == 0) {
                std::cout << "No event this month" << std::endl;
            } else {
                Zoo::monkey_babies();
            }
        } else if(b == 2) {
            if(this->num_sea_otters == 0) {
                std::cout << "No event this month" << std::endl;
            } else {
                Zoo::sea_otter_babies();
            }
        } else if(b == 3) {
            if(this->num_sloths == 0) {
                std::cout << "No event this month" << std::endl;
            } else {
                Zoo::sloth_babies();
            }
        }
    } else if(event == 3) {
        if(this->num_monkeys == 0) {
                std::cout << "No event this month" << std::endl;
            } else {
                Zoo::extra_revenue();
            }
    } else if(event == 4) {
        std::cout << "No event this month" << std::endl;
        return;
    }
}


/**********************************************************************
 ** Function: Sick_monkey
 ** Description: Removes a monkey if the user doesn't have enough money
 ** Parameters: None
 ** Pre-Conditions: Their is a monkey in the array
 ** Post-Conditions: Monkey is either removed or money is removed
 **********************************************************************/
void Zoo::sick_monkey() {
    if(this->monkeys == NULL) {
        return;
    }
    std::cout << "Oh no, one of the monkeys is sick" << std::endl;
    srand((unsigned) time(0));
    int y = (rand() % this->num_monkeys) + 0;
    if(this->monkeys[y].get_age() < 6) {
        if((this->bank -= 15000) > 0) {
            std::cout << "You have enough to save the monkey!" << std::endl;
            this->bank -= 15000;
        } else {
            std::cout << "You don't have enough money, the monkey died" << std::endl;
            Zoo::remove_monkey(y);
        }
    } else if(this->monkeys[y].get_age() >= 6) {
        if((this->bank -= 7500) > 0) {
            std::cout << "You have enough to save the monkey!" << std::endl;
            this->bank -= 7500;
        } else {
            std::cout << "You don't have enough money, the monkey died" << std::endl;
            Zoo::remove_monkey(y);
        }
    }
}


/*************************************************************************
 ** Function: Sick_sea_otter
 ** Description: Removes a sea_otter if the user doesn't have enough money
 ** Parameters: None
 ** Pre-Conditions: Their is a sea_otter in the array
 ** Post-Conditions: Sea_otter is either removed or money is removed
 *************************************************************************/
void Zoo::sick_sea_otter() {
    std::cout << "Oh no, one of the sea otters is sick" << std::endl;
    srand((unsigned) time(0));
    int y = (rand() % this->num_sea_otters) + 0;
    if(this->sea_otters[y].get_age() < 6) {
        if((this->bank -= 5000) > 0) {
            std::cout << "You have enough to save the sea otter!" << std::endl;
            this->bank -= 5000;
        } else {
            std::cout << "You don't have enough money, the sea otter died" << std::endl;
            Zoo::remove_sea_otter(y);
        }
    } else if(this->sea_otters[y].get_age() >= 6) {
        if((this->bank -= 2500) > 0) {
            std::cout << "You have enough to save the sea otter!" << std::endl;
            this->bank -= 2500;
        } else {
            std::cout << "You don't have enough money, the sea otter died" << std::endl;
            Zoo::remove_sea_otter(y);
        }
    }
}


/*********************************************************************
 ** Function: Sick_sloth
 ** Description: Removes a sloth if the user doesn't have enough money
 ** Parameters: None
 ** Pre-Conditions: Their is a sloth in the array
 ** Post-Conditions: Sloth is either removed or money is removed
 *********************************************************************/
void Zoo::sick_sloth() {
    std::cout << "Oh no, one of the sloths is sick" << std::endl;
    srand((unsigned) time(0));
    int y = (rand() % this->num_sloths) + 0;
    if(this->sloths[y].get_age() < 6) {
        if((this->bank -= 2000) > 0) {
            std::cout << "You have enough to save the sloth!" << std::endl;
            this->bank -= 2000;
        } else {
            std::cout << "You don't have enough money, the sloth died" << std::endl;
            Zoo::remove_sea_otter(y);
        }
    } else if(this->sloths[y].get_age() >= 6) {
        if((this->bank -= 1000) > 0) {
            std::cout << "You have enough to save the sloth!" << std::endl;
            this->bank -= 1000;
        } else {
            std::cout << "You don't have enough money, the sloth died" << std::endl;
            Zoo::remove_sloth(y);
        }
    }
}


/************************************************
 ** Function: Monkey_babies
 ** Description: Adds one monkey to the array
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Monkey is added to the array
 ************************************************/
void Zoo::monkey_babies() {
    if(this->monkeys != NULL) {
        while(true) {
            srand((unsigned) time(0));
            int index = (rand() % this->num_monkeys) + 0;
            if(this->monkeys[index].get_age() >= 24) {
                Monkey m(0, 15000, 1, 100, 1500);
                Zoo::add_monkey(m);
                break;
            }
        }
        std::cout << "One of the monkeys had a baby!" << std::endl;
    }
}


/***************************************************
 ** Function: Sea_otter_babies
 ** Description: Adds two sea_otters to the array
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Sea_otter is added to the array
 ***************************************************/
void Zoo::sea_otter_babies() {
    if(this->sea_otters != NULL) {
        while(true) {
            srand((unsigned) time(0));
            int index = (rand() % this->num_sea_otters) + 0;
            if(this->sea_otters[index].get_age() >= 24) {
                for(int i = 0; i < this->sloths[index].get_num_babies(); i++) {
                    Sea_otter s(0, 5000, 2, 100, 250);
                    Zoo::add_sea_otter(s);
                }
                break;
            }
        }
        std::cout << "One of the sea otters had babies!" << std::endl;
    }
}


/***********************************************
 ** Function: Sloth_babies
 ** Description: Adds five sloths to the array
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Sloth is added to the array
 ***********************************************/
void Zoo::sloth_babies() {
    if(this->sloths != NULL) {
        while(true) {
            srand((unsigned) time(0));
            int index = (rand() % this->num_sloths) + 0;
            if(this->sloths[index].get_age() >= 24) {
                for(int i = 0; i < this->sloths[index].get_num_babies(); i++) {
                    Sloth s(0, 2000, 5, 100, 100);
                    Zoo::add_sloth(s);
                }
                break;
            }
        }
        std::cout << "One of the sloths had babies!" << std::endl;
    }
}


/******************************************************
 ** Function: Extra_revenue
 ** Description: Adds extra revenue to the bank
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Extra revenue is added to the bank
 ******************************************************/
void Zoo::extra_revenue() {
    std::cout << "This month you get extra revenue!" << std::endl;
    for(int i = 0; i < this->num_monkeys; i++) {
        int y = (rand() % 700) + 300;
        this->bank += y;
    }
}


/***************************************************
 ** Function: Monkey_revenue
 ** Description: Adds monkey revenue to bank
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Monkey revenue is added to bank
 ***************************************************/
void Zoo::monkey_revenue() {
    if(this->monkeys == NULL) {
        return;
    } else {
        int revenue = 0;
        for(int i = 0; i < this->num_monkeys; i++) {
            if(this->monkeys[i].get_age() < 6) {
                revenue += (this->monkeys[i].get_revenue() * 2);
            } else if(this->monkeys[i].get_age() >= 6) {
                revenue += (this->monkeys[i].get_revenue());
            }
        }
        this->bank += revenue;
    }
}


/**********************************************************
 ** Function: Sea_otter_revenue
 ** Description: Adds sea_otter revenue to bank
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Sea_otter revenue is added to the bank
 **********************************************************/
void Zoo::sea_otter_revenue() {
    if(this->sea_otters == NULL) {
        return;
    } else {
        int revenue = 0;
        for(int i = 0; i < this->num_sea_otters; i++) {
            if(this->sea_otters[i].get_age() < 6) {
                revenue += (this->sea_otters[i].get_revenue() * 2);
            } else if(this->sea_otters[i].get_age() >= 6) {
                revenue += (this->sea_otters[i].get_revenue());
            }
        }
        this->bank += revenue;
    }
}


/************************************************
 ** Function: Monkey_babies
 ** Description: Adds one monkey to the array
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Monkey is added to the array
 ************************************************/
void Zoo::sloth_revenue() {
    if(this->sloths == NULL) {
        return;
    } else {
        int revenue = 0;
        for(int i = 0; i < this->num_sloths; i++) {
            if(this->sloths[i].get_age() < 6) {
                revenue += (this->sloths[i].get_revenue() * 2);
            } else if(this->sloths[i].get_age() >= 6) {
                revenue += (this->sloths[i].get_revenue());
            }
        }
        this->bank += revenue;
    }
}


/*****************************************
 ** Function: Display_monkeys
 ** Description: Displays monkeys
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Monkeys are displayed
 *****************************************/
void Zoo::display_monkeys() {
    if(this->monkeys == NULL) {
        std::cout << "You don't own any monkeys" << std::endl;
    } else {
        for(int i = 0; i < this->num_monkeys; i++) {
            std::cout << "Monkey " << i + 1 << ", age: " << this->monkeys[i].get_age() << ", price: " <<
                        this->monkeys[i].get_price() << ", revenue: " << this->monkeys[i].get_revenue() << std::endl;
        }
    }
}


/********************************************
 ** Function: Display_sea_otters
 ** Description: Displays sea_otters
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Sea_otters are displayed
 ********************************************/
void Zoo::display_sea_otters() {
    if(this->sea_otters == NULL) {
        std::cout << "You don't own any sea otters" << std::endl;
    } else {
        std::cout << "-----------------------------------------------" << std::endl;
        for(int i = 0; i < this->num_sea_otters ; i++) {
            std::cout << "Sea_otter " << i + 1 << ", age: " << this->sea_otters[i].get_age() << ", price: " <<
                        this->sea_otters[i].get_price() << ", revenue: " << this->sea_otters[i].get_revenue() << std::endl;
        }
    }
}


/****************************************
 ** Function: Display_sloth
 ** Description: Displays sloths
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Sloths are displayed
 ****************************************/
void Zoo::display_sloths() {
    if(this->sloths == NULL) {
        std::cout << "You don't own any sloths" << std::endl;
    } else {
        std::cout << "-----------------------------------------------" << std::endl;
        for(int i = 0; i < this->num_sloths ; i++) {
            std::cout << "Sloth " << i + 1 << ", age: " << this->sloths[i].get_age() << ", price: " <<
                        this->sloths[i].get_price() << ", revenue: " << this->sloths[i].get_revenue() << std::endl;
        }
    }
}


/**************************************************************
 ** Function: Sell_monkey
 ** Description: Removes a monkey from the array and adds money
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Monkey is removed
 **************************************************************/
void Zoo::sell_monkey() {
    Zoo::display_monkeys();
    std::cout << "Which monkey do you want to sell? ";
    int a;
    std::cin >> a;
    Zoo::remove_monkey(a);
    this->bank += 7500;
}


/*****************************************************************
 ** Function: Sell_sea_otter
 ** Description: Removes a sea_otter from the array and adds money
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Sea_otter is removed
 *****************************************************************/
void Zoo::sell_sea_otter() {
    Zoo::display_sea_otters();
    std::cout << "Which sea otter do you want to sell? ";
    int a;
    std::cin >> a;
    Zoo::remove_sea_otter(a);
    this->bank += 2500;
}


/*************************************************************
 ** Function: Sell_sloth
 ** Description: Removes a sloth from the array and adds money
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Sloth is removed
 *************************************************************/
void Zoo::sell_sloth() {
    Zoo::display_sloths();
    std::cout << "Which sloth do you want to sell? ";
    int a;
    std::cin >> a;
    Zoo::remove_sloth(a);
    this->bank +=1000;
}


/***************************************************************
 ** Function: Food
 ** Description: Calculates food cost
 ** Parameters: &a
 ** Pre-Conditions: All parameters are type int
 ** Post-Conditions: Food is calculated and subtracted from bank
 ***************************************************************/
void Zoo::food(int &a) {
    srand((unsigned) time(0));
    int food = 0;
    int change = (rand() % 125) + 75;
    if(this->month == 0) {
        Zoo::monkey_food(a, food);
        Zoo::sea_otter_food(a, food);
        Zoo::sloth_food(a, food);
        std::cout << "\nFood cost for the month: $" << food << std::endl;
        this->bank -= food;
    } else if(this->month > 0) {
        a = ((a * change) / 100);
        Zoo::monkey_food(a, food);
        Zoo::sea_otter_food(a, food);
        Zoo::sloth_food(a, food);
        std::cout << "\nFood cost for the month: $" << food << std::endl;
        this->bank -= food;
    }
}


/**********************************************
 ** Function: Monkey_food
 ** Description: Calculates monkey food
 ** Parameters: &b, &b
 ** Pre-Conditions: All parameters are type int
 ** Post-Conditions: Monkey_food is calculatee
 **********************************************/
void Zoo::monkey_food(int &a, int &b) {
    for(int i = 0; i < this->num_monkeys; i++) {
        b += (a * 4);
    }
}


/************************************************
 ** Function: Sea_otter_food
 ** Description: Calculates sea_otter food
 ** Parameters: &b, &b
 ** Pre-Conditions: All parameters are type int
 ** Post-Conditions: Sea_otter_food is calculatee
 ************************************************/
void Zoo::sea_otter_food(int &a, int &b) {
    for(int i = 0; i < this->num_sea_otters; i++) {
        b+= (a * 2);
    }
}


/**********************************************
 ** Function: Sloth_food
 ** Description: Calculates sloth food
 ** Parameters: &b, &b
 ** Pre-Conditions: All parameters are type int
 ** Post-Conditions: Sloth_food is calculatee
 **********************************************/
void Zoo::sloth_food(int &a, int &b) {
    for(int i = 0; i < this->num_sloths; i++) {
        b += (a);
    }
}


/*******************************************************
 ** Function: Buy_sell
 ** Description: Controls the flow of buying and selling
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Calls correct functions
 *******************************************************/
void Zoo::buy_sell() {
    int a, b, c;
    while(!(std::cin >> a)) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Incorrect entry. Try again: ";
    }
    if(a == 1) {
        std::cout << "How many monkeys do you want to buy?\n";
        std::cin >> b;
        Zoo::buy_monkey(b);
    } else if(a == 2) {
        std::cout << "How many sea otters do you want to buy?\n";
        std::cin >> b;
        Zoo::buy_sea_otter(b);
    } else if(a == 3) {
        std::cout << "How many sloths do you want to buy?\n";
        std::cin >> b;
        Zoo::buy_sloth(b);
    } else if(a == 4) {
        std::cin.clear();
    }
    int base = 100;
    Zoo::food(base);
    while(true) {
        std::cout << "\nWould you like to sell an animal?" << std::endl;
        std::cout << "1) sell monkeys\n2) sell sea otters\n3) sell sloths\n4) sell none" << std::endl;
        while(!(std::cin >> c)) {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Incorrect entry. Try again: ";
        }
        if(c == 1) {
            if(this->monkeys == NULL) {
                Zoo::display_monkeys();
            } else {
                Zoo::sell_monkey();
                break;
            }
        } else if(c == 2) {
            if(this->sea_otters == NULL) {
                Zoo::display_sea_otters();
            } else {
                Zoo::sell_sea_otter();
                break;
            }
        } else if(c == 3) {
            if(this->sloths == NULL) {
                Zoo::display_sloths();
            } else {
                Zoo::sell_sloth();
                break;
            }
        } else if(c == 4) {
            std::cin.clear();
            break;
        }
    }
}