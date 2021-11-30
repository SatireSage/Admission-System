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
    friend string IntFindType(InternationalStudentList *Stu, string FirstName, string LastName);
    bool inList(InternationalStudentList *Stu, string FirstName, string LastName);

public:
    International internationalStudent;
    InternationalStudentList *next, *head, *tail;

    virtual void threshold(InternationalStudentList *Stu, float CGPA_VALUE, int researchScore_VALUE);
    virtual void threshold(InternationalStudentList *Stu, float CGPA_VALUE);
    virtual void threshold(InternationalStudentList *Stu, int researchScore_VALUE);

    void deleteInt(InternationalStudentList **headNode, string FirstName, string LastName);
    void appendInt(InternationalStudentList **headNode, International new_data);
    void printInt(InternationalStudentList *node);
    void deleteIntHD(InternationalStudentList **headNode);
    void updateIntHD(InternationalStudentList **headNode);
    void deleteList(InternationalStudentList **headNode);
};

#endif