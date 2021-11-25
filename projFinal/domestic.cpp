// domestic.cpp to implement your classes
#include "domestic.hpp"
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std; // use namespace std

// Domestic class constructor
Domestic::Domestic()
{
    setProvince("");
}

// Domestic class constructor
Domestic::Domestic(string FirstNameValue, string LastNameValue, string TypeValue, string ProvinceValue, float CGPAValue, int researchScoreValue)
{
    setFirstName(FirstNameValue);
    setLastName(LastNameValue);
    setType(TypeValue);
    setCGPA(CGPAValue);
    setResearchScore(researchScoreValue);
    UID = StudentUIDcounter++;
    setProvince(ProvinceValue);
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
    outs << setw(14) << left << stuObj.getFirstName() << " " << setw(17) << left << stuObj.getLastName();
    outs << setw(10) << left << stuObj.getProvince();
    outs << setw(6) << left << stuObj.getCGPA();
    outs << setw(4) << left << stuObj.getResearchScore() << endl;
    return outs;
}
// compares provinces of domestic students alphabetically
int compareProvince(Domestic stu1, Domestic stu2)
{
    string student1 = stu1.getProvince();
    string student2 = stu2.getProvince();
    for (int i = 0; i < student1.size(); i++)
        if (student1[i] >= 'a' && student1[i] <= 'z')
            student1[i] -= ('a' - 'A');
    for (int i = 0; i < student2.size(); i++)
        if (student2[i] >= 'a' && student2[i] <= 'z')
            student2[i] -= ('a' - 'A');
    return student1.compare(student2);
}