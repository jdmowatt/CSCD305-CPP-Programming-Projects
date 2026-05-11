//Jake Mowatt
//Compiled with CLion CMake, or use:
//g++ -Wall -std=c++20 graph_tester.cpp Point3D.cpp Graph.cpp -o graph_tester

#pragma once
#include <vector>
#include <set>
#include <map>
#include "Point3D.h"

class Graph {
public:
    // Extracts information from filename to initialize mVertices and vIndices
    bool loadCityInformation(const char *filename);

    // Generates the connectivity map among cities;
    //Calls Link function to generate connectivity information for all cities
    void Generate();

    //prints connectivity information of different cities
    void Print();

    // Displays connectivity information for a particular city “a” and finds
    //distance information of neighboring cities
    void showConnectivity(int a);

private:
    std::vector<Point3D>cityCoordinates;
    std::vector<int> cityIndices;
    std::map<int, std::set<int>> Connectivity;
};