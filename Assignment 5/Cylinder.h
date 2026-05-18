#pragma once
#include "Shape3D.h"

class Cylinder : public Shape3D {

protected:
    double radius, height;

public:
    Cylinder(const std::string& _name, double r, double h)
        : Shape3D(_name), radius(r), height(h) {}

    double computeArea() const {
        return 2 * PI * radius * height + 2 * PI * radius * radius;
    }
    double computeVolume() const { return PI * radius * radius * height; }

    void printDetail() const {
        std::cout << name << ", " << getType() << ", radius: " << radius
            << ", height: " << height << ", area: " << computeArea()
            << ", volume: " << computeVolume() << "." << std::endl;
    }
};