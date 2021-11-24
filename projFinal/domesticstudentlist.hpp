// header file domesticstudentlist.hpp to declare your classes
#ifndef DOMSTUDENT_HPP
#define DOMSTUDENT_HPP

#include <string> //you will have to use string in C++
#include "domestic.hpp"
using namespace std; // use namespace std

// Domestic student linked-list class
// class DomesticStudentList : public Domestic
class DomesticStudentList
{
protected:
    friend void DomFindName(DomesticStudentList *Stu, string FirstName, string LastName);
    friend void DomFindCGPA(DomesticStudentList *Stu1, float CGPA_VALUE);
    friend void DomFindResearchScore(DomesticStudentList *Stu1, int researchScore_VALUE);
    friend void DomFindUID(DomesticStudentList *Stu1, int UIDValue);

public:
    Domestic domesticStudent;
    DomesticStudentList *next, *head, *tail;

    void deleteDom(DomesticStudentList **head_ref, string FirstName, string LastName);
    void appendDom(DomesticStudentList **head_ref, Domestic new_data);
    void printDom(DomesticStudentList *node);
    void deleteDomHD(DomesticStudentList **head_ref);
    void updateDomHD(DomesticStudentList **head_ref);
};

#endif