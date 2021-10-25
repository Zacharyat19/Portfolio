#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>

#include "Rectangle.h"

class Square:public Rectangle {
    public:
        Square();
        Square(std::string, std::string, float, float);
        ~Square();
        float area();
};

#endif