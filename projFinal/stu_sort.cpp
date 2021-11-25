// stu_sort.cpp to implement your sorting functions
#include "stu_sort.hpp"

//----------------------------------------------Domestic-----------------------------------------
// Single Sort Functions
void MergeSortDom(DomesticStudentList **headRef, char type)//O(n^3) time complexity
{
    DomesticStudentList *head = *headRef;
    DomesticStudentList *stu1;
    DomesticStudentList *stu2;

    if ((head != NULL) && (head->next != NULL))
    {
        FrontBackSplit(head, &stu1, &stu2);
        MergeSortDom(&stu1, type);
        MergeSortDom(&stu2, type);

        *headRef = SortedMergeDom(stu1, stu2, type);
    }
}

// Single Sort Functions
void MergeSortDom(DomesticStudentList **headRef)//O(n^3) time complexity
{
    DomesticStudentList *head = *headRef;
    DomesticStudentList *stu1;
    DomesticStudentList *stu2;

    if ((head != NULL) && (head->next != NULL))
    {
        FrontBackSplit(head, &stu1, &stu2);
        MergeSortDom(&stu1);
        MergeSortDom(&stu2);

        *headRef = SortedMergeDom(stu1, stu2);
    }
}

DomesticStudentList *SortedMergeDom(DomesticStudentList *stu1, DomesticStudentList *stu2, char type)//O(n^2) time complexity
{
    DomesticStudentList *result = NULL;

    if (stu1 == NULL)
    {
        return (stu2);
    }
    else if (stu2 == NULL)
    {
        return (stu1);
    }
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

DomesticStudentList *SortedMergeDom(DomesticStudentList *stu1, DomesticStudentList *stu2)//O(n^2) time complexity
{
    DomesticStudentList *result = NULL;

    if (stu1 == NULL)
    {
        return (stu2);
    }
    else if (stu2 == NULL)
    {
        return (stu1);
    }

    if ((compareResearchScore(stu1->domesticStudent, stu2->domesticStudent) == 0) && (compareCGPA(stu1->domesticStudent, stu2->domesticStudent) == 0) && (compareProvince(stu1->domesticStudent, stu2->domesticStudent) < 0))
    {
        result = stu1;
        result->next = SortedMergeDom(stu1->next, stu2);
    }
    else if ((compareResearchScore(stu1->domesticStudent, stu2->domesticStudent) == 0) && (compareCGPA(stu1->domesticStudent, stu2->domesticStudent) < 0))
    {
        result = stu1;
        result->next = SortedMergeDom(stu1->next, stu2);
    }
    else if (compareResearchScore(stu1->domesticStudent, stu2->domesticStudent) < 0)
    {
        result = stu1;
        result->next = SortedMergeDom(stu1->next, stu2);
    }
    else
    {
        result = stu2;
        result->next = SortedMergeDom(stu1, stu2->next);
    }
    return (result);
}

void FrontBackSplit(DomesticStudentList *source, DomesticStudentList **frontRef, DomesticStudentList **backRef)//O(n) time complexity
{
    DomesticStudentList *first, *second;
    second = source;
    first = source->next;

    while (first != NULL)
    {
        first = first->next;
        if (first != NULL)
        {
            second = second->next;
            first = first->next;
        }
    }

    *frontRef = source;
    *backRef = second->next;
    second->next = NULL;
}

//----------------------------------------------International--------------------------------------------------------
void MergeSortInt(InternationalStudentList **headRef, char type)//O(n^3) time complexity
{
    InternationalStudentList *head = *headRef;
    InternationalStudentList *stu1;
    InternationalStudentList *stu2;

    if ((head != NULL) && (head->next != NULL))
    {
        FrontBackSplit(head, &stu1, &stu2);
        MergeSortInt(&stu1, type);
        MergeSortInt(&stu2, type);

        *headRef = SortedMergeInt(stu1, stu2, type);
    }
}

void MergeSortInt(InternationalStudentList **headRef)//O(n^3) time complexity
{
    InternationalStudentList *head = *headRef;
    InternationalStudentList *stu1;
    InternationalStudentList *stu2;

    if ((head != NULL) && (head->next != NULL))
    {
        FrontBackSplit(head, &stu1, &stu2);
        MergeSortInt(&stu1);
        MergeSortInt(&stu2);

        *headRef = SortedMergeInt(stu1, stu2);
    }
}

InternationalStudentList *SortedMergeInt(InternationalStudentList *stu1, InternationalStudentList *stu2, char type)//O(n^2) time complexity
{
    InternationalStudentList *result = NULL;

    if (stu1 == NULL)
    {
        return (stu2);
    }
    else if (stu2 == NULL)
    {
        return (stu1);
    }

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

InternationalStudentList *SortedMergeInt(InternationalStudentList *stu1, InternationalStudentList *stu2)//O(n^2) time complexity
{
    InternationalStudentList *result = NULL;

    if (stu1 == NULL)
    {
        return (stu2);
    }
    else if (stu2 == NULL)
    {
        return (stu1);
    }

    if ((compareResearchScore(stu1->internationalStudent, stu2->internationalStudent) == 0) && (compareCGPA(stu1->internationalStudent, stu2->internationalStudent) == 0) && (compareCountry(stu1->internationalStudent, stu2->internationalStudent) < 0))
    {
        result = stu1;
        result->next = SortedMergeInt(stu1->next, stu2);
    }
    else if ((compareResearchScore(stu1->internationalStudent, stu2->internationalStudent) == 0) && (compareCGPA(stu1->internationalStudent, stu2->internationalStudent) < 0))
    {
        result = stu1;
        result->next = SortedMergeInt(stu1->next, stu2);
    }
    else if (compareResearchScore(stu1->internationalStudent, stu2->internationalStudent) < 0)
    {
        result = stu1;
        result->next = SortedMergeInt(stu1->next, stu2);
    }
    else
    {
        result = stu2;
        result->next = SortedMergeInt(stu1, stu2->next);
    }
    return (result);
}

void FrontBackSplit(InternationalStudentList *source, InternationalStudentList **frontRef, InternationalStudentList **backRef)//O(n) time complexity
{
    InternationalStudentList *first, *second;
    second = source;
    first = source->next;

    while (first != NULL)
    {
        first = first->next;
        if (first != NULL)
        {
            second = second->next;
            first = first->next;
        }
    }

    *frontRef = source;
    *backRef = second->next;
    second->next = NULL;
}

//-----------------------------------------------Student List----------------------------------------------------------------
void MergeSortAll(StudentList **headRef, char type)//O(n^3) time complexity
{
    StudentList *head = *headRef;
    StudentList *stu1;
    StudentList *stu2;

    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }
    FrontBackSplit(head, &stu1, &stu2);
    MergeSortAll(&stu1, type);
    MergeSortAll(&stu2, type);

    *headRef = SortedMergeAll(stu1, stu2, type);
}

void MergeSortAll(StudentList **headRef)//O(n^3) time complexity
{
    StudentList *head = *headRef;
    StudentList *stu1;
    StudentList *stu2;

    if ((head != NULL) && (head->next != NULL))
    {
        FrontBackSplit(head, &stu1, &stu2);
        MergeSortAll(&stu1);
        MergeSortAll(&stu2);

        *headRef = SortedMergeAll(stu1, stu2);
    }
}

StudentList *SortedMergeAll(StudentList *stu1, StudentList *stu2, char type)//O(n^2) time complexity
{
    StudentList *result = NULL;

    if (stu1 == NULL)
    {
        return (stu2);
    }
    else if (stu2 == NULL)
    {
        return (stu1);
    }

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

StudentList *SortedMergeAll(StudentList *stu1, StudentList *stu2)//O(n^2) time complexity
{
    StudentList *result = NULL;

    if (stu1 == NULL)
    {
        return (stu2);
    }
    else if (stu2 == NULL)
    {
        return (stu1);
    }

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

void FrontBackSplit(StudentList *source, StudentList **frontRef, StudentList **backRef)//O(n) time complexity
{
    StudentList *first, *second;
    second = source;
    first = source->next;

    while (first != NULL)
    {
        first = first->next;
        if (first != NULL)
        {
            second = second->next;
            first = first->next;
        }
    }

    *frontRef = source;
    *backRef = second->next;
    second->next = NULL;
}