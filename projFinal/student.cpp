// student.cpp to implement your classes
#include "student.hpp"
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std; // use namespace std
// -------------------------------------- Student Class -------------------------------------- //

// Student class constructor
Student::Student()
{
    setFirstName("");
    setLastName("");
    setType("");
    setCGPA(0.0);
    setResearchScore(0);
    setUID(0);
}

// Student class get-functions
string Student::getFirstName() const { return firstName; }

string Student::getLastName() const { return lastName; }

string Student::getType() const { return type; }

float Student::getCGPA() const { return CGPA; }

int Student::getResearchScore() const { return RScore; }

int Student::getUID() const { return UID; }

// Student class Set-functions
void Student::setFirstName(string firstNameValue) { firstName = firstNameValue; }

void Student::setLastName(string lastNameValue) { lastName = lastNameValue; }

void Student::setType(string typeValue) { type = typeValue; }

void Student::setCGPA(float cgpaValue) { CGPA = cgpaValue; }

void Student::setResearchScore(int researchScoreValue) { RScore = researchScoreValue; }

void Student::setUID(int UIDValue) { UID = 20210000 + UIDValue - 1; }

// Student class friend functions
// Overload operator
ostream &operator<<(ostream &outs, const Student &stuObj)
{
    outs << setw(12) << left << stuObj.getUID();
    outs << setw(14) << left << stuObj.getFirstName() << " " << setw(17) << left << stuObj.getLastName();
    outs << setw(10) << left << stuObj.getCGPA();
    outs << setw(6) << left << stuObj.getResearchScore();
    outs << setw(2) << left << stuObj.getType() << endl;
    return outs;
}
// compares CGPA of students
int compareCGPA(Student stu1, Student stu2)
{
    if (stu1.getCGPA() < stu2.getCGPA())
    {
        return 1;
    }
    if (stu1.getCGPA() > stu2.getCGPA())
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
// compares RS of students
int compareResearchScore(Student stu1, Student stu2)
{
    if (stu1.getResearchScore() < stu2.getResearchScore())
    {
        return 1;
    }
    if (stu1.getResearchScore() > stu2.getResearchScore())
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
// compares first names of students alphabetically
int compareFirstName(Student stu1, Student stu2)
{
    string student1 = stu1.getFirstName();
    string student2 = stu2.getFirstName();
    for (int i = 0; i < student1.size(); i++)
        if (student1[i] >= 'a' && student1[i] <= 'z')
            student1[i] -= ('a' - 'A');
    for (int i = 0; i < student2.size(); i++)
        if (student2[i] >= 'a' && student2[i] <= 'z')
            student2[i] -= ('a' - 'A');
    return student1.compare(student2);
}
// compares last names of students alphabetically
int compareLastName(Student stu1, Student stu2)
{
    string student1 = stu1.getLastName();
    string student2 = stu2.getLastName();
    for (int i = 0; i < student1.size(); i++)
        if (student1[i] >= 'a' && student1[i] <= 'z')
            student1[i] -= ('a' - 'A');
    for (int i = 0; i < student2.size(); i++)
        if (student2[i] >= 'a' && student2[i] <= 'z')
            student2[i] -= ('a' - 'A');
    return student1.compare(student2);
}

// compares the type of students
int compareType(Student stu1, Student stu2)
{
    if (stu1.getType() == "International" && stu2.getType() == "Domestic")
    {
        return 1;
    }
    if (stu1.getType() == "Domestic" && stu2.getType() == "International")
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

// -------------------------------------- End Student Class -------------------------------------- //
// -------------------------------------- Domestic Class -------------------------------------- //



// -------------------------------------- End Domestic Class -------------------------------------- //
// -------------------------------------- International Class -------------------------------------- //



// -------------------------------------- End International Class -------------------------------------- //
// -------------------------------------- ToeflScore Class -------------------------------------- //

// ToeflScore class constructor
ToeflScore::ToeflScore()
{
    setReading(0);
    setListening(0);
    setSpeaking(0);
    setWriting(0);
}

// ToeflScore class get-functions
int ToeflScore::getReading() const
{
    return reading;
}

int ToeflScore::getListening() const
{
    return listening;
}

int ToeflScore::getSpeaking() const
{
    return speaking;
}

int ToeflScore::getWriting() const
{
    return writing;
}

int ToeflScore::getTotalScore() const
{
    return cummulative;
}

// ToeflScore class set-functions
void ToeflScore::setReading(int readingScore)
{
    reading = readingScore;
}

void ToeflScore::setListening(int listeningScore)
{
    listening = listeningScore;
}

void ToeflScore::setSpeaking(int speakingScore)
{
    speaking = speakingScore;
}

void ToeflScore::setWriting(int writingScore)
{
    writing = writingScore;
}

void ToeflScore::setTotalScore(int totalScore)
{
    cummulative = totalScore;
}

// -------------------------------------- End ToeflScore Class -------------------------------------- //
// -------------------------------------- Domestic Student Linked List Class -------------------------------------- //


