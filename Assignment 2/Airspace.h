//Jake Mowatt
//Compiled with CLion CMake, or use:
//g++ -Wall -std=c++20 interception_tester.cpp Point3D.cpp Airspace.cpp Radar.cpp -o interception_tester

#pragma once
#include "Point3D.h"

class Radar;

class Airspace {
    friend class Radar;

    double radius, height;
    Point3D center;

    public:
    //Default Constructor
    Airspace(): radius{0}, height{0} {}

    //Parameterized Constructor
    Airspace(double radius, double height, Point3D center)
        : radius{radius}, height{height}, center{center}
    {}

    //Getters
    double getRadius() const;
    double getHeight() const;
    Point3D getCenter() const;

    //Setters
    void setRadius(double radius);
    void setHeight(double height);
    void setCenter(Point3D center);
};