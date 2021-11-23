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
    //  Studnet class constructor
    Student();

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
    void setUID(int UIDValue);
    // each student should have an 8-digit unique application id with int type, starting with 20210000.
    // We assume there are less than 10,000 applicants in our system.

    // Student class friend functions
    friend int compareCGPA(Student stu1, Student stu2);
    friend int compareResearchScore(Student stu1, Student stu2);
    friend int compareFirstName(Student stu1, Student stu2);
    friend int compareLastName(Student stu1, Student stu2);
    friend int compareType(Student stu1, Student stu2);
    friend ostream &operator<<(ostream &outs, const Student &stuObj);

    // virtual void threshold(StudentList *Stu, float CGPA_VALUE, int researchScore_VALUE); *using this one :) moo

    // virtual void threshold(StudentList *Stu, float CGPA_VALUE);
    // virtual void threshold(StudentList *Stu, int researchScore_VALUE);
};



// TOEFL class for international students
class ToeflScore
{
private:
    // ToeflScore class private memeber variables
    int reading, listening, speaking, writing, cummulative;

public:
    // ToeflScore class constructor
    ToeflScore();

    // ToeflScore class get function
    int getReading() const;
    int getListening() const;
    int getSpeaking() const;
    int getWriting() const;
    int getTotalScore() const;

    // ToeflScore class set function
    void setReading(int readingScore);
    void setListening(int listeningScore);
    void setSpeaking(int speakingScore);
    void setWriting(int writingScore);
    void setTotalScore(int totalScore);
};





#endif