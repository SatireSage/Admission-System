// student.cpp to implement your classes
#include "student.hpp"
#include <iomanip>

// ****************** Student Class ****************** //
// Student class constructor
Student::Student()
{
    setFirstName("");
    setLastName("");
    setCGPA(0.0);
    setResearchScore(0);
}

// Student class get-functions
string Student::getFirstName() const
{
    return firstName;
}

string Student::getLastName() const
{
    return lastName;
}

float Student::getCGPA() const
{
    return CGPA;
}

int Student::getResearchScore() const
{
    return RScore;
}

// Student class Set-functions
void Student::setLastName(string firstNameValue)
{
    lastName = firstNameValue;
}

void Student::setLastName(string lastNameValue)
{
    lastName = lastNameValue;
}

void Student::setCGPA(float cgpaValue)
{
    CGPA = cgpaValue;
}

void Student::setResearchScore(int researchScoreValue)
{
    RScore = researchScoreValue;
}

// Student class friend functions
//  int compareCGPA(Student stu1, Student stu2)
//  {
// compare Here
//  }

// int compareResearchScore(Student stu1, Student stu2)
// {
// compare Here
// }

// int compareFirstName(Student stu1, Student stu2)
// {
// compare Here
// }

// int compareLastName(Student stu1, Student stu2)
// {
// compare Here
// }
// ****************** End Student Class ****************** //

// ****************** Domestic Class ****************** //
// Domestic class constructor
Domestic::Domestic()
{
    setProvince("");
}

// Domestic class get-functions
string Domestic::getProvince() const
{
    return Province;
}

// Domestic class set-functions
void Domestic::setProvince(string ProvinceName)
{
    Province = ProvinceName;
}

// Overload operator
ostream &operator<<(ostream &outs, const Domestic &stuObj)
{
    outs << setw(14) << left << stuObj.getFirstName() << " " << setw(18) << left << stuObj.getLastName();
    outs << setw(10) << left << stuObj.getProvince();
    outs << setw(6) << left << stuObj.getCGPA();
    outs << setw(4) << left << stuObj.getResearchScore() << endl;
    return outs;
}
// ****************** End Domestic Class ****************** //

// ****************** International Class ****************** //
// International class constructor
International::International()
{
    setCountry("");
}

// International class get-functions
string International::getCountry() const
{
    return Country;
}

// International class set-functions
void International::setCountry(string countryValue)
{
    Country = countryValue;
}

// Overload operator
ostream &operator<<(ostream &outs, const International &stuObj)
{
    outs << setw(14) << left << stuObj.getFirstName() << " " << setw(18) << left << stuObj.getLastName();
    outs << setw(10) << left << stuObj.getCountry() << endl;
    return outs;
}
// ****************** End International Class ****************** //

// ****************** ToeflScore Class ****************** //
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

void ToeflScore::setTotalScore()
{
    int total = 0;
    int readScore = getReading();
    int listenScore = getListening();
    int speakScore = getSpeaking();
    int writeScore = getWriting();
    total = readScore + listenScore + speakScore + writeScore;
    cummulative = total;
}
// ****************** End ToeflScore Class ****************** //