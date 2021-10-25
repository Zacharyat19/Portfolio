/*********************************************
 ** Program: Wizard Spellbook Catalog
 ** Author: Zach Taylor.
 ** Date: 4/8/2020.
 ** Description: Categorizes a book of spells
 ** Input: wizards.txt, spellbooks.txt
 ** Output: output file or terminal
 ********************************************/
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

#include "catalog.h"

int main(int argc, char *argv[]) {
    if(argc != 3) {
        std::cout << "Entered too many/too few arguments." << std::endl;
        return 0;
    }
    std::ifstream fin;
    fin.open("spellbooks.txt");

    if(!fin.is_open()) {
        std::cout << "Error opening file to read." << std::endl;
        return 1;
    }

    std::string temp;
    int numBooks;
    std::getline(fin, temp);
    numBooks = atoi(temp.c_str());

    spellbook *books = createSpellbooks(numBooks);
    populateSpellbook(books, numBooks, fin);
    fin.close();

    std::ifstream fin2;
    fin2.open("wizards.txt");
    if(!fin2.is_open()) {
        std::cout << "Error opening file to read." << std::endl;
        return 1;
    }

    std::string temp2;
    int numWiz;
    std::getline(fin2, temp2);
    numWiz = atoi(temp2.c_str());

    wizard *wizards = makeWizards(numWiz);
    populateWizard(wizards, numWiz, fin2);
    fin2.close();

    int Id;
    std::string password;
    int counter = 0;
    int *p = new int;

    while(counter < 3) {
        std::cout << "Please enter your id: ";
        while(!(std::cin >> Id)) {
            std::cin.clear();
            std::cin.ignore(123, '\n');
            std::cout << "Invalid Id, try again: ";
        }
        std::cout << "Please enter your password: ";
        std::cin >> password;
        
        if(checkWiz(wizards, numWiz, password, Id, p)) {
            break;
        }

        std::cout << "Incorrect ID or password" << std::endl;
        counter++;
        if(counter == 3) {
            std::cout << "All attempts used, restart to try again" << std::endl;
            return 0;
        }
    }

    run(books, numBooks, wizards, p);
    delete_info(&wizards, numBooks, &books);
    delete p;

    return 0;
}