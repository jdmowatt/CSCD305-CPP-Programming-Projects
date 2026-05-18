#pragma once
#include "Shape3D.h"

class Box : public Shape3D {

protected:
    double width, height, depth;

public:
    Box(const std::string& _name, double w, double h, double d)
        : Shape3D(_name), width(w), height(h), depth(d) {}

    double computeArea() const {
        return 2 * (width * height) + 2 * (width * depth) + 2 * (height * depth);
    }

    double computeVolume() const { return width * height * depth; }

    void printDetail() const {
        std::cout << name << ", " << getType() << ", width: " << width
            << ", height: " << height << ", depth: " << depth << ", area: " << computeArea()
            << ", volume: " << computeVolume() << "." << std::endl;
    }
};