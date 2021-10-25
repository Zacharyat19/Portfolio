#include <iostream>

#include "Rectangle.h"

Rectangle::Rectangle() {
    this->width = 0.0;
    this->height = 0.0;
}

Rectangle::Rectangle(std::string name, std::string color, float width, float height) {
    this->name = name;
    this->color = color;
    this->width = width;
    this->height = height;
}

Rectangle::~Rectangle() {}

float Rectangle::get_width() const {
    return this->width;
}

float Rectangle::get_height() const {
    return this->height;
}

float Rectangle::set_width(float width) {
    this->width = width;
}

float Rectangle::set_height(float height) {
    this->height = height;
}

float Rectangle::area() {
    return (this->width * this->height);
}