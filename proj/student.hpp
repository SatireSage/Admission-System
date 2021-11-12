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
    string firstName, lastName;
    float CGPA;
    int RScore, UID;

public:
    //  Studnet class constructor
    Student();

    // Student class get functions
    string getFirstName() const;
    string getLastName() const;
    float getCGPA() const;
    int getResearchScore() const;
    int getUID() const;

    // Student class set functions
    void setFirstName(string firstNameValue);
    void setLastName(string lastNameValue);
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
    friend ostream &operator<<(ostream &outs, const Student &stuObj);
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

// Student node
// class StudentNode
// {
// public:
//     int StuID;
//     StudentNode *head;
//     StudentNode *tail;
// };
// typedef class StudentNode *StuPtr;

// class StudentNodeList
// {
// private:
//     Domestic domesticStudent;
//     International internationalStudent;
//     StuPtr Node;

// protected:
//     StuPtr newNodeDom(Domestic StuObj, StuPtr Stu1);
//     StuPtr newNodeInt(International StuObj, StuPtr Stu1);
//     StuPtr DelNodeDom(Domestic StuObj, StuPtr Stu1);
//     StuPtr DelNodeInt(International StuObj, StuPtr Stu1);

//     string FindName(StuPtr Stu1, StuPtr Stu2);
//     string FindFirstName(StuPtr Stu1, StuPtr Stu2);
//     string FindLastName(StuPtr Stu1, StuPtr Stu2);
//     int FindCGPA(StuPtr Stu1, StuPtr Stu2);
//     int FindResearchScore(StuPtr Stu1, StuPtr Stu2);
//     int FindUID(StuPtr Stu1, StuPtr Stu2);
//     string compareStudentTypes(StuPtr Stu1, StuPtr Stu2);

// public:
//     StudentNodeList();

//     StuPtr newNodeDom(Domestic StuObj);
//     StuPtr newNodeInt(International StuObj);
//     StuPtr DelNodeDom(Domestic StuObj);
//     StuPtr DelNodeInt(International StuObj);
// };

// Domestic student linked-list class
class DomesticStudentList
{
protected:
    //     DomesticStudentList *newNodeDom(Domestic StuObj, DomesticStudentList *Stu1);
    //     DomesticStudentList *DelNodeDom(Domestic StuObj, DomesticStudentList *Stu1);
    //     DomesticStudentList *removeHeadTailNodes(Domestic StuObj, DomesticStudentList *Stu1);

    void friend DomFindName(DomesticStudentList *Stu, string FirstName, string LastName);
    void friend DomFindCGPA(DomesticStudentList *Stu1, int CGPA_VALUE);
    void friend DomFindResearchScore(DomesticStudentList *Stu1, int researchScore_VALUE);
    void friend DomFindUID(DomesticStudentList *Stu1, int UIDValue);
    //     string FindName(DomesticStudentList *Stu1, DomesticStudentList *Stu2, string FirstName, string LastName);
    //     int FindCGPA(DomesticStudentList *Stu1, DomesticStudentList *Stu2, int CGPA_VALUE);
    //     int FindResearchScore(DomesticStudentList *Stu1, DomesticStudentList *Stu2, int researchScore_VALUE);
    //     int FindUID(DomesticStudentList *Stu1, DomesticStudentList *Stu2, int UIDValue);

    //     string FindFirstName(DomesticStudentList *Stu1, DomesticStudentList *Stu2, string FirstName);
    //     string FindLastName(DomesticStudentList *Stu1, DomesticStudentList *Stu2, string LastName);
    //     string compareStudentTypes(DomesticStudentList *Stu1, DomesticStudentList *Stu2);

public:
    Domestic domesticStudent;
    DomesticStudentList *next, *head, *tail;

    void friend pushDom(DomesticStudentList **head_ref, Domestic new_data);
    void friend appendDom(DomesticStudentList **head_ref, Domestic new_data);
    void friend printDom(DomesticStudentList *node);

    // DomesticStudentList *newNodeDom(Domestic StuObj);
    // DomesticStudentList *DelNodeDom(Domestic StuObj);
    // DomesticStudentList *removeHeadTailNodes(Domestic StuObj);
};

// International student linked-list class
class InternationalStudentList
{
    // protected:
    //     InternationalStudentList *newNodeInt(International StuObj, InternationalStudentList *Stu1);
    //     InternationalStudentList *DelNodeInt(International StuObj, InternationalStudentList *Stu1);
    //     InternationalStudentList *removeHeadTailNodes(International StuObj, InternationalStudentList *Stu1);

    //     string FindName(InternationalStudentList *Stu1, InternationalStudentList *Stu2, string FirstName, string LastName);
    //     string FindFirstName(InternationalStudentList *Stu1, InternationalStudentList *Stu2, string FirstName);
    //     string FindLastName(InternationalStudentList *Stu1, InternationalStudentList *Stu2, string LastName);
    //     int FindCGPA(InternationalStudentList *Stu1, InternationalStudentList *Stu2, int CGPA_VALUE);
    //     int FindResearchScore(InternationalStudentList *Stu1, InternationalStudentList *Stu2, int researchScore_VALUE);
    //     int FindUID(InternationalStudentList *Stu1, InternationalStudentList *Stu2, int UIDValue);
    //     string compareStudentTypes(InternationalStudentList *Stu1, InternationalStudentList *Stu2);

public:
    International internationalStudent;
    InternationalStudentList *next;
    InternationalStudentList *head;
    InternationalStudentList *tail;

    // InternationalStudentList();

    void friend pushInt(InternationalStudentList **head_ref, International new_data);
    void friend appendInt(InternationalStudentList **head_ref, International new_data);
    void friend printInt(InternationalStudentList *node);

    // InternationalStudentList *newNodeInt(International StuObj);
    // InternationalStudentList *DelNodeInt(International StuObj);
    // InternationalStudentList *removeHeadTailNodes(International StuObj);
};

// Merged student linked-list class
class StudentList
{
    // protected:
    //     StudentList *newNodeInt(Student StuObj, InternationalStudentList *Stu1);
    //     StudentList *DelNodeInt(Student StuObj, InternationalStudentList *Stu1);
    //     StudentList *removeHeadTailNodes(Student StuObj, InternationalStudentList *Stu1);

    //     string FindName(StudentList *Stu1, StudentList *Stu2, string FirstName, string LastName);
    //     string FindFirstName(StudentList *Stu1, StudentList *Stu2, string FirstName);
    //     string FindLastName(StudentList *Stu1, StudentList *Stu2, string LastName);
    //     int FindCGPA(StudentList *Stu1, StudentList *Stu2, int CGPA_VALUE);
    //     int FindResearchScore(StudentList *Stu1, StudentList *Stu2, int researchScore_VALUE);
    //     int FindUID(StudentList *Stu1, StudentList *Stu2, int UIDValue);
    //     string compareStudentTypes(StudentList *Stu1, StudentList *Stu2);

public:
    Student Students;
    StudentList *next;
    StudentList *head;
    StudentList *tail;

    // StudentList();

    void friend pushMerge(StudentList **head_ref, Student new_data);
    void friend appendMerge(StudentList **head_ref, Student new_data);
    void friend printMerge(StudentList *node);

    // StudentList *newNodeInt(Student StuObj);
    // StudentList *DelNodeInt(Student StuObj);
    // StudentList *removeHeadTailNodes(Student StuObj);
};

#endif