// header file studentlist.hpp to declare your classes
#ifndef STUDENTLIST_HPP
#define STUDENTLIST_HPP

#include <string> //you will have to use string in C++
#include "student.hpp"
#include "domesticstudentlist.hpp"
#include "internationalstudentlist.hpp"
using namespace std; // use namespace std

// Merged student linked-list class
// class StudentList : public Student
class StudentList : public Student, public DomesticStudentList, public InternationalStudentList
{
protected:
    friend void FindName(StudentList *Stu, string FirstName, string LastName);
    friend void FindCGPA(StudentList *Stu1, float CGPA_VALUE);
    friend void FindResearchScore(StudentList *Stu1, int researchScore_VALUE);
    friend void FindUID(StudentList *Stu1, int UIDValue);

public:
    Student Students;
    StudentList *next, *head, *tail;

    void threshold(StudentList *Stu, float CGPA_VALUE, int researchScore_VALUE);
    void threshold(StudentList *Stu, float CGPA_VALUE);
    void threshold(StudentList *Stu, int researchScore_VALUE);

    void deleteMerge(StudentList **head_ref, string FirstName, string LastName);
    void appendMerge(StudentList **head_ref, Student new_data);
    void printMerge(StudentList *node);
    void deleteMergeHD(StudentList **head_ref);
    void updateMergeHD(StudentList **head_ref);
    void deleteList(StudentList **head_ref);
};

#endif