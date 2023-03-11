#include <iostream>

#include "Shape.h"

Shape::Shape() {
    this->name = "";
    this->color = "";
    this->area = 0;
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

float Shape::get_area() const {
    return this->area;
}

void Shape::set_area(float area) {
    this->area = area;
}

void Shape::set_name(std::string name) {
    this->name = name;
}

void Shape::set_color(std::string color) {
    this->color = color;
}

float Shape::measure_area() {
    return 0;
}

bool operator>(const Shape &a, const Shape &b) {
    return a.get_area() > b.get_area();
}

bool operator<(const Shape &a, const Shape &b) {
    return a.get_area() < b.get_area();
}

