//Jake Mowatt
//Milk is used as the default Chocolate
//Compiled with CLion CMake, or use:
//g++ -Wall -std=c++20 test_chocolate_box.cpp Chocolate.cpp ChocolateBox.cpp -o test_chocolate_box
#pragma once
#include <string>
#include <iostream>


class Chocolate {
    std::string type;
    double cocoa;
public:
    Chocolate(const std::string choco, double c);
    Chocolate();
    Chocolate(const std::string choco);
    Chocolate(double c);

    Chocolate(const Chocolate &);
    Chocolate& operator=(const Chocolate&);

    Chocolate& setType(std::string cType);
    Chocolate& setCocoaPercentage(double c);

    std::string getType() const;
    double getCocoaPercentage() const;

    friend bool operator==(const Chocolate &chocoOne, const Chocolate &chocoTwo);
    friend Chocolate operator+(const Chocolate &chocoOne, const Chocolate &chocoTwo);
    friend bool operator!(const Chocolate &choc);
    friend std::istream &operator>>(std::istream&, Chocolate&);
    friend std::ostream &operator<<(std::ostream&, const Chocolate&);
};