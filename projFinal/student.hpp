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

    // virtual void threshold(StudentList *Stu, float CGPA_VALUE, int researchScore_VALUE);
    // virtual void threshold(StudentList *Stu, float CGPA_VALUE);
    // virtual void threshold(StudentList *Stu, int researchScore_VALUE);
};

// Domestic student sub-class
class Domestic : public Student
{
private:
    // Domestic class private memeber variable
    string Province;

public:
    // Domestic class constructor
    Domestic();

    // Domestic class get function
    string getProvince() const;

    // Domestic class set function
    void setProvince(string ProvinceName);

    // Domestic class friend function
    friend ostream &operator<<(ostream &outs, const Domestic &stuObj);
    friend int compareProvince(Domestic stu1, Domestic stu2);
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

// International student sub-class
class International : public Student
{
private:
    // International class private memeber variables
    string Country;
    ToeflScore toeflScore;

public:
    // International class constructor
    International();

    // international class get function
    string getCountry() const;

    ToeflScore getToeflScore() const;

    int getReading() const;
    int getListening() const;
    int getWriting() const;
    int getSpeaking() const;
    int getTotalScore() const;

    // International class set function
    void setCountry(string countryName);

    void setToeflScore(int reading, int listening, int speaking, int writing);
    void setToeflScore(ToeflScore score);

    void setReading(int reading);
    void setListening(int listening);
    void setSpeaking(int speaking);
    void setWriting(int writing);

    // International class friend function
    friend ostream &operator<<(ostream &outs, const International &stuObj);
    friend int compareCountry(International stu1, International stu2);
};

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