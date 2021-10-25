#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

#include "Shape.h"

class Rectangle:public Shape {
    private:
        float width;
        float height;
    public:
        Rectangle();
        Rectangle(std::string, std::string, float, float);
        ~Rectangle();
        float get_width() const;
        float get_height() const;
        float set_width(float);
        float set_height(float);
        float area();
};

#endif