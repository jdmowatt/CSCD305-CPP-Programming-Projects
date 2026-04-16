//Jake Mowatt
//Compiled with CLion CMake, or use:
//g++ -Wall -std=c++20 interception_tester.cpp Point3D.cpp Airspace.cpp Radar.cpp -o interception_tester

#pragma once
#include "Airspace.h"

class Radar {

    Point3D position;

    public:
    //Default Constructor
    Radar() {}

    //Parameterized Constructor
    Radar(Point3D position) : position{position} {}

    //Checks whether an Enemy Plane has entered the Airspace Zone
    void checkViolation(Airspace &s);
};