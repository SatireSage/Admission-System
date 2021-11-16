// stu_sort.cpp to implement your sorting functions
#include "stu_sort.hpp"

// Single Sort Functions
void MergeSortDom(DomesticStudentList **headRef, char type)
{
    DomesticStudentList *head = *headRef;
    DomesticStudentList *stu1;
    DomesticStudentList *stu2;

    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }
    FrontBackSplitDom(head, &stu1, &stu2);
    MergeSortDom(&stu1, type);
    MergeSortDom(&stu2, type);

    *headRef = SortedMergeDom(stu1, stu2, type);
}

DomesticStudentList *SortedMergeDom(DomesticStudentList *stu1, DomesticStudentList *stu2, char type)
{
    DomesticStudentList *result = NULL;

    if (stu1 == NULL)
        return (stu2);
    else if (stu2 == NULL)
        return (stu1);

    if (((type == 'F' || type == 'f') && (compareFirstName(stu1->domesticStudent, stu2->domesticStudent) < 0)) || ((type == 'L' || type == 'l') && (compareLastName(stu1->domesticStudent, stu2->domesticStudent) < 0)) || ((type == 'G' || type == 'g') && (compareCGPA(stu1->domesticStudent, stu2->domesticStudent) < 0)) || ((type == 'R' || type == 'r') && (compareResearchScore(stu1->domesticStudent, stu2->domesticStudent) < 0)) || ((type == 'P' || type == 'p') && (compareProvince(stu1->domesticStudent, stu2->domesticStudent) < 0)))
    {
        result = stu1;
        result->next = SortedMergeDom(stu1->next, stu2, type);
    }
    else
    {
        result = stu2;
        result->next = SortedMergeDom(stu1, stu2->next, type);
    }
    return (result);
}

void FrontBackSplitDom(DomesticStudentList *source,
                       DomesticStudentList **frontRef, DomesticStudentList **backRef)
{
    DomesticStudentList *fast;
    DomesticStudentList *slow;
    slow = source;
    fast = source->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

void MergeSortInt(InternationalStudentList **headRef, char type)
{
    InternationalStudentList *head = *headRef;
    InternationalStudentList *stu1;
    InternationalStudentList *stu2;

    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }
    FrontBackSplitInt(head, &stu1, &stu2);
    MergeSortInt(&stu1, type);
    MergeSortInt(&stu2, type);

    *headRef = SortedMergeInt(stu1, stu2, type);
}

InternationalStudentList *SortedMergeInt(InternationalStudentList *stu1, InternationalStudentList *stu2, char type)
{
    InternationalStudentList *result = NULL;

    if (stu1 == NULL)
        return (stu2);
    else if (stu2 == NULL)
        return (stu1);

    if (((type == 'F' || type == 'f') && (compareFirstName(stu1->internationalStudent, stu2->internationalStudent) < 0)) || ((type == 'L' || type == 'l') && (compareLastName(stu1->internationalStudent, stu2->internationalStudent) < 0)) || ((type == 'G' || type == 'g') && (compareCGPA(stu1->internationalStudent, stu2->internationalStudent) < 0)) || ((type == 'R' || type == 'r') && (compareResearchScore(stu1->internationalStudent, stu2->internationalStudent) < 0)) || ((type == 'C' || type == 'c') && (compareCountry(stu1->internationalStudent, stu2->internationalStudent) < 0)))
    {
        result = stu1;
        result->next = SortedMergeInt(stu1->next, stu2, type);
    }
    else
    {
        result = stu2;
        result->next = SortedMergeInt(stu1, stu2->next, type);
    }
    return (result);
}

void FrontBackSplitInt(InternationalStudentList *source,
                       InternationalStudentList **frontRef, InternationalStudentList **backRef)
{
    InternationalStudentList *fast;
    InternationalStudentList *slow;
    slow = source;
    fast = source->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

void MergeSortAll(StudentList **headRef, char type)
{
    StudentList *head = *headRef;
    StudentList *stu1;
    StudentList *stu2;

    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }
    FrontBackSplitAll(head, &stu1, &stu2);
    MergeSortAll(&stu1, type);
    MergeSortAll(&stu2, type);

    *headRef = SortedMergeAll(stu1, stu2, type);
}

void MergeSortAll(StudentList **headRef)
{
    StudentList *head = *headRef;
    StudentList *stu1;
    StudentList *stu2;

    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }
    FrontBackSplitAll(head, &stu1, &stu2);
    MergeSortAll(&stu1);
    MergeSortAll(&stu2);

    *headRef = SortedMergeAll(stu1, stu2);
}

StudentList *SortedMergeAll(StudentList *stu1, StudentList *stu2, char type)
{
    StudentList *result = NULL;

    if (stu1 == NULL)
        return (stu2);
    else if (stu2 == NULL)
        return (stu1);

    if (((type == 'F' || type == 'f') && (compareFirstName(stu1->Students, stu2->Students) < 0)) || ((type == 'L' || type == 'l') && (compareLastName(stu1->Students, stu2->Students) < 0)) || ((type == 'G' || type == 'g') && (compareCGPA(stu1->Students, stu2->Students) < 0)) || ((type == 'R' || type == 'r') && (compareResearchScore(stu1->Students, stu2->Students) < 0)) || ((type == 'T' || type == 't') && (compareType(stu1->Students, stu2->Students) < 0)))
    {
        result = stu1;
        result->next = SortedMergeAll(stu1->next, stu2, type);
    }
    else
    {
        result = stu2;
        result->next = SortedMergeAll(stu1, stu2->next, type);
    }
    return (result);
}

StudentList *SortedMergeAll(StudentList *stu1, StudentList *stu2)
{
    StudentList *result = NULL;

    if (stu1 == NULL)
        return (stu2);
    else if (stu2 == NULL)
        return (stu1);

    if ((compareResearchScore(stu1->Students, stu2->Students) == 0) && (compareCGPA(stu1->Students, stu2->Students) == 0) && (compareType(stu1->Students, stu2->Students) < 0))
    {
        result = stu1;
        result->next = SortedMergeAll(stu1->next, stu2);
    }
    else if ((compareResearchScore(stu1->Students, stu2->Students) == 0) && (compareCGPA(stu1->Students, stu2->Students) < 0))
    {
        result = stu1;
        result->next = SortedMergeAll(stu1->next, stu2);
    }
    else if (compareResearchScore(stu1->Students, stu2->Students) < 0)
    {
        result = stu1;
        result->next = SortedMergeAll(stu1->next, stu2);
    }
    else
    {
        result = stu2;
        result->next = SortedMergeAll(stu1, stu2->next);
    }
    return (result);
}

void FrontBackSplitAll(StudentList *source,
                       StudentList **frontRef, StudentList **backRef)
{
    StudentList *fast;
    StudentList *slow;
    slow = source;
    fast = source->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}