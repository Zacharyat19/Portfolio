#include <iostream>
#include <fstream>

#ifndef CATALOG_H
#define CATALOG_H
struct wizard {
    std::string name;
    int id;
    std::string password;
    std::string position;
    float beardLength;
};

struct spellbook {
    std::string title; 
    std::string author; 
    int numPages; 
    int edition; 
    int numSpells; 
    float avgSuccessRate; 
    struct spell *s; 
};

struct spell {
    std::string name;
    float successRate;
    std::string effect;
};

spellbook *createSpellbooks(int); 
void populateSpellbook(spellbook *, int, std::ifstream &); 
spell *createSpells(int); 
void populateSpells(spell *, int, std::ifstream &); 
wizard *makeWizards(int);
void populateWizard(wizard *, int, std::ifstream &); 
void delete_info(wizard **, int, spellbook **);   
void printSpellBook(spellbook *, int, wizard *, int *);
void sortPages(spellbook *, int);
bool checkWiz(wizard *, int, std::string, int, int *);
void sortEffect(spellbook *, int, wizard *, int *);
int outputPages(spellbook *, int, std::ofstream &, wizard *, int *);
int outputEffects(spellbook *, int, std::ofstream &, wizard *, int *);
int outputSuccess(spellbook *, int, std::ofstream &, wizard *, int *);
void sortSuccess(spellbook *, int);
void printSuccess(spellbook *, int, wizard *, int *);
int run(spellbook *, int, wizard *, int *);
#endif