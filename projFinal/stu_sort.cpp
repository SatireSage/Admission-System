// stu_sort.cpp to implement your sorting functions
#include "stu_sort.hpp"

// Single Sort Functions
void MergeSortDom(DomesticStudentList **headRef, char type)
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
void MergeSortDom(DomesticStudentList **headRef)
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

DomesticStudentList *SortedMergeDom(DomesticStudentList *stu1, DomesticStudentList *stu2, char type)
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

DomesticStudentList *SortedMergeDom(DomesticStudentList *stu1, DomesticStudentList *stu2)
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

void FrontBackSplit(DomesticStudentList *source, DomesticStudentList **frontRef, DomesticStudentList **backRef)
{
    DomesticStudentList *a, *b;
    b = source;
    a = source->next;

    while (a != NULL)
    {
        a = a->next;
        if (a != NULL)
        {
            b = b->next;
            a = a->next;
        }
    }

    *frontRef = source;
    *backRef = b->next;
    b->next = NULL;
}

void MergeSortInt(InternationalStudentList **headRef, char type)
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

void MergeSortInt(InternationalStudentList **headRef)
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

InternationalStudentList *SortedMergeInt(InternationalStudentList *stu1, InternationalStudentList *stu2, char type)
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

InternationalStudentList *SortedMergeInt(InternationalStudentList *stu1, InternationalStudentList *stu2)
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

void FrontBackSplit(InternationalStudentList *source,
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
    FrontBackSplit(head, &stu1, &stu2);
    MergeSortAll(&stu1, type);
    MergeSortAll(&stu2, type);

    *headRef = SortedMergeAll(stu1, stu2, type);
}

void MergeSortAll(StudentList **headRef)
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

StudentList *SortedMergeAll(StudentList *stu1, StudentList *stu2, char type)
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

StudentList *SortedMergeAll(StudentList *stu1, StudentList *stu2)
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

void FrontBackSplit(StudentList *source, StudentList **frontRef, StudentList **backRef)
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