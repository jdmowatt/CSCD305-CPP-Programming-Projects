#pragma once
#include "Shape2D.h"

class Circle : public Shape2D {

protected:
    double radius;

public:
    Circle(const std::string& _name, double r) : Shape2D(_name), radius(r) {}

    double computeArea() const { return PI * radius * radius; }

    void printDetail() const {
        std::cout << name << ", " << getType() << ", radius: " << radius
            << ", area: " << computeArea() << "." << std::endl;
    }
};