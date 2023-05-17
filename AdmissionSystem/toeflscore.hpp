// header file international.hpp to declare your classes
#ifndef TOEFLSCORE_HPP
#define TOEFLSCORE_HPP

#include <string>    //you will have to use string in C++
using namespace std; // use namespace std

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