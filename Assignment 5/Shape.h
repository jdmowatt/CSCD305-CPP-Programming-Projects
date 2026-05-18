//Jake Mowatt
//Compiled with CLion CMake, or use:
//g++ -Wall -std=c++20 shape_hierarchy_tester.cpp -o shape_hierarchy_tester

#pragma once
#include <string>
#include <iostream>

class Shape {

protected:
    std::string name;

public:
    Shape(const std::string& _name) :name{ _name } {};
    virtual ~Shape() {}
    const double PI = 3.14159265358979;
    virtual void printDetail() const = 0;
    virtual std::string getType() const = 0;
};