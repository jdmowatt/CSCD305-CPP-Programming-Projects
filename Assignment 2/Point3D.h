//Jake Mowatt
//Compiled with CLion CMake, or use:
//g++ -Wall -std=c++20 interception_tester.cpp Point3D.cpp Airspace.cpp Radar.cpp -o interception_tester

#pragma once

class Point3D {

    double x, y, z;

    public:
    //Default Constructor
    Point3D(): x{0}, y{0}, z{0} {}

    //Parameterized Constructor
    Point3D(double x, double y, double z): x{x}, y{y}, z{z} {};

    //Getters
    double getX() const;
    double getY() const;
    double getZ() const;

    //Setters
    void setX(double x);
    void setY(double y);
    void setZ(double z);

    //Adds another Point3D to this Point3D
    Point3D& addPoints(const Point3D &P);

    //Subtracts another Point3D from this Point3D
    Point3D& subtractPoints(const Point3D &P);

    //Returns the magnitude
    double magnitude();
};