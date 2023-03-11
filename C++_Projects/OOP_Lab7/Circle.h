#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>

#include "Shape.h"

class Circle:public Shape {
    private:
        float radius;
    public:
        Circle();
        Circle(std::string, std::string, float);
        ~Circle();
        float get_radius() const;
        float set_radius(float);
        float area();
};

#endif