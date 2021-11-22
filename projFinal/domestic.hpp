// header file domestic.hpp to declare your classes
#ifndef DOMESTIC_HPP
#define DOMESTIC_HPP

#include <string>    //you will have to use string in C++
using namespace std; // use namespace std

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

#endif