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
    setCGPA(0.0);
    setResearchScore(0);
    setUID(0);
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
    UID = 20210000 + UIDValue - 1;
}

// Student class friend functions
// Overload operator
ostream &operator<<(ostream &outs, const Student &stuObj)
{
    outs << setw(12) << left << stuObj.getUID();
    outs << setw(14) << left << stuObj.getFirstName() << " " << setw(17) << left << stuObj.getLastName();
    outs << setw(10) << left << stuObj.getCGPA();
    outs << setw(6) << left << stuObj.getResearchScore() << endl;
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

void deleteDom(DomesticStudentList **head_ref, string FirstName, string LastName)
{
    DomesticStudentList *temp = *head_ref;
    DomesticStudentList *prev = NULL;

    if (temp != NULL && temp->domesticStudent.getFirstName() == FirstName && temp->domesticStudent.getLastName() == LastName)
    {
        *head_ref = temp->next; // Changed head
        delete temp;            // free old head

        DomesticStudentList *second_last = *head_ref;
        while (second_last->next != NULL)
            second_last = second_last->next;
        (*head_ref)->head = second_last->head;
        (*head_ref)->tail = second_last;
        return;
    }

    else
    {
        while (temp != NULL && temp->domesticStudent.getFirstName() != FirstName && temp->domesticStudent.getLastName() != LastName)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
            return;

        prev->next = temp->next;
        delete temp;
        DomesticStudentList *second_last = *head_ref;
        while (second_last->next != NULL)
            second_last = second_last->next;
        (*head_ref)->head = temp->head;
        (*head_ref)->tail = second_last;
    }
}

void appendDom(DomesticStudentList **root, Domestic item)
{
    DomesticStudentList *temp = new DomesticStudentList;
    DomesticStudentList *current;
    temp->domesticStudent = item;
    temp->next = NULL;
    temp->head = NULL;
    temp->tail = NULL;

    if (*root == NULL)
    {
        temp->head = temp;
        temp->tail = temp;
        *root = temp;
    }
    else
    {
        current = *root;
        while (current->next != NULL)
            current = current->next;
        temp->head = current->head;
        temp->tail = temp;
        (*root)->tail = temp;
        current->next = temp;
        current->tail = current->next;
    }
}

void DomFindName(DomesticStudentList *Stu, string FirstName, string LastName)
{
    string string1, string2;
    DomesticStudentList *current;
    vector<Domestic> storeDom;

    if (Stu == nullptr)
    {
        cout << "\n Does not exist.";
    }
    else
    {
        current = Stu;
        while (current != NULL)
        {
            string1 = current->domesticStudent.getFirstName();
            string2 = current->domesticStudent.getLastName();
            for (int i = 0; i < string1.size(); i++)
                if (string1[i] >= 'a' && string1[i] <= 'z')
                    string1[i] -= ('a' - 'A');
            for (int i = 0; i < FirstName.size(); i++)
                if (FirstName[i] >= 'a' && FirstName[i] <= 'z')
                    FirstName[i] -= ('a' - 'A');
            for (int i = 0; i < string2.size(); i++)
                if (string2[i] >= 'a' && string2[i] <= 'z')
                    string2[i] -= ('a' - 'A');
            for (int i = 0; i < LastName.size(); i++)
                if (LastName[i] >= 'a' && LastName[i] <= 'z')
                    LastName[i] -= ('a' - 'A');
            int comparatorFirstName = FirstName.compare(string1);
            int comparatorLastName = LastName.compare(string2);
            if ((comparatorFirstName == 0) && (comparatorLastName == 0))
            {
                storeDom.push_back(current->domesticStudent);
            }
            current = current->next;
        }
    }

    if (storeDom.size() == 0)
        cout << "No such student found." << endl;

    for (int i = 0; i < storeDom.size(); i++)
        cout << storeDom.at(i) << ' ';
}

void DomFindCGPA(DomesticStudentList *Stu, int CGPA_VALUE)
{
    int storeCGPA;
    DomesticStudentList *current;
    vector<Domestic> storeDom;

    if (Stu == nullptr)
    {
        cout << "\n Does not exist.";
    }
    else
    {
        current = Stu;
        while (current != NULL)
        {
            storeCGPA = current->domesticStudent.getCGPA();
            if (storeCGPA == CGPA_VALUE)
            {
                storeDom.push_back(current->domesticStudent);
            }
            current = current->next;
        }
    }

    if (storeDom.size() == 0)
        cout << "No such student found." << endl;

    for (int i = 0; i < storeDom.size(); i++)
        cout << storeDom.at(i) << ' ';
}

void DomFindResearchScore(DomesticStudentList *Stu, int researchScore_VALUE)
{
    int storeRScore;
    DomesticStudentList *current;
    vector<Domestic> storeDom;

    if (Stu == nullptr)
    {
        cout << "\n Does not exist.";
    }
    else
    {
        current = Stu;
        while (current != NULL)
        {
            storeRScore = current->domesticStudent.getResearchScore();
            if (storeRScore == researchScore_VALUE)
            {
                storeDom.push_back(current->domesticStudent);
            }
            current = current->next;
        }
    }

    if (storeDom.size() == 0)
        cout << "No such student found." << endl;

    for (int i = 0; i < storeDom.size(); i++)
        cout << storeDom.at(i) << ' ';
}

void DomFindUID(DomesticStudentList *Stu, int UIDValue)
{
    int storeID;
    DomesticStudentList *current;
    vector<Domestic> storeDom;

    if (Stu == nullptr)
    {
        cout << "\n Does not exist.";
    }
    else
    {
        current = Stu;
        while (current != NULL)
        {
            storeID = current->domesticStudent.getUID();
            if (storeID == UIDValue)
            {
                storeDom.push_back(current->domesticStudent);
            }
            current = current->next;
        }
    }

    if (storeDom.size() == 0)
        cout << "No such student found." << endl;

    for (int i = 0; i < storeDom.size(); i++)
        cout << storeDom.at(i) << ' ';
}

void printDom(DomesticStudentList *node)
{
    while (node != NULL)
    {
        cout << " " << node->domesticStudent;
        node = node->next;
    }
}

void deleteDomHD(DomesticStudentList **head_ref)
{
    if (head_ref == NULL)
        return;

    deleteDom(&(*head_ref), (*head_ref)->domesticStudent.getFirstName(), (*head_ref)->domesticStudent.getLastName());

    DomesticStudentList *second_last = *head_ref;
    while (second_last->next->next != NULL)
        second_last = second_last->next;

    delete (*head_ref)->tail;
    (*head_ref)->tail = second_last;
    (*head_ref)->tail->next = NULL;
}

void updateDomHD(DomesticStudentList **head_ref)
{
    DomesticStudentList *temp = *head_ref;
    cout << endl
         << "CHECK HEAD: " << temp->domesticStudent << endl;
    (*head_ref)->head = temp;
    DomesticStudentList *last = *head_ref;
    while (last->next != NULL)
        last = last->next;
    (*head_ref)->tail = last;
}
// -------------------------------------- End Domestic Student Linked List Class -------------------------------------- //
// -------------------------------------- International Student Linked List Class -------------------------------------- //

void deleteInt(InternationalStudentList **head_ref, string FirstName, string LastName)
{
    InternationalStudentList *temp = *head_ref;
    InternationalStudentList *prev = NULL;

    if (temp != NULL && temp->internationalStudent.getFirstName() == FirstName && temp->internationalStudent.getLastName() == LastName)
    {
        *head_ref = temp->next; // Changed head
        delete temp;            // free old head

        InternationalStudentList *second_last = *head_ref;
        while (second_last->next != NULL)
            second_last = second_last->next;
        (*head_ref)->head = second_last->head;
        (*head_ref)->tail = second_last;
        return;
    }

    else
    {
        while (temp != NULL && temp->internationalStudent.getFirstName() != FirstName && temp->internationalStudent.getLastName() != LastName)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
            return;

        prev->next = temp->next;
        delete temp;
        InternationalStudentList *second_last = *head_ref;
        while (second_last->next != NULL)
            second_last = second_last->next;
        (*head_ref)->head = temp->head;
        (*head_ref)->tail = second_last;
    }
}

void appendInt(InternationalStudentList **root, International item)
{
    InternationalStudentList *temp = new InternationalStudentList;
    InternationalStudentList *current;
    temp->internationalStudent = item;
    temp->next = NULL;
    temp->head = NULL;
    temp->tail = NULL;

    if (*root == NULL)
    {
        temp->head = temp;
        temp->tail = temp;
        *root = temp;
    }
    else
    {
        current = *root;
        while (current->next != NULL)
            current = current->next;
        temp->head = current->head;
        temp->tail = temp;
        (*root)->tail = temp;
        current->next = temp;
        current->tail = current->next;
    }
}

void IntFindName(InternationalStudentList *Stu, string FirstName, string LastName)
{
    string string1, string2;
    InternationalStudentList *current;
    vector<International> storeInt;

    if (Stu == nullptr)
    {
        cout << "\n Does not exist.";
    }
    else
    {
        current = Stu;
        while (current != NULL)
        {
            string1 = current->internationalStudent.getFirstName();
            string2 = current->internationalStudent.getLastName();
            for (int i = 0; i < string1.size(); i++)
                if (string1[i] >= 'a' && string1[i] <= 'z')
                    string1[i] -= ('a' - 'A');
            for (int i = 0; i < FirstName.size(); i++)
                if (FirstName[i] >= 'a' && FirstName[i] <= 'z')
                    FirstName[i] -= ('a' - 'A');
            for (int i = 0; i < string2.size(); i++)
                if (string2[i] >= 'a' && string2[i] <= 'z')
                    string2[i] -= ('a' - 'A');
            for (int i = 0; i < LastName.size(); i++)
                if (LastName[i] >= 'a' && LastName[i] <= 'z')
                    LastName[i] -= ('a' - 'A');
            int comparatorFirstName = FirstName.compare(string1);
            int comparatorLastName = LastName.compare(string2);
            if ((comparatorFirstName == 0) && (comparatorLastName == 0))
            {
                storeInt.push_back(current->internationalStudent);
            }
            current = current->next;
        }
    }

    if (storeInt.size() == 0)
        cout << "No such student found." << endl;

    for (int i = 0; i < storeInt.size(); i++)
        cout << storeInt.at(i) << ' ';
}

void IntFindCGPA(InternationalStudentList *Stu, int CGPA_VALUE)
{
    int storeCGPA;
    InternationalStudentList *current;
    vector<International> storeInt;

    if (Stu == nullptr)
    {
        cout << "\n Does not exist.";
    }
    else
    {
        current = Stu;
        while (current != NULL)
        {
            storeCGPA = current->internationalStudent.getCGPA();
            if (storeCGPA == CGPA_VALUE)
            {
                storeInt.push_back(current->internationalStudent);
            }
            current = current->next;
        }
    }

    if (storeInt.size() == 0)
        cout << "No such student found." << endl;

    for (int i = 0; i < storeInt.size(); i++)
        cout << storeInt.at(i) << ' ';
}

void IntFindResearchScore(InternationalStudentList *Stu, int researchScore_VALUE)
{
    int storeRScore;
    InternationalStudentList *current;
    vector<International> storeInt;

    if (Stu == nullptr)
    {
        cout << "\n Does not exist.";
    }
    else
    {
        current = Stu;
        while (current != NULL)
        {
            storeRScore = current->internationalStudent.getResearchScore();
            if (storeRScore == researchScore_VALUE)
            {
                storeInt.push_back(current->internationalStudent);
            }
            current = current->next;
        }
    }

    if (storeInt.size() == 0)
        cout << "No such student found." << endl;

    for (int i = 0; i < storeInt.size(); i++)
        cout << storeInt.at(i) << ' ';
}

void IntFindUID(InternationalStudentList *Stu, int UIDValue)
{
    int storeID;
    InternationalStudentList *current;
    vector<International> storeInt;

    if (Stu == nullptr)
    {
        cout << "\n Does not exist.";
    }
    else
    {
        current = Stu;
        while (current != NULL)
        {
            storeID = current->internationalStudent.getUID();
            if (storeID == UIDValue)
            {
                storeInt.push_back(current->internationalStudent);
            }
            current = current->next;
        }
    }

    if (storeInt.size() == 0)
        cout << "No such student found." << endl;

    for (int i = 0; i < storeInt.size(); i++)
        cout << storeInt.at(i) << ' ';
}

void printInt(InternationalStudentList *node)
{
    while (node != NULL)
    {
        cout << " " << node->internationalStudent;
        node = node->next;
    }
}

void deleteIntHD(InternationalStudentList **head_ref)
{
    if (head_ref == NULL)
        return;

    deleteInt(&(*head_ref), (*head_ref)->internationalStudent.getFirstName(), (*head_ref)->internationalStudent.getLastName());

    InternationalStudentList *second_last = *head_ref;
    while (second_last->next->next != NULL)
        second_last = second_last->next;

    delete (*head_ref)->tail;
    (*head_ref)->tail = second_last;
    (*head_ref)->tail->next = NULL;
}

void updateIntHD(InternationalStudentList **head_ref)
{
    InternationalStudentList *temp = *head_ref;
    cout << endl
         << "CHECK HEAD: " << temp->internationalStudent << endl;
    (*head_ref)->head = temp;
    InternationalStudentList *last = *head_ref;
    while (last->next != NULL)
        last = last->next;
    (*head_ref)->tail = last;
}
// -------------------------------------- End International Student Linked List Class -------------------------------------- //
// -------------------------------------- Merged Student Linked List Class -------------------------------------- //
void deleteMerge(StudentList **head_ref, string FirstName, string LastName)
{
    StudentList *temp = *head_ref;
    StudentList *prev = NULL;

    if (temp != NULL && temp->Students.getFirstName() == FirstName && temp->Students.getLastName() == LastName)
    {
        *head_ref = temp->next; // Changed head
        delete temp;            // free old head

        StudentList *second_last = *head_ref;
        while (second_last->next != NULL)
            second_last = second_last->next;
        (*head_ref)->head = second_last->head;
        (*head_ref)->tail = second_last;
        return;
    }

    else
    {
        while (temp != NULL && temp->Students.getFirstName() != FirstName && temp->Students.getLastName() != LastName)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
            return;

        prev->next = temp->next;
        delete temp;
        StudentList *second_last = *head_ref;
        while (second_last->next != NULL)
            second_last = second_last->next;
        (*head_ref)->head = second_last->head;
        (*head_ref)->tail = second_last;
    }
}

void appendMerge(StudentList **root, Student item)
{
    StudentList *temp = new StudentList;
    StudentList *current;
    temp->Students = item;
    temp->next = NULL;
    temp->head = NULL;
    temp->tail = NULL;

    if (*root == NULL)
    {
        temp->head = temp;
        temp->tail = temp;
        *root = temp;
    }
    else
    {
        current = *root;
        while (current->next != NULL)
            current = current->next;
        temp->head = current->head;
        temp->tail = temp;
        (*root)->tail = temp;
        current->next = temp;
        current->tail = current->next;
    }
}

void FindName(StudentList *Stu, string FirstName, string LastName)
{
    string string1, string2;
    StudentList *current;
    vector<Student> storeStu;

    if (Stu == nullptr)
    {
        cout << "\n Does not exist.";
    }
    else
    {
        current = Stu;
        while (current != NULL)
        {
            string1 = current->Students.getFirstName();
            string2 = current->Students.getLastName();
            for (int i = 0; i < string1.size(); i++)
                if (string1[i] >= 'a' && string1[i] <= 'z')
                    string1[i] -= ('a' - 'A');
            for (int i = 0; i < FirstName.size(); i++)
                if (FirstName[i] >= 'a' && FirstName[i] <= 'z')
                    FirstName[i] -= ('a' - 'A');
            for (int i = 0; i < string2.size(); i++)
                if (string2[i] >= 'a' && string2[i] <= 'z')
                    string2[i] -= ('a' - 'A');
            for (int i = 0; i < LastName.size(); i++)
                if (LastName[i] >= 'a' && LastName[i] <= 'z')
                    LastName[i] -= ('a' - 'A');
            int comparatorFirstName = FirstName.compare(string1);
            int comparatorLastName = LastName.compare(string2);
            if ((comparatorFirstName == 0) && (comparatorLastName == 0))
            {
                storeStu.push_back(current->Students);
            }
            current = current->next;
        }
    }

    if (storeStu.size() == 0)
        cout << "No such student found." << endl;

    for (int i = 0; i < storeStu.size(); i++)
        cout << storeStu.at(i) << ' ';
}

void FindCGPA(StudentList *Stu, int CGPA_VALUE)
{
    int storeCGPA;
    StudentList *current;
    vector<Student> storeStu;

    if (Stu == nullptr)
    {
        cout << "\n Does not exist.";
    }
    else
    {
        current = Stu;
        while (current != NULL)
        {
            storeCGPA = current->Students.getCGPA();
            if (storeCGPA == CGPA_VALUE)
            {
                storeStu.push_back(current->Students);
            }
            current = current->next;
        }
    }

    if (storeStu.size() == 0)
        cout << "No such student found." << endl;

    for (int i = 0; i < storeStu.size(); i++)
        cout << storeStu.at(i) << ' ';
}

void FindResearchScore(StudentList *Stu, int researchScore_VALUE)
{
    int storeRScore;
    StudentList *current;
    vector<Student> storeStu;

    if (Stu == nullptr)
    {
        cout << "\n Does not exist.";
    }
    else
    {
        current = Stu;
        while (current != NULL)
        {
            storeRScore = current->Students.getResearchScore();
            if (storeRScore == researchScore_VALUE)
            {
                storeStu.push_back(current->Students);
            }
            current = current->next;
        }
    }

    if (storeStu.size() == 0)
        cout << "No such student found." << endl;

    for (int i = 0; i < storeStu.size(); i++)
        cout << storeStu.at(i) << ' ';
}

void FindUID(StudentList *Stu, int UIDValue)
{
    int storeID;
    StudentList *current;
    vector<Student> storeStu;

    if (Stu == nullptr)
    {
        cout << "\n Does not exist.";
    }
    else
    {
        current = Stu;
        while (current != NULL)
        {
            storeID = current->Students.getUID();
            if (storeID == UIDValue)
            {
                storeStu.push_back(current->Students);
            }
            current = current->next;
        }
    }

    if (storeStu.size() == 0)
        cout << "No such student found." << endl;

    for (int i = 0; i < storeStu.size(); i++)
        cout << storeStu.at(i) << ' ';
}

void printMerge(StudentList *node)
{
    while (node != NULL)
    {
        cout << " " << node->Students;
        node = node->next;
    }
}

void deleteMergeHD(StudentList **head_ref)
{
    if (head_ref == NULL)
        return;

    deleteMerge(&(*head_ref), (*head_ref)->Students.getFirstName(), (*head_ref)->Students.getLastName());

    StudentList *second_last = *head_ref;
    while (second_last->next->next != NULL)
        second_last = second_last->next;

    delete (*head_ref)->tail;
    (*head_ref)->tail = second_last;
    (*head_ref)->tail->next = NULL;
}

void updateMergeHD(StudentList **head_ref)
{
    StudentList *temp = *head_ref;
    cout << endl
         << "CHECK HEAD: " << temp->Students << endl;
    (*head_ref)->head = temp;
    StudentList *last = *head_ref;
    while (last->next != NULL)
        last = last->next;
    (*head_ref)->tail = last;
}