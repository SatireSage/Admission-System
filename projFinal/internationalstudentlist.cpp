// internationalstudentlist.cpp to implement your classes
#include "internationalstudentlist.hpp"
#include "stu_sort.hpp"
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; // use namespace std

void InternationalStudentList::deleteInt(InternationalStudentList **headNode, string FirstName, string LastName) // O(n) time complexity
{
    for (int i = 0; i < 2; i++)
    {
        transform(FirstName.begin(), FirstName.end(), FirstName.begin(), ::tolower);
        transform(LastName.begin(), LastName.end(), LastName.begin(), ::tolower);
        bool exists = (*headNode)->inList((*headNode), FirstName, LastName);

        if (exists == 1)
        {

            InternationalStudentList *temp = *headNode;
            InternationalStudentList *prev = NULL;

            string fname, lname;
            fname = temp->internationalStudent.getFirstName();
            lname = temp->internationalStudent.getLastName();
            transform(fname.begin(), fname.end(), fname.begin(), ::tolower);
            transform(lname.begin(), lname.end(), lname.begin(), ::tolower);

            if (temp != NULL && fname == FirstName && lname == LastName)
            {
                *headNode = temp->next; // Changed head
                delete temp;            // free old head

                InternationalStudentList *second_last = *headNode;
                while (second_last->next != NULL)
                    second_last = second_last->next;
                (*headNode)->head = second_last->head;
                (*headNode)->tail = second_last;
                return;
            }

            else
            {
                while (temp != NULL && fname != FirstName && lname != LastName)
                {
                    prev = temp;
                    temp = temp->next;
                    fname = temp->internationalStudent.getFirstName();
                    lname = temp->internationalStudent.getLastName();
                    transform(fname.begin(), fname.end(), fname.begin(), ::tolower);
                    transform(lname.begin(), lname.end(), lname.begin(), ::tolower);
                }

                if (temp == NULL)
                    return;

                prev->next = temp->next;
                delete temp;
                InternationalStudentList *second_last = *headNode;
                while (second_last->next != NULL)
                    second_last = second_last->next;
                (*headNode)->head = temp->head;
                (*headNode)->tail = second_last;
            }
        }
        else
        {
            return;
        }
    }
}

void InternationalStudentList::appendInt(InternationalStudentList **root, International item) // O(n) time complexity
{
    try
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
    catch (bad_alloc)
    {
        std::cout << "Warning: Bad memory allocation!";
        exit(1);
    }
}

bool InternationalStudentList::inList(InternationalStudentList *Stu, string FirstName, string LastName)
{
    bool found;
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
    {
        found = false;
    }
    else
    {
        found = true;
    }
    return found;
}

void IntFindName(InternationalStudentList *Stu, string FirstName, string LastName) // O(n^2) time complexity
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
        cout << " " << storeInt.at(i);
}

void IntFindCGPA(InternationalStudentList *Stu, float CGPA_VALUE) // O(n) time complexity
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
        // cout << storeInt.at(i) << ' ';
        cout << " " << storeInt.at(i);
}

void IntFindResearchScore(InternationalStudentList *Stu, int researchScore_VALUE) // O(n) time complexity
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
        cout << " " << storeInt.at(i);
}

void IntFindUID(InternationalStudentList *Stu, int UIDValue) // O(n) time complexity
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
        cout << " " << storeInt.at(i);
}

void InternationalStudentList::printInt(InternationalStudentList *node) // O(n) time complexity
{
    while (node != NULL)
    {
        cout << " " << node->internationalStudent;
        node = node->next;
    }
}

void InternationalStudentList::deleteIntHD(InternationalStudentList **headNode) // O(n) time complexity
{
    if (headNode == NULL)
        return;

    deleteInt(&(*headNode), (*headNode)->internationalStudent.getFirstName(), (*headNode)->internationalStudent.getLastName());

    InternationalStudentList *second_last = *headNode;
    while (second_last->next->next != NULL)
        second_last = second_last->next;

    delete (*headNode)->tail;
    (*headNode)->tail = second_last;
    (*headNode)->tail->next = NULL;
}

void InternationalStudentList::updateIntHD(InternationalStudentList **headNode) // O(n) time complexity
{
    InternationalStudentList *temp = *headNode;
    (*headNode)->head = temp;
    InternationalStudentList *last = *headNode;
    while (last->next != NULL)
        last = last->next;
    (*headNode)->tail = last;
}

void InternationalStudentList::threshold(InternationalStudentList *Stu, float CGPA_VALUE, int researchScore_VALUE) // O(n) time complexity
{
    int storeRScore;
    float storeCGPA;
    InternationalStudentList *current;
    InternationalStudentList *storeStu = nullptr;

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
            storeCGPA = current->internationalStudent.getCGPA();
            if (CGPA_VALUE <= storeCGPA && researchScore_VALUE <= storeRScore)
            {
                storeStu->appendInt(&storeStu, current->internationalStudent);
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
        MergeSortInt(&storeStu);
        printInt(storeStu);
    }
}

void InternationalStudentList::threshold(InternationalStudentList *Stu, int researchScore_VALUE) // O(n) time complexity
{
    int storeRScore;
    InternationalStudentList *current;
    InternationalStudentList *storeStu = nullptr;

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
            if (researchScore_VALUE <= storeRScore)
            {
                storeStu->appendInt(&storeStu, current->internationalStudent);
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
        MergeSortInt(&storeStu);
        printInt(storeStu);
    }
}

void InternationalStudentList::threshold(InternationalStudentList *Stu, float CGPA_VALUE) // O(n) time complexity
{
    float storeCGPA;
    InternationalStudentList *current;
    InternationalStudentList *storeStu = nullptr;

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
            if (CGPA_VALUE <= storeCGPA)
            {
                storeStu->appendInt(&storeStu, current->internationalStudent);
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
        MergeSortInt(&storeStu);
        printInt(storeStu);
    }
}

string IntFindType(InternationalStudentList *Stu, string FirstName, string LastName) // O(n^2) time complexity
{
    string string1, string2, typeValueStu;
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
                if (current->internationalStudent.getTotalScore() >= 93 && current->internationalStudent.getReading() >= 20 && current->internationalStudent.getListening() >= 20 && current->internationalStudent.getSpeaking() >= 20 && current->internationalStudent.getWriting() >= 20)
                {
                    typeValueStu = "Accepted";
                }
                else
                {
                    typeValueStu = "Rejected";
                }
            }
            current = current->next;
        }
    }

    if (storeInt.size() == 0)
    {
        cout << "No such student found." << endl;
        typeValueStu = "None";
    }

    return typeValueStu;
    // for (int i = 0; i < storeInt.size(); i++)
    //     cout << " " << storeInt.at(i);
}

void InternationalStudentList::deleteList(InternationalStudentList **headNode)
{
    InternationalStudentList *currentNode = *headNode;
    InternationalStudentList *next = NULL;

    while (currentNode != NULL)
    {
        next = currentNode->next;
        free(currentNode);
        currentNode = next;
    }
    *headNode = nullptr;
}
