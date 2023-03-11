#ifndef MONKEY_H
#define MONKEY_H


#include "Animal.h"

class Monkey:public Animal {
    public:
        Monkey();
        Monkey(int, int, int, int, int);
        ~Monkey();
};
#endif