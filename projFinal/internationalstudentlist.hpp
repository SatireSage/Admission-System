// header file internationalstudentlist.hpp to declare your classes
#ifndef INTSTUDENT_HPP
#define INTSTUDENT_HPP

#include <string>    //you will have to use string in C++
using namespace std; // use namespace std

// International student linked-list class
// class InternationalStudentList : public International
class InternationalStudentList
{
protected:
    void friend IntFindName(InternationalStudentList *Stu, string FirstName, string LastName);
    void friend IntFindCGPA(InternationalStudentList *Stu1, float CGPA_VALUE);
    void friend IntFindResearchScore(InternationalStudentList *Stu1, int researchScore_VALUE);
    void friend IntFindUID(InternationalStudentList *Stu1, int UIDValue);

public:
    International internationalStudent;
    InternationalStudentList *next, *head, *tail;

    void friend deleteInt(InternationalStudentList **head_ref, string FirstName, string LastName);
    void friend appendInt(InternationalStudentList **head_ref, International new_data);
    void friend printInt(InternationalStudentList *node);
    void friend deleteIntHD(InternationalStudentList **head_ref);
    void friend updateIntHD(InternationalStudentList **head_ref);
};

#endif