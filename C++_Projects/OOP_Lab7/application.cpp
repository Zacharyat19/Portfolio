#include <iostream>

#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"

void print_shape_info(Shape &);

int main() {
    Rectangle r("Rectangle", "Red", 1.1, 2.3);
    Shape *shape = &r;
    print_shape_info(*shape);
    return 0;
}

void print_shape_info(Shape &a) {
    std::cout << a.get_name() << a.get_color() << a.area() << std::endl;
}   