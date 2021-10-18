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
    friend istream &operator>>(istream &ins, Domestic &stuObj);
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
    void setTotalScore();
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
    friend istream &operator>>(istream &ins, International &stuObj);
};

#endif