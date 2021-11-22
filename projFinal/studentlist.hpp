// header file studentlist.hpp to declare your classes
#ifndef STUDENTLIST_HPP
#define STUDENTLIST_HPP

#include <string>    //you will have to use string in C++
using namespace std; // use namespace std

// Merged student linked-list class
// class StudentList : public Student
class StudentList
{
protected:
    void friend FindName(StudentList *Stu, string FirstName, string LastName);
    void friend FindCGPA(StudentList *Stu1, float CGPA_VALUE);
    void friend FindResearchScore(StudentList *Stu1, int researchScore_VALUE);
    void friend FindUID(StudentList *Stu1, int UIDValue);
    void friend threshold(StudentList *Stu, float CGPA_VALUE, int researchScore_VALUE);
    void friend threshold(StudentList *Stu, float CGPA_VALUE);
    void friend threshold(StudentList *Stu, int researchScore_VALUE);

public:
    Student Students;
    StudentList *next, *head, *tail;

    void friend deleteMerge(StudentList **head_ref, string FirstName, string LastName);
    void friend appendMerge(StudentList **head_ref, Student new_data);
    void friend printMerge(StudentList *node);
    void friend deleteMergeHD(StudentList **head_ref);
    void friend updateMergeHD(StudentList **head_ref);
};

#endif