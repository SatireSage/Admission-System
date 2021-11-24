// international.cpp to implement your classes
#include "international.hpp"
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std; // use namespace std

// International class constructor
International::International()
{
    setCountry("");
}

// Domestic class constructor
International::International(string FirstNameValue, string LastNameValue, string TypeValue, string InternationalValue, float CGPAValue, int researchScoreValue)
{
    setFirstName(FirstNameValue);
    setLastName(FirstNameValue);
    setType(TypeValue);
    setCGPA(CGPAValue);
    setResearchScore(researchScoreValue);
    UID = StudentUIDcounter++;
    setCountry(InternationalValue);
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
// creates total score for international students
void International::setToeflScore(int reading, int listening, int speaking, int writing)
{
    toeflScore.setReading(reading);
    toeflScore.setListening(listening);
    toeflScore.setSpeaking(speaking);
    toeflScore.setWriting(writing);
    int total = 0;
    int readScore = getReading();
    int listenScore = getListening();
    int speakScore = getSpeaking();
    int writeScore = getWriting();
    total = reading + listening + speaking + writing;
    toeflScore.setTotalScore(total);
}

void International::setToeflScore(ToeflScore score)
{
    toeflScore.setReading(score.getReading());
    toeflScore.setListening(score.getListening());
    toeflScore.setSpeaking(score.getSpeaking());
    toeflScore.setWriting(score.getWriting());
    int total = 0;
    int readScore = toeflScore.getReading();
    int listenScore = toeflScore.getListening();
    int speakScore = toeflScore.getSpeaking();
    int writeScore = toeflScore.getWriting();
    total = readScore + listenScore + speakScore + writeScore;
    toeflScore.setTotalScore(total);
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
    outs << setw(14) << left << stuObj.getFirstName() << " " << setw(17) << left << stuObj.getLastName();
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
// compares countries alphabetically
int compareCountry(International stu1, International stu2)
{
    string student1 = stu1.getCountry();
    string student2 = stu2.getCountry();
    for (int i = 0; i < student1.size(); i++)
        if (student1[i] >= 'a' && student1[i] <= 'z')
            student1[i] -= ('a' - 'A');
    for (int i = 0; i < student2.size(); i++)
        if (student2[i] >= 'a' && student2[i] <= 'z')
            student2[i] -= ('a' - 'A');
    return student1.compare(student2);
}