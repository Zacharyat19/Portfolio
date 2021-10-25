#ifndef SLOTH_H
#define SLOTH_H


#include "Animal.h"

class Sloth:public Animal {
    public:
        Sloth();
        Sloth(int, int, int, int, int);
        ~Sloth();
};
#endif