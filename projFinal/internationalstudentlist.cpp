// internationalstudentlist.cpp to implement your classes
#include "internationalstudentlist.hpp"
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std; // use namespace std

void InternationalStudentList::deleteInt(InternationalStudentList **head_ref, string FirstName, string LastName)
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

void InternationalStudentList::appendInt(InternationalStudentList **root, International item)
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

void IntFindCGPA(InternationalStudentList *Stu, float CGPA_VALUE)
{
    float storeCGPA;
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

void InternationalStudentList::printInt(InternationalStudentList *node)
{
    while (node != NULL)
    {
        cout << " " << node->internationalStudent;
        node = node->next;
    }
}

void InternationalStudentList::deleteIntHD(InternationalStudentList **head_ref)
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

void InternationalStudentList::updateIntHD(InternationalStudentList **head_ref)
{
    InternationalStudentList *temp = *head_ref;
    (*head_ref)->head = temp;
    InternationalStudentList *last = *head_ref;
    while (last->next != NULL)
        last = last->next;
    (*head_ref)->tail = last;
}