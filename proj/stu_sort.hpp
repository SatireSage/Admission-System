// header file stu_sort.hpp to declare your sorting functions
#ifndef STUSORT_HPP
#define STUSORT_HPP
#include "student.hpp"
#include <string> //you will have to use string in C++

// Multi Sort functions
void MultiSort(Domestic *DomesticStudent, int num, string type, string order);
void MultiSort(International *InternationalStudent, int num, string type, string order);

// Single Sort functions
void SingleSort(Domestic *DomesticStudent, int num, char type, string order);
void SingleSort(International *InternationalStudent, int num, char type, string order);

#endif