// student.cpp to implement your classes
#include "student.hpp"
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std; // use namespace std
// -------------------------------------- Student Class -------------------------------------- //
int Student::StudentUIDcounter = 20210000;
// Student class constructor
Student::Student()
{
    setFirstName("");
    setLastName("");
    setType("");
    setCGPA(0.0);
    setResearchScore(0);
    UID = StudentUIDcounter++;
}

Student::Student(string FirstNameValue, string LastNameValue, string TypeValue, float CGPAValue, int researchScoreValue)
{
    setFirstName(FirstNameValue);
    setLastName(FirstNameValue);
    setType(TypeValue);
    setCGPA(CGPAValue);
    setResearchScore(researchScoreValue);
    UID = StudentUIDcounter++;
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
int compareCGPA(const Student stu1, const Student stu2)
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
int compareResearchScore(const Student stu1, const Student stu2)
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
int compareFirstName(const Student stu1, const Student stu2)
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
int compareLastName(const Student stu1, const Student stu2)
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
int compareType(const Student stu1, const Student stu2)
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
