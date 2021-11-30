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
    bool inList(DomesticStudentList *Stu, string FirstName, string LastName);

public:
    Domestic domesticStudent;
    DomesticStudentList *next, *head, *tail;

    virtual void threshold(DomesticStudentList *Stu, float CGPA_VALUE, int researchScore_VALUE);
    virtual void threshold(DomesticStudentList *Stu, float CGPA_VALUE);
    virtual void threshold(DomesticStudentList *Stu, int researchScore_VALUE);

    void deleteDom(DomesticStudentList **headNode, string FirstName, string LastName);
    void appendDom(DomesticStudentList **headNode, Domestic new_data);
    void printDom(DomesticStudentList *node);
    void deleteDomHD(DomesticStudentList **headNode);
    void updateDomHD(DomesticStudentList **headNode);
    void deleteList(DomesticStudentList **headNode);
};

#endif