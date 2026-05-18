//Jake Mowatt
//Compiled with CLion CMake, or use:
//g++ -Wall -std=c++20 shape_hierarchy_tester.cpp -o shape_hierarchy_tester

#pragma once
#include "Shape2D.h"

class Shape3D : public Shape2D {

public:
    Shape3D(const std::string& _name) : Shape2D(_name) {}
    virtual ~Shape3D() {}
    std::string getType() const { return "3D Shape"; }
    virtual double computeVolume() const = 0;
};