#include <iostream>

#include "Circle.h"

Circle::Circle() {
    this->radius = 0.0;
}

Circle::Circle(std::string name, std::string color, float radius):Shape(name,color) {
    this->radius = radius;
}

Circle::~Circle() {}

float Circle::get_radius() const {
    return this->radius;
}

float Circle::set_radius(float radius) {
    this->radius = radius;
}

float Circle::area() {
    float pi = 3.14;
    float square = this->radius*2;
    return (pi * square);
}