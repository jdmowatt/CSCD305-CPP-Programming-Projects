#include "Graph.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

bool Graph::loadCityInformation(const char* fileName) {
    //Open File
    std::ifstream ifs(fileName);
    if (!ifs.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return false;
    }

    //Parse File
    std::string line;
    while (getline(ifs, line)) {
        if (line.empty()) {
            continue;
        }

        //Check for line type
        std::istringstream iss(line);
        char type;
        iss >> type;

        //If 'p', push point into cityCoordinates
        if (type == 'p') {
            double x, y, z;
            iss >> x;
            iss >> y;
            iss >> z;
            cityCoordinates.emplace_back(x,y,z);
        //If 'c' push city indices into cityIndices
        } else if (type == 'c') {
            int idx;
            for (int i = 0; i < 3; i++) {
                iss >> idx;
                cityIndices.push_back(idx);
            }
        }
    }

    return true;
}

void Graph::Generate() {
    for (size_t i = 0; i + 2 < cityIndices.size(); i += 3) {
        int a = cityIndices[i];
        int b = cityIndices[i + 1];
        int c = cityIndices[i + 2];

        Connectivity[a].insert(b);
        Connectivity[a].insert(c);

        Connectivity[b].insert(a);
        Connectivity[b].insert(c);

        Connectivity[c].insert(a);
        Connectivity[c].insert(b);
    }
}

void Graph::Print() {
    std::cout << "Printing information for all cities :" << std::endl;
    for (const auto& pair : Connectivity) {
        std::cout << "[" << pair.first << " ]";
        for (int neighbor : pair.second) {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::showConnectivity(int a) {
    std::cout << "Showing Connectivity for Node " << a << " :" << std::endl;
    Point3D p1 = cityCoordinates[a];
    for (int neighbor : Connectivity[a]) {
        Point3D p2 = cityCoordinates[neighbor];
        double dist = p2.subtractPoints(p1).magnitude();
        std::cout << "[" << a << "-" << neighbor << " ]: " << dist << std::endl;
    }
}
