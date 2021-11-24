// header file internationalstudentlist.hpp to declare your classes
#ifndef INTSTUDENT_HPP
#define INTSTUDENT_HPP

#include <string> //you will have to use string in C++
#include "international.hpp"
using namespace std; // use namespace std

// International student linked-list class
// class InternationalStudentList : public International
class InternationalStudentList
{
protected:
    friend void IntFindName(InternationalStudentList *Stu, string FirstName, string LastName);
    friend void IntFindCGPA(InternationalStudentList *Stu1, float CGPA_VALUE);
    friend void IntFindResearchScore(InternationalStudentList *Stu1, int researchScore_VALUE);
    friend void IntFindUID(InternationalStudentList *Stu1, int UIDValue);

public:
    International internationalStudent;
    InternationalStudentList *next, *head, *tail;

    void deleteInt(InternationalStudentList **head_ref, string FirstName, string LastName);
    void appendInt(InternationalStudentList **head_ref, International new_data);
    void printInt(InternationalStudentList *node);
    void deleteIntHD(InternationalStudentList **head_ref);
    void updateIntHD(InternationalStudentList **head_ref);
};

#endif