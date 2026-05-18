#pragma once
#include "Shape2D.h"

class Triangle : public Shape2D {

protected:
    double base, height;

public:
    Triangle(const std::string& _name, double b, double h)
        : Shape2D(_name), base(b), height(h) {}

    double computeArea() const { return 0.5 * base * height; }

    void printDetail() const {
        std::cout << name << ", " << getType() << ", base: " << base
            << ", height: " << height << ", area: " << computeArea() << "." << std::endl;
    }
};