#pragma once
#include "Shape3D.h"

class Sphere : public Shape3D {

protected:
    double radius;

public:
    Sphere(const std::string& _name, double r) : Shape3D(_name), radius(r) {}

    double computeArea() const { return 4 * PI * radius * radius; }
    double computeVolume() const { return (4 * PI * radius * radius * radius) / 3; }

    void printDetail() const {
        std::cout << name << ", " << getType() << ", radius: " << radius
            << ", area: " << computeArea() << ", volume: " << computeVolume()
            << "." << std::endl;
    }
};