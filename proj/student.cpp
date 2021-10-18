// student.cpp to implement your classes
#include "student.hpp"
#include <iomanip>
using namespace std; // use namespace std
// -------------------------------------- Student Class -------------------------------------- //

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

int Student::getUID() const
{
    return UID;
}

// Student class Set-functions
void Student::setFirstName(string firstNameValue)
{
    firstName = firstNameValue;
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

void Student::setUID(int UIDValue)
{
    UID = 20210000 + UIDValue;
}

// Student class friend functions
int compareCGPA(Student stu1, Student stu2)
{
    if (stu1.getCGPA() > stu2.getCGPA())
    {
        return stu1.getCGPA() > stu2.getCGPA();
    }
    if (stu1.getCGPA() < stu2.getCGPA())
    {
        return stu1.getCGPA() < stu2.getCGPA();
    }
    else
    {
        return stu1.getCGPA() == stu2.getCGPA();
    }
}

int compareResearchScore(Student stu1, Student stu2)
{
    if (stu1.getResearchScore() > stu2.getResearchScore())
    {
        return stu1.getResearchScore() > stu2.getResearchScore();
    }
    if (stu1.getResearchScore() < stu2.getResearchScore())
    {
        return stu1.getResearchScore() < stu2.getResearchScore();
    }
    else
    {
        return stu1.getResearchScore() == stu2.getResearchScore();
    }
}

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

// -------------------------------------- End Student Class -------------------------------------- //
// -------------------------------------- Domestic Class -------------------------------------- //

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
    outs << setw(12) << left << stuObj.getUID();
    outs << setw(14) << left << stuObj.getFirstName() << " " << setw(18) << left << stuObj.getLastName();
    outs << setw(10) << left << stuObj.getProvince();
    outs << setw(6) << left << stuObj.getCGPA();
    outs << setw(4) << left << stuObj.getResearchScore() << endl;
    return outs;
}

// -------------------------------------- End Domestic Class -------------------------------------- //
// -------------------------------------- International Class -------------------------------------- //

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

ToeflScore International::getToeflScore() const
{
    ToeflScore toefl;
    toefl.setReading(toeflScore.getReading());
    toefl.setListening(toeflScore.getListening());
    toefl.setSpeaking(toeflScore.getSpeaking());
    toefl.setWriting(toeflScore.getWriting());
    return toefl;
}

int International::getReading() const
{
    return toeflScore.getReading();
}

int International::getListening() const
{
    return toeflScore.getListening();
}

int International::getSpeaking() const
{
    return toeflScore.getSpeaking();
}

int International::getWriting() const
{
    return toeflScore.getWriting();
}

int International::getTotalScore() const
{
    return toeflScore.getTotalScore();
}

// International class set-functions
void International::setCountry(string countryValue)
{
    Country = countryValue;
}

void International::setToeflScore(int reading, int listening, int speaking, int writing)
{
    toeflScore.setReading(reading);
    toeflScore.setListening(listening);
    toeflScore.setSpeaking(speaking);
    toeflScore.setWriting(writing);
}

void International::setToeflScore(ToeflScore score)
{
    toeflScore.setReading(score.getReading());
    toeflScore.setListening(score.getListening());
    toeflScore.setSpeaking(score.getSpeaking());
    toeflScore.setWriting(score.getWriting());
}

void International::setReading(int reading)
{
    toeflScore.setReading(reading);
}

void International::setListening(int listening)
{
    toeflScore.setListening(listening);
}

void International::setSpeaking(int speaking)
{
    toeflScore.setSpeaking(speaking);
}

void International::setWriting(int writing)
{
    toeflScore.setWriting(writing);
}

// Overload operator
ostream &operator<<(ostream &outs, const International &stuObj)
{
    outs << setw(12) << left << stuObj.getUID();
    outs << setw(14) << left << stuObj.getFirstName() << " " << setw(18) << left << stuObj.getLastName();
    outs << setw(10) << left << stuObj.getCountry();
    outs << setw(6) << left << stuObj.getCGPA();
    outs << setw(4) << left << stuObj.getResearchScore();
    outs << setw(4) << left << stuObj.getReading();
    outs << setw(4) << left << stuObj.getListening();
    outs << setw(4) << left << stuObj.getSpeaking();
    outs << setw(4) << left << stuObj.getWriting();
    outs << stuObj.getTotalScore() << endl;
    return outs;
}

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

// -------------------------------------- End ToeflScore Class -------------------------------------- //