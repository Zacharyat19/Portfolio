#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape {
    protected:
        std::string name;
        std::string color;
        float area;
    public:
        Shape();
        Shape(std::string, std::string);
        ~Shape();
        virtual std::string get_name() const;
        virtual std::string get_color() const;
        float get_area() const;
        void set_area(float);
        void set_name(std::string);
        void set_color(std::string);
        virtual float measure_area();
        friend bool operator>(const Shape &, const Shape &);
        friend bool operator<(const Shape &, const Shape &);
};

#endif