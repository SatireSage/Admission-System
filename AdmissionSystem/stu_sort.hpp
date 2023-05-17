// header file stu_sort.hpp to declare your sorting functions
#ifndef STUSORT_HPP
#define STUSORT_HPP
#include "student.hpp"
#include "domesticstudentlist.hpp"
#include "internationalstudentlist.hpp"
#include "studentlist.hpp"
#include <string> //you will have to use string in C++

// Multi Sort functions
void MergeSortDom(DomesticStudentList **headNode);
DomesticStudentList *SortedMergeDom(DomesticStudentList *stu1, DomesticStudentList *stu2);
void MergeSortInt(InternationalStudentList **headNode);
InternationalStudentList *SortedMergeInt(InternationalStudentList *stu1, InternationalStudentList *stu2);
void MergeSortAll(StudentList **headNode);
StudentList *SortedMergeAll(StudentList *stu1, StudentList *stu2);

// Single Sort functions
void MergeSortDom(DomesticStudentList **headNode, char type);
DomesticStudentList *SortedMergeDom(DomesticStudentList *stu1, DomesticStudentList *stu2, char type);
void MergeSortInt(InternationalStudentList **headNode, char type);
InternationalStudentList *SortedMergeInt(InternationalStudentList *stu1, InternationalStudentList *stu2, char type);
void MergeSortAll(StudentList **headNode, char type);
StudentList *SortedMergeAll(StudentList *stu1, StudentList *stu2, char type);

void FrontBackSplit(DomesticStudentList *source,
                    DomesticStudentList **frontRef, DomesticStudentList **backRef);
void FrontBackSplit(InternationalStudentList *source,
                    InternationalStudentList **frontRef, InternationalStudentList **backRef);
void FrontBackSplit(StudentList *source,
                    StudentList **frontRef, StudentList **backRef);

#endif