// header file domesticstudentlist.hpp to declare your classes
#ifndef DOMSTUDENT_HPP
#define DOMSTUDENT_HPP

#include <string>    //you will have to use string in C++
using namespace std; // use namespace std

// Domestic student linked-list class
// class DomesticStudentList : public Domestic
class DomesticStudentList
{
protected:
    void friend DomFindName(DomesticStudentList *Stu, string FirstName, string LastName);
    void friend DomFindCGPA(DomesticStudentList *Stu1, float CGPA_VALUE);
    void friend DomFindResearchScore(DomesticStudentList *Stu1, int researchScore_VALUE);
    void friend DomFindUID(DomesticStudentList *Stu1, int UIDValue);

public:
    Domestic domesticStudent;
    DomesticStudentList *next, *head, *tail;

    void friend deleteDom(DomesticStudentList **head_ref, string FirstName, string LastName);
    void friend appendDom(DomesticStudentList **head_ref, Domestic new_data);
    void friend printDom(DomesticStudentList *node);
    void friend deleteDomHD(DomesticStudentList **head_ref);
    void friend updateDomHD(DomesticStudentList **head_ref);
};

#endif