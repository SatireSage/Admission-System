// header file student.hpp to declare your classes
#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>    //you will have to use string in C++
using namespace std; // use namespace std

// Main Student class
class Student
{
private:
    // Student class private memeber variables
    string firstName, lastName, type;
    float CGPA;
    int RScore, UID;

public:
    // int UID;
    static int StudentUIDcounter;

    //  Studnet class constructor
    Student();
    Student(string FirstNameValue, string LastNameValue, string TypeValue, float CGPAValue, int researchScoreValue);

    // Student class get functions
    string getFirstName() const;
    string getLastName() const;
    string getType() const;
    float getCGPA() const;
    int getResearchScore() const;
    int getUID() const;

    // Student class set functions
    void setFirstName(string firstNameValue);
    void setLastName(string lastNameValue);
    void setType(string typeValue);
    void setCGPA(float cgpaValue);
    void setResearchScore(int researchScoreValue);
    void setUID();

    // Student class friend functions
    friend int compareCGPA(Student stu1, Student stu2);
    friend int compareResearchScore(Student stu1, Student stu2);
    friend int compareFirstName(Student stu1, Student stu2);
    friend int compareLastName(Student stu1, Student stu2);
    friend int compareType(Student stu1, Student stu2);
    friend ostream &operator<<(ostream &outs, const Student &stuObj);
};

#endif