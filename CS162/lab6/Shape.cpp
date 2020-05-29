#include <iostream>

#include "Shape.h"

Shape::Shape() {
    this->name = "";
    this->color = "";
}

Shape::Shape(std::string name, std::string color) {
    this->name = name;
    this->color = color;
}

Shape::~Shape() {}

std::string Shape::get_name() const {
    return this->name;
}

std::string Shape::get_color() const {
    return this->color;
}

void Shape::set_name(std::string name) {
    this->name = name;
}

void Shape::set_color(std::string color) {
    this->color = color;
}

int Shape::area() {
    return 0;
}