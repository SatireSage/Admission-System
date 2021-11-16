// header file stu_sort.hpp to declare your sorting functions
#ifndef STUSORT_HPP
#define STUSORT_HPP
#include "student.hpp"
#include <string> //you will have to use string in C++

// Multi Sort functions
// void MultiSort(DomesticStudentList **headRef);
// void MultiSort(InternationalStudentList **headRef);
void MergeSortAll(StudentList **headRef);
StudentList *SortedMergeAll(StudentList *stu1, StudentList *stu2);

// Single Sort functions
void MergeSortDom(DomesticStudentList **headRef, char type);
DomesticStudentList *SortedMergeDom(DomesticStudentList *stu1, DomesticStudentList *stu2, char type);
void FrontBackSplitDom(DomesticStudentList *source,
                       DomesticStudentList **frontRef, DomesticStudentList **backRef);

void MergeSortInt(InternationalStudentList **headRef, char type);
InternationalStudentList *SortedMergeInt(InternationalStudentList *stu1, InternationalStudentList *stu2, char type);
void FrontBackSplitInt(InternationalStudentList *source,
                       InternationalStudentList **frontRef, InternationalStudentList **backRef);

void MergeSortAll(StudentList **headRef, char type);
StudentList *SortedMergeAll(StudentList *stu1, StudentList *stu2, char type);
void FrontBackSplitAll(StudentList *source,
                       StudentList **frontRef, StudentList **backRef);

#endif