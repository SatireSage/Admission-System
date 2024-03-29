// studentlist.cpp to implement your classes
#include "studentlist.hpp"
#include "stu_sort.hpp"
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; // use namespace std

void StudentList::deleteMerge(StudentList **headNode, string FirstName, string LastName) // O(n) time complexity
{
    for (int i = 0; i < 2; i++)
    {
        transform(FirstName.begin(), FirstName.end(), FirstName.begin(), ::tolower);
        transform(LastName.begin(), LastName.end(), LastName.begin(), ::tolower);
        bool exists = (*headNode)->inList((*headNode), FirstName, LastName);

        if (exists == 1)
        {

            StudentList *temp = *headNode;
            StudentList *prev = NULL;

            string fname, lname;
            fname = temp->Students.getFirstName();
            lname = temp->Students.getLastName();
            transform(fname.begin(), fname.end(), fname.begin(), ::tolower);
            transform(lname.begin(), lname.end(), lname.begin(), ::tolower);

            if (temp != NULL && fname == FirstName && lname == LastName)
            {
                *headNode = temp->next; // Changed head
                delete temp;            // free old head

                StudentList *second_last = *headNode;
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
                    fname = temp->Students.getFirstName();
                    lname = temp->Students.getLastName();
                    transform(fname.begin(), fname.end(), fname.begin(), ::tolower);
                    transform(lname.begin(), lname.end(), lname.begin(), ::tolower);
                }

                if (temp == NULL)
                    return;

                prev->next = temp->next;
                delete temp;
                StudentList *second_last = *headNode;
                while (second_last->next != NULL)
                    second_last = second_last->next;
                (*headNode)->head = second_last->head;
                (*headNode)->tail = second_last;
            }
        }
        else
        {
            return;
        }
    }
}

void StudentList::appendMerge(StudentList **root, Student item) // O(n) time complexity
{
    try
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
    catch (bad_alloc)
    {
        std::cout << "Warning: Bad memory allocation!";
        exit(1);
    }
}

bool StudentList::inList(StudentList *Stu, string FirstName, string LastName)
{
    bool found;
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
    {
        found = false;
    }
    else
    {
        found = true;
    }
    return found;
}

void FindName(StudentList *Stu, string FirstName, string LastName) // O(n^2) time complexity
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

void FindCGPA(StudentList *Stu, float CGPA_VALUE) // O(n) time complexity
{
    float storeCGPA;
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

void FindResearchScore(StudentList *Stu, int researchScore_VALUE) // O(n) time complexity
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

void FindUID(StudentList *Stu, int UIDValue) // O(n) time complexity
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

void StudentList::threshold(StudentList *Stu, float CGPA_VALUE, int researchScore_VALUE) // O(n) time complexity
{
    int storeRScore;
    float storeCGPA;
    StudentList *current;
    StudentList *storeStu = nullptr;

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
            storeCGPA = current->Students.getCGPA();
            if (CGPA_VALUE <= storeCGPA && researchScore_VALUE <= storeRScore)
            {
                storeStu->appendMerge(&storeStu, current->Students);
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
        MergeSortAll(&storeStu);
        printMerge(storeStu);
    }
}

void StudentList::threshold(StudentList *Stu, int researchScore_VALUE) // O(n) time complexity
{
    int storeRScore;
    StudentList *current;
    StudentList *storeStu = nullptr;

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
            if (researchScore_VALUE <= storeRScore)
            {
                storeStu->appendMerge(&storeStu, current->Students);
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
        MergeSortAll(&storeStu);
        printMerge(storeStu);
    }
}

void StudentList::threshold(StudentList *Stu, float CGPA_VALUE) // O(n) time complexity
{
    float storeCGPA;
    StudentList *current;
    StudentList *storeStu = nullptr;

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
            if (CGPA_VALUE <= storeCGPA)
            {
                storeStu->appendMerge(&storeStu, current->Students);
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
        MergeSortAll(&storeStu);
        printMerge(storeStu);
    }
}

void StudentList::printMerge(StudentList *node) // O(n) time complexity
{
    while (node != NULL)
    {
        cout << " " << node->Students;
        node = node->next;
    }
}

void StudentList::deleteMergeHD(StudentList **headNode) // O(n) time complexity
{
    if (headNode == NULL)
        return;

    deleteMerge(&(*headNode), (*headNode)->Students.getFirstName(), (*headNode)->Students.getLastName());

    StudentList *second_last = *headNode;
    while (second_last->next->next != NULL)
        second_last = second_last->next;

    delete (*headNode)->tail;
    (*headNode)->tail = second_last;
    (*headNode)->tail->next = NULL;
}

void StudentList::updateMergeHD(StudentList **headNode) // O(n) time complexity
{
    StudentList *temp = *headNode;
    (*headNode)->head = temp;
    StudentList *last = *headNode;
    while (last->next != NULL)
        last = last->next;
    (*headNode)->tail = last;
}

void StudentList::deleteList(StudentList **headNode)
{
    StudentList *currentNode = *headNode;
    StudentList *next = NULL;

    while (currentNode != NULL)
    {
        next = currentNode->next;
        free(currentNode);
        currentNode = next;
    }
    *headNode = nullptr;
}
