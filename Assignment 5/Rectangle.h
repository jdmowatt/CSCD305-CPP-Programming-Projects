#pragma once
#include "Shape2D.h"

class Rectangle : public Shape2D {

protected:
    double width, height;

public:
    Rectangle(const std::string& _name, double w, double h)
        : Shape2D(_name), width(w), height(h) {}

    double computeArea() const { return width * height; }

    void printDetail() const {
        std::cout << name << ", " << getType() << ", width: " << width
            << ", height: " << height << ", area: " << computeArea() << "." << std::endl;
    }
};