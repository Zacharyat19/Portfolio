#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

#include "catalog.h"


/**************************************************
 ** Function: createSpellBook
 ** Description: creates an array of spellbook type
 ** Parameters: int size
 ** Pre-Conditions: size is int
 ** Post-Conditions: returns spellbook array
 **************************************************/
spellbook *createSpellbooks(int size) {
    spellbook *books = new spellbook[size];
    return books;
}


/*********************************************************************
 ** Function: populateSpellBook
 ** Description: Fills spellbook array from spellbook.txt
 ** Parameters: int size, spellbook *books, ifstream &fin
 ** Pre-Conditions: size is int, spellbook is array, ifstream is clear
 ** Post-Conditions: Fills spellbook array
 *********************************************************************/
void populateSpellbook(spellbook *books, int size, std::ifstream &fin) {
    for(int i = 0; i < size; i++) {
        fin >> books[i].title >> books[i].author >> books[i].numPages >> books[i].edition >> books[i].numSpells;
        books[i].s = createSpells(books[i].numSpells);
        populateSpells(books[i].s, books[i].numSpells, fin);
    }
}


/**********************************************
 ** Function: createSpell
 ** Description: creates an array of type spell
 ** Parameters: int size
 ** Pre-Conditions: size is int
 ** Post-Conditions: returns spell array
 **********************************************/
spell *createSpells(int size) {
    spell *spells = new spell[size];
    return spells;
}


/******************************************************************
 ** Function: populateSpells
 ** Description: Fills spells array from spellbook.txt
 ** Parameters: int size, spell *spells, ifstream &fin
 ** Pre-Conditions: size is int, spells is array, ifstream is clear
 ** Post-Conditions: Fills spell array
 ******************************************************************/
void populateSpells(spell *spells, int size, std::ifstream &fin) {
    for(int i = 0; i < size; i++) {
        fin >> spells[i].name >> spells[i].successRate >> spells[i].effect;
    }
}


/******************************************************************
 ** Function: printSpellBook
 ** Description: prints the contents of spellbook array
 ** Parameters: int size, *books, *wizards, *p
 ** Pre-Conditions: size is int, *books is an array of spellbooks, 
 **                 wizards is an array of wizards, *p is a pointer
 ** Post-Conditions: prints spellbook array
 ******************************************************************/
void printSpellBook(spellbook *books, int size, wizard *wizards, int *p) {
    bool badBook = false;
    if(wizards[*p].position == "Student") {
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < books[i].numSpells; j++) {
                if(books[i].s[j].effect == "death" || books[i].s[j].effect == "poison") {
                    badBook = true;
                    break;
                }
            }

            if(badBook == false) {
                std::cout << books[i].title << " " <<  books[i].numPages << std::endl;
            } else if(badBook == true) {
                badBook = false;
                continue;
            }
        }
    } else if(!(wizards[*p].position == "student")) {
        for(int i = 0; i < size; i++) {
            std::cout << books[i].title << " " <<  books[i].numPages << std::endl;
        }
    }
}


/************************************************************
 ** Function: sortPages
 ** Description: sorts spellbooks by number of pages
 ** Parameters: int size, spellbook *books
 ** Pre-Conditions: size is int, spellbook is an array
 ** Post-Conditions: spellbooks are sorted by number of pages
 ************************************************************/
void sortPages(spellbook *books, int size) {
    spellbook temp;
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            /*Bubble sort through pages by comparing 
            the pages of i to j
            */
            if(books[j].numPages < books[i].numPages) {
                temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}


/************************************************
 ** Function: makeWizards
 ** Description: creates an array of type wizard
 ** Parameters: int size
 ** Pre-Conditions: size is int
 ** Post-Conditions: returns array of type wizard
 ************************************************/
wizard *makeWizards(int size) {
    wizard *wizards = new wizard[size];
    return wizards;
}


/*****************************************************************
 ** Function: populateWizard
 ** Description: adds the contents of wizards.txt to wizards
 ** Parameters: int size, wizard *wizards, ifstream fin
 ** Pre-Conditions: size is int, wizards is an array, fin is clear
 ** Post-Conditions: wizards is filled from wizards.txt
 *****************************************************************/
void populateWizard(wizard *wizards, int size, std::ifstream &fin) {
    for(int i = 0; i < size; i++) {
        fin >> wizards[i].name >> wizards[i].id >> wizards[i].password >> wizards[i].position >> wizards[i].beardLength;
    }
}


/***********************************************************************************************
 ** Function: checkWiz
 ** Description: checks if a wizard exists
 ** Parameters: *wizards, int size, string password, int Id, int *p
 ** Pre-Conditions: size is int, password is string, wizards is full, Id is int, *p is a pointer
 ** Post-Conditions: returns true if the wizard is found, false otherwise
 ***********************************************************************************************/
bool checkWiz(wizard *wizards, int size, std::string password, int Id, int *p) {
    for(int i = 0; i < size; i++) {
        if(wizards[i].id == Id && wizards[i].password == password) {
            std::cout << "Welcome " << wizards[i].name << std::endl;
            std::cout << "ID: " << wizards[i].id << std::endl;
            std::cout << "Status: " << wizards[i].position << std::endl;
            std::cout << "Beard length: " << wizards[i].beardLength << std::endl;
            *p = i;
            return true;
            break;
        }
    }
    return false;
}


/******************************************************************
 ** Function: sortEffect
 ** Description: prints the spell effects in specific order
 ** Parameters: int size, *books, *wizards, int *p
 ** Pre-Conditions: size is int, *books is an array of spellbooks, 
 **                 wizards is an array of wizards, *p is a pointer
 ** Post-Conditions: prints out the spells in effect order
 ******************************************************************/
void sortEffect(spellbook *books, int size, wizard * wizards, int *p) {
    //This function must print out the spells in order of effect
    //Each for loop will run and print out each spell in the correct order
    if(wizards[*p].position == "Student") {
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < books[i].numSpells; j++) {
                if(books[i].s[j].effect == "bubble") {
                    std::cout << books[i].s[j].effect << " " << books[i].s[j].name << std::endl;
                }
            }
        }

        for(int i = 0; i < size; i++) {
            for(int j = 0; j < books[i].numSpells; j++) {
                if(books[i].s[j].effect == "memory_loss") {
                    std::cout << books[i].s[j].effect << " " << books[i].s[j].name << std::endl;
                }
            }
        }

        for(int i = 0; i < size; i++) {
            for(int j = 0; j < books[i].numSpells; j++) {
                if(books[i].s[j].effect == "fire") {
                    std::cout << books[i].s[j].effect << " " << books[i].s[j].name << std::endl;
                }
            }   
        }
    } else {
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < books[i].numSpells; j++) {
                if(books[i].s[j].effect == "bubble") {
                    std::cout << books[i].s[j].effect << " " << books[i].s[j].name << std::endl;
                }
            }
        }

        for(int i = 0; i < size; i++) {
            for(int j = 0; j < books[i].numSpells; j++) {
                if(books[i].s[j].effect == "memory_loss") {
                    std::cout << books[i].s[j].effect << " " << books[i].s[j].name << std::endl;
                }
            }
        }

        for(int i = 0; i < size; i++) {
            for(int j = 0; j < books[i].numSpells; j++) {
                if(books[i].s[j].effect == "fire") {
                    std::cout << books[i].s[j].effect << " " << books[i].s[j].name << std::endl;
                }
            }
        }

        for(int i = 0; i < size; i++) {
            for(int j = 0; j < books[i].numSpells; j++) {
                if(books[i].s[j].effect == "poison") {
                    std::cout << books[i].s[j].effect << " " << books[i].s[j].name << std::endl;
                }
            }
        }

        for(int i = 0; i < size; i++) {
            for(int j = 0; j < books[i].numSpells; j++) {
                if(books[i].s[j].effect == "death") {
                    std::cout << books[i].s[j].effect << " " << books[i].s[j].name << std::endl;
                }
            }
        }
    }
}


/*******************************************************************************
 ** Function: outputPages
 ** Description: prints sorted pages to text file
 ** Parameters: int size, *books, &fout, *wizards, int *p
 ** Pre-Conditions: &fout is open size is int, *books is an array of spellbooks, 
 **                 wizards is an array of wizards, *p is a pointer
 ** Post-Conditions: prints results to text file
 *******************************************************************************/
int outputPages(spellbook *books, int size, std::ofstream &fout, wizard *wizards, int *p) {
    std::string file;
    std::cout <<"Enter a file name: " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, file);
    fout.open(file.c_str(), std::ios::app);

    if(!fout.is_open()) {
        std::cout << "Error opening file to write" << std::endl;
        return 1;
    }

    bool badBook = false;
    if(wizards[*p].position == "Student") {
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < books[i].numSpells; j++) {
                if(books[i].s[j].effect == "death" || books[i].s[j].effect == "poison") {
                    badBook = true;
                    break;
                }
            }

            if(badBook == false) {
                fout << books[i].title << " " <<  books[i].numPages << std::endl;
            } else if(badBook == true) {
                badBook = false;
                continue;
            }
        }
    } else if(!(wizards[*p].position == "student")) {
        for(int i = 0; i < size; i++) {
            fout << books[i].title << " " <<  books[i].numPages << std::endl;
        }
    }
   fout.close();
   return 0;
}


/******************************************************************************
 ** Function: outputEffects
 ** Description: prints effects to text file
 ** Parameters: int size, *books, &fout, *wizards, int *p
 ** Pre-Conditions: fout is open, size is int, *books is an array of spellbooks, 
 **                 wizards is an array of wizards, *p is a pointer
 ** Post-Conditions: prints results to text file
 ******************************************************************************/
int outputEffects(spellbook * books, int size, std::ofstream &fout, wizard *wizards, int *p) {
    std::string file;
    std::cout <<"Enter a file name: " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, file);
    fout.open(file.c_str(), std::ios::app);

    if(!fout.is_open()) {
        std::cout << "Error opening file to write" << std::endl;
        return 1;
    }

    if(wizards[*p].position == "Student") {
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < books[i].numSpells; j++) {
                if(books[i].s[j].effect == "bubble") {
                    fout << books[i].s[j].effect << " " << books[i].s[j].name << std::endl;
                }
            }
        }

        for(int i = 0; i < size; i++) {
            for(int j = 0; j < books[i].numSpells; j++) {
                if(books[i].s[j].effect == "memory_loss") {
                    fout << books[i].s[j].effect << " " << books[i].s[j].name << std::endl;
                }
            }
        }

        for(int i = 0; i < size; i++) {
            for(int j = 0; j < books[i].numSpells; j++) {
                if(books[i].s[j].effect == "fire") {
                    fout << books[i].s[j].effect << " " << books[i].s[j].name << std::endl;
                }
            }   
        }
    } else {
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < books[i].numSpells; j++) {
                if(books[i].s[j].effect == "bubble") {
                    fout << books[i].s[j].effect << " " << books[i].s[j].name << std::endl;
                }
            }
        }

        for(int i = 0; i < size; i++) {
            for(int j = 0; j < books[i].numSpells; j++) {
                if(books[i].s[j].effect == "memory_loss") {
                    fout << books[i].s[j].effect << " " << books[i].s[j].name << std::endl;
                }
            }
        }

        for(int i = 0; i < size; i++) {
            for(int j = 0; j < books[i].numSpells; j++) {
                if(books[i].s[j].effect == "fire") {
                    fout << books[i].s[j].effect << " " << books[i].s[j].name << std::endl;
                }
            }
        }

        for(int i = 0; i < size; i++) {
            for(int j = 0; j < books[i].numSpells; j++) {
                if(books[i].s[j].effect == "poison") {
                    fout << books[i].s[j].effect << " " << books[i].s[j].name << std::endl;
                }
            }
        }

        for(int i = 0; i < size; i++) {
            for(int j = 0; j < books[i].numSpells; j++) {
                if(books[i].s[j].effect == "death") {
                    fout << books[i].s[j].effect << " " << books[i].s[j].name << std::endl;
                }
            }
        }
    }
    fout.close();
    return 0;
}


/*******************************************************************************
 ** Function: outputSucccess
 ** Description: prints success to text file
 ** Parameters: int size, *books, &fout, *wizards, int *p
 ** Pre-Conditions: fout is open, size is int, *books is an array of spellbooks, 
 **                 wizards is an array of wizards, *p is a pointer
 ** Post-Conditions: prints results to text file
 *******************************************************************************/
int outputSuccess(spellbook *books, int size, std::ofstream &fout, wizard *wizards, int *p) {
    std::string file;
    std::cout <<"Enter a file name: " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, file);
    fout.open(file.c_str(), std::ios::app);

    if(!fout.is_open()) {
        std::cout << "Error opening file to write" << std::endl;
        return 1;
    }

    float success = 0;
    bool badBook = false;

    if(wizards[*p].position == "Student") {
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < books[i].numSpells; j++) {
                if(books[i].s[j].effect == "death" || books[i].s[j].effect == "poison") {
                    badBook = true;
                    break;
                }
            }

            if(badBook == false) {
                for(int j = 0; j < books[i].numSpells; j++) {
                    success += books[i].s[j].successRate;
                }
                fout << books[i].title << " " << success << std::endl;
            } else if(badBook == true) {
                badBook = false;
                continue;
            }
        }
    } else if(!(wizards[*p].position == "student")) {
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < books[i].numSpells; j++) {
                success += books[i].s[j].successRate;
            }
            fout << books[i].title << " " << success << std::endl;
        }
    }
    fout.close();
    return 0;
}


/***************************************************************
 ** Function: sortSuccess
 ** Description: sorts books by success rate
 ** Parameters: int size, *books
 ** Pre-Conditions: size is int, books is an array of spellbooks
 ** Post-Conditions: books is sorted by success rate
 ***************************************************************/
void sortSuccess(spellbook *books, int size) {
    spellbook temp;
    float success = 0;
    float successTwo = 0;
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < books[i].numSpells; j++) {
            success += books[i].s[j].successRate;
        }

        for(int j = 0; j < books[i + 1].numSpells; i++) {
            successTwo += books[i + 1].s[j].successRate;
        } 

        for(int j = i + 1; j < size; j++) {
            if(successTwo < success) {
                temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}


/******************************************************************
 ** Function: printSuccss
 ** Description: prints books in order of success rate
 ** Parameters: int size, *books, *wizards, int *p
 ** Pre-Conditions: size is int, *books is an array of spellbooks, 
 **                 wizards is an array of wizards, *p is a pointer
 ** Post-Conditions: print results to console
 ******************************************************************/
void printSuccess(spellbook *books, int size, wizard *wizards, int *p) {
    bool badBook = false;
    float success = 0;

    if(wizards[*p].position == "Student") {
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < books[i].numSpells; j++) {
                if(books[i].s[j].effect == "death" || books[i].s[j].effect == "poison") {
                    badBook = true;
                    break;
                }
            }

            if(badBook == false) {
                for(int j = 0; j < books[i].numSpells; j++) {
                    success += books[i].s[j].successRate;
                }
                std::cout << books[i].title << " " << success << std::endl;
            } else if(badBook == true) {
                badBook = false;
                continue;
            }
        }
    } else if(!(wizards[*p].position == "student")) {
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < books[i].numSpells; j++) {
                success += books[i].s[j].successRate;
            }
            std::cout << books[i].title << " " << success << std::endl;
        }
    }
}


/******************************************************************
 ** Function: run
 ** Description: runs the main program selections
 ** Parameters: int size, *books, *wizards, int *p
 ** Pre-Conditions: size is int, *books is an array of spellbooks, 
 **                 wizards is an array of wizards, *p is a pointer
 ** Post-Conditions: calls functions and exits gracefully
 ******************************************************************/
int run(spellbook *books, int size, wizard *wizards, int *p) {
    while(true) {
        std::ofstream fout;
        int choice;
        std::cout << "What option would you like to choose?" << std::endl;
        std::cout << "1. Sort spellbooks by page numbers" << std::endl;
        std::cout << "2. Group spells by their effect" << std::endl;
        std::cout << "3. Sort spellbooks by average success rate" << std::endl;
        std::cout << "4. Quit" << std::endl;
        std::cin >> choice;
        std::cin.clear();

        if(choice == 1) {
            int output;
            std::cout << "How would you like the information to be displayed" << std::endl;
            std::cout << "1. Print to screen" << std::endl;
            std::cout << "2. print to file" << std::endl;
            std::cin >> output;
            sortPages(books, size);
            if(output == 1) {
                printSpellBook(books, size, wizards, p);
            } else if(output == 2) {
                outputPages(books, size, fout, wizards, p);
            }
        } else if(choice == 2) {
            int output;
            std::cout << "How would you like the information to be displayed" << std::endl;
            std::cout << "1. Print to screen" << std::endl;
            std::cout << "2. print to file" << std::endl;
            std::cin >> output;
            if(output == 1) {
                sortEffect(books, size, wizards, p);
            } else if(output == 2) {
                outputEffects(books, size, fout, wizards, p);
            }
        } else if(choice == 3) {
            int output;
            std::cout << "How would you like the information to be displayed" << std::endl;
            std::cout << "1. Print to screen" << std::endl;
            std::cout << "2. print to file" << std::endl;
            std::cin >> output;
            sortSuccess(books, size);
            if(output == 1) {
                printSuccess(books, size, wizards, p);
            } else if(output == 2) {
                outputSuccess(books, size, fout, wizards , p);
            }
        } else if(choice == 4) {
            return 0;
        }
    }
}



void delete_info(wizard **wizards, int size, spellbook **books) {
    for(int i = 0; i < size; i++) {
        delete [](*books)[i].s;
    }
    
    delete [](*books);
    *books = NULL;

    delete [](*wizards);
    *wizards = NULL;
}