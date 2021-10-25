// header file stu_sort.hpp to declare your sorting functions
#ifndef STUSORT_HPP
#define STUSORT_HPP
#include "student.hpp"
#include <string> //you will have to use string in C++

// Multi Sort functions
void MultiSort(Domestic *DomesticStudent, int num);
void MultiSort(International *InternationalStudent, int num);
void MultiSort(Student *Students, int num);

// Single Sort functions
void SingleSort(Domestic *DomesticStudent, int num, int num2, char type);
void SingleSort(International *InternationalStudent, int num, int num2, char type);
void SingleSort(Student *Students, int num, int num2, char type);

#endif