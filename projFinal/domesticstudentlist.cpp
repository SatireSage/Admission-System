// domesticstudentlist.cpp to implement your classes
#include "domesticstudentlist.hpp"
#include "stu_sort.hpp"
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; // use namespace std

void DomesticStudentList::deleteDom(DomesticStudentList **head_ref, string FirstName, string LastName) // O(n) time complexity
{
    transform(FirstName.begin(), FirstName.end(), FirstName.begin(), ::tolower);
    transform(LastName.begin(), LastName.end(), LastName.begin(), ::tolower);
    bool exists = (*head_ref)->inList((*head_ref), FirstName, LastName);

    if (exists == 1)
    {
        for (int i = 0; i < 2; i++)
        {
            DomesticStudentList *temp = *head_ref;
            DomesticStudentList *prev = NULL;

            string fname, lname;
            fname = temp->domesticStudent.getFirstName();
            lname = temp->domesticStudent.getLastName();
            transform(fname.begin(), fname.end(), fname.begin(), ::tolower);
            transform(lname.begin(), lname.end(), lname.begin(), ::tolower);

            if (temp != NULL && fname == FirstName && lname == LastName)
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
                while (temp != NULL && fname != FirstName && lname != LastName)
                {
                    prev = temp;
                    temp = temp->next;
                    fname = temp->domesticStudent.getFirstName();
                    lname = temp->domesticStudent.getLastName();
                    transform(fname.begin(), fname.end(), fname.begin(), ::tolower);
                    transform(lname.begin(), lname.end(), lname.begin(), ::tolower);
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
    }
    else
    {
        return;
    }
}

void DomesticStudentList::appendDom(DomesticStudentList **root, Domestic item) // O(n) time complexity
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

bool DomesticStudentList::inList(DomesticStudentList *Stu, string FirstName, string LastName)
{
    bool found;
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
    {
        found = false;
    }
    else
    {
        found = true;
    }
    return found;
}

void DomFindName(DomesticStudentList *Stu, string FirstName, string LastName) // O(n^2) time complexity
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

void DomFindCGPA(DomesticStudentList *Stu, float CGPA_VALUE) // O(n) time complexity
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

void DomFindResearchScore(DomesticStudentList *Stu, int researchScore_VALUE) // O(n) time complexity
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

void DomFindUID(DomesticStudentList *Stu, int UIDValue) // O(n) time complexity
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

void DomesticStudentList::printDom(DomesticStudentList *node) // O(n) time complexity
{
    while (node != NULL)
    {
        cout << " " << node->domesticStudent;
        node = node->next;
    }
}

void DomesticStudentList::deleteDomHD(DomesticStudentList **head_ref) // O(n) time complexity
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

void DomesticStudentList::updateDomHD(DomesticStudentList **head_ref) // O(n) time complexity
{
    DomesticStudentList *temp = *head_ref;
    (*head_ref)->head = temp;
    DomesticStudentList *last = *head_ref;
    while (last->next != NULL)
        last = last->next;
    (*head_ref)->tail = last;
}

void DomesticStudentList::threshold(DomesticStudentList *Stu, float CGPA_VALUE, int researchScore_VALUE) // O(n) time complexity
{
    int storeRScore;
    float storeCGPA;
    DomesticStudentList *current;
    DomesticStudentList *storeStu = nullptr;

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
            storeCGPA = current->domesticStudent.getCGPA();
            if (CGPA_VALUE <= storeCGPA && researchScore_VALUE <= storeRScore)
            {
                storeStu->appendDom(&storeStu, current->domesticStudent);
            }
            current = current->next;
        }
    }

    if (storeStu == nullptr)
    {
        cout << "No such student found." << endl;
    }
    else
    {
        MergeSortDom(&storeStu);
        printDom(storeStu);
    }
}

void DomesticStudentList::threshold(DomesticStudentList *Stu, int researchScore_VALUE) // O(n) time complexity
{
    int storeRScore;
    DomesticStudentList *current;
    DomesticStudentList *storeStu = nullptr;

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
            if (researchScore_VALUE <= storeRScore)
            {
                storeStu->appendDom(&storeStu, current->domesticStudent);
            }
            current = current->next;
        }
    }

    if (storeStu == nullptr)
    {
        cout << "No such student found." << endl;
    }
    else
    {
        MergeSortDom(&storeStu);
        printDom(storeStu);
    }
}

void DomesticStudentList::threshold(DomesticStudentList *Stu, float CGPA_VALUE) // O(n) time complexity
{
    float storeCGPA;
    DomesticStudentList *current;
    DomesticStudentList *storeStu = nullptr;

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
            if (CGPA_VALUE <= storeCGPA)
            {
                storeStu->appendDom(&storeStu, current->domesticStudent);
            }
            current = current->next;
        }
    }

    if (storeStu == nullptr)
    {
        cout << "No such student found." << endl;
    }
    else
    {
        MergeSortDom(&storeStu);
        printDom(storeStu);
    }
}

void DomesticStudentList::deleteList(DomesticStudentList **head_ref)
{
    DomesticStudentList *currentNode = *head_ref;
    DomesticStudentList *next = NULL;

    while (currentNode != NULL)
    {
        next = currentNode->next;
        free(currentNode);
        currentNode = next;
    }
    *head_ref = nullptr;
}
