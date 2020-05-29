#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape {
    protected:
        std::string name;
        std::string color;
    public:
        Shape();
        Shape(std::string, std::string);
        ~Shape();
        std::string get_name() const;
        std::string get_color() const;
        void set_name(std::string);
        void set_color(std::string);
        int area();
};

#endif