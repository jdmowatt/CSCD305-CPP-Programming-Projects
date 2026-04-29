//Jake Mowatt
//Milk is used as the default Chocolate
//Compiled with CLion CMake, or use:
//g++ -Wall -std=c++20 test_chocolate_box.cpp Chocolate.cpp ChocolateBox.cpp -o test_chocolate_box
#pragma once
#include "Chocolate.h"

class ChocolateBox {
    friend bool operator==(const ChocolateBox&, const ChocolateBox&);
    friend bool operator!(const ChocolateBox&);
    friend ChocolateBox operator+(const ChocolateBox&, const ChocolateBox&);
    friend std::ostream& operator<<(std::ostream&, const ChocolateBox&);
    friend std::istream& operator>>(std::istream&, ChocolateBox&);
    friend bool isEmpty(const ChocolateBox&);
public:
    ChocolateBox(int w, int h, Chocolate c);
    ChocolateBox();
    ChocolateBox(int w, int h);
    ChocolateBox(Chocolate c);

    ChocolateBox(const ChocolateBox&);//copy constructor
    ChocolateBox(ChocolateBox&&);//move constructor
    ChocolateBox& operator=(const ChocolateBox&);//copy assignment operator
    ChocolateBox& operator=(ChocolateBox&&);//move assignment operator

    ~ChocolateBox();//destructor
private:
    int width;
    int height;
    Chocolate** choco;
};