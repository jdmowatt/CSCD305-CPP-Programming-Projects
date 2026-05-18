//Jake Mowatt
//Compiled with CLion CMake, or use:
//g++ -Wall -std=c++20 shape_hierarchy_tester.cpp -o shape_hierarchy_tester

#pragma once
#include "Shape.h"

class Shape2D : public Shape {

public:
    Shape2D(const std::string& _name) : Shape(_name) {}
    virtual ~Shape2D() {}
    std::string getType() const { return "2D Shape"; }
    virtual double computeArea() const = 0;
};