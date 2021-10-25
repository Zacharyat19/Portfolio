#include <iostream>

#include "Square.h"

Square::Square() {}

Square::Square(std::string name, std::string color, float width, float height):Rectangle(name, color, width, height) {}

Square::~Square() {}

float Square::area() {
    return (get_width() * get_height());
}