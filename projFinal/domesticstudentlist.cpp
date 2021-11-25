// domesticstudentlist.cpp to implement your classes
#include "domesticstudentlist.hpp"
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std; // use namespace std

void DomesticStudentList::deleteDom(DomesticStudentList **head_ref, string FirstName, string LastName)
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

void DomesticStudentList::appendDom(DomesticStudentList **root, Domestic item)
{
    try
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
    catch (bad_alloc)
    {
        std::cout << "Warning: Bad memory allocation!";
        exit(1);
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
        cout << " " << storeDom.at(i);
}

void DomFindCGPA(DomesticStudentList *Stu, float CGPA_VALUE)
{
    float storeCGPA;
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
        cout << " " << storeDom.at(i);
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
        cout << " " << storeDom.at(i);
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
        cout << " " << storeDom.at(i);
}

void DomesticStudentList::printDom(DomesticStudentList *node)
{
    while (node != NULL)
    {
        cout << " " << node->domesticStudent;
        node = node->next;
    }
}

void DomesticStudentList::deleteDomHD(DomesticStudentList **head_ref)
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

void DomesticStudentList::updateDomHD(DomesticStudentList **head_ref)
{
    DomesticStudentList *temp = *head_ref;
    (*head_ref)->head = temp;
    DomesticStudentList *last = *head_ref;
    while (last->next != NULL)
        last = last->next;
    (*head_ref)->tail = last;
}