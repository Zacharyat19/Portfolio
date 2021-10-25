#include <iostream>

#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"

int main() {
    Shape s;
    Shape s2("Shape", "Red");

    std::cout << "Shape one: " << s.get_name() << " " << s.get_color() << std::endl;
    std::cout << "Shape two: " << s2.get_name() << " " << s2.get_color() << std::endl;

    Rectangle r;
    Rectangle r2("Rectangle", "Blue", 3.2, 4.2);

    std::cout << "\nRectangle one: " << r.get_width() << " " << r.get_height() << std::endl;
    std::cout << "Rectangle two: " << r2.get_name() << " " << r2.get_color() << " " << 
                r2.get_width() << " " << r2.get_height() << std::endl;

    Circle c;
    Circle c2("Circle", "Yellow", 2.4);

    std::cout << "\nCircle one: " << c.get_radius() << std::endl;
    std::cout << "Circle two: " << c2.get_name() << " " << c2.get_color() << " " << c2.get_radius() << std::endl;

    Square sq;
    Square sq2("Square", "Purple", 2.3, 5.7);

    std::cout << "\nSquare one: " << sq.get_width() << " " << sq.get_height() << std::endl;
    std::cout << "Square two: " << sq2.get_name() << " " << sq2.get_color() << " " << 
                sq2.get_width() << " " << sq2.get_height() << std::endl;

    std::cout << "\nRectangle area: " << r2.area() << std::endl;
    std::cout << "Circle area: " << c2.area() << std::endl;
    return 0;
}