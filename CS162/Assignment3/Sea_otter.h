#ifndef SEA_OTTER_H
#define SEA_OTTER_H


#include "Animal.h"

class Sea_otter:public Animal {
    public:
        Sea_otter();
        Sea_otter(int, int, int, int, int);
        ~Sea_otter();
};
#endif