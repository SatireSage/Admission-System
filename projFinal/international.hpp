// header file international.hpp to declare your classes
#ifndef INTERNATIONAL_HPP
#define INTERNATIONAL_HPP

#include <string> //you will have to use string in C++
#include "student.hpp"
#include "toeflscore.hpp"
using namespace std; // use namespace std

// International student sub-class
class International : public Student, public ToeflScore
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

#endif