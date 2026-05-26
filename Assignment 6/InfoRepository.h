//Jake Mowatt
//Compiled with CLion CMake, or use:
//g++ -Wall -std=c++20 info_repostory_tester.cpp -o info_repository_tester

#pragma once
#include "InfoNode.h"
#include <iostream>
#include <iomanip>

//Info Repository Class
template<class T, class U, class V>
class InfoRepository{
public:
    InfoRepository(std::string name) :first(0), iName(name){}
    ~InfoRepository();
    void addInfo(T t, U u, V v);
    bool isEmpty();
    void printInformation();
    void retrieveInfoNode(const T &t);

private:
    InfoNode<T, U, V>* first;
    std::string iName;
};

#include "InfoRepository.tpp"