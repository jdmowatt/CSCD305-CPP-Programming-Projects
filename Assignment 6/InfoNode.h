//Jake Mowatt
//Compiled with CLion CMake, or use:
//g++ -Wall -std=c++20 info_repostory_tester.cpp -o info_repostory_tester

#pragma once

//Forward Declaration
template<class T, class U, class V>
class InfoRepository;

//Info Node Class
template<class T, class U, class V>
class InfoNode{
    friend class InfoRepository<T, U, V>;

public:
    InfoNode(T& t, U& u, V& v, InfoNode<T, U, V>* p) :dataOne(t), dataTwo(u), dataThree(v),
    next(p){}

private:
    T dataOne;
    U dataTwo;
    V dataThree;
    InfoNode* next; // points to next node in the list
};