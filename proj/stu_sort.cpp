// stu_sort.cpp to implement your sorting functions
#include "stu_sort.hpp"

// Multi Sort functions
void MultiSort(Domestic *DomesticStudent, int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - 1; j++)
        {
            if (compareProvince(DomesticStudent[j], DomesticStudent[j + 1]) > 0)
            {
                Domestic tmpStudent;
                tmpStudent = DomesticStudent[j];
                DomesticStudent[j] = DomesticStudent[j + 1];
                DomesticStudent[j + 1] = tmpStudent;
            }
        }
    }
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - 1; j++)
        {
            if (compareCGPA(DomesticStudent[j], DomesticStudent[j + 1]) > 0)
            {
                Domestic tmpStudent;
                tmpStudent = DomesticStudent[j];
                DomesticStudent[j] = DomesticStudent[j + 1];
                DomesticStudent[j + 1] = tmpStudent;
            }
        }
    }
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - 1; j++)
        {
            if (compareResearchScore(DomesticStudent[j], DomesticStudent[j + 1]) > 0)
            {
                Domestic tmpStudent;
                tmpStudent = DomesticStudent[j];
                DomesticStudent[j] = DomesticStudent[j + 1];
                DomesticStudent[j + 1] = tmpStudent;
            }
        }
    }
}

void MultiSort(International *InternationalStudent, int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - 1; j++)
        {
            if (compareCountry(InternationalStudent[j], InternationalStudent[j + 1]) > 0)
            {
                International tmpStudent;
                tmpStudent = InternationalStudent[j];
                InternationalStudent[j] = InternationalStudent[j + 1];
                InternationalStudent[j + 1] = tmpStudent;
            }
        }
    }
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - 1; j++)
        {
            if (compareCGPA(InternationalStudent[j], InternationalStudent[j + 1]) > 0)
            {
                International tmpStudent;
                tmpStudent = InternationalStudent[j];
                InternationalStudent[j] = InternationalStudent[j + 1];
                InternationalStudent[j + 1] = tmpStudent;
            }
        }
    }
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - 1; j++)
        {
            if (compareResearchScore(InternationalStudent[j], InternationalStudent[j + 1]) > 0)
            {
                International tmpStudent;
                tmpStudent = InternationalStudent[j];
                InternationalStudent[j] = InternationalStudent[j + 1];
                InternationalStudent[j + 1] = tmpStudent;
            }
        }
    }
}

// Single Sort functions
void SingleSort(Domestic *DomesticStudent, int num, char type)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - 1; j++)
        {
            if (((type == 'F' || type == 'f') && (compareFirstName(DomesticStudent[j], DomesticStudent[j + 1]) > 0)) || ((type == 'L' || type == 'l') && (compareLastName(DomesticStudent[j], DomesticStudent[j + 1]) > 0)) || ((type == 'G' || type == 'g') && (compareCGPA(DomesticStudent[j], DomesticStudent[j + 1]) > 0)) || ((type == 'R' || type == 'r') && (compareResearchScore(DomesticStudent[j], DomesticStudent[j + 1]) > 0)) || ((type == 'P' || type == 'p') && (compareProvince(DomesticStudent[j], DomesticStudent[j + 1]) > 0)))
            {
                Domestic tmpStudent;
                tmpStudent = DomesticStudent[j];
                DomesticStudent[j] = DomesticStudent[j + 1];
                DomesticStudent[j + 1] = tmpStudent;
            }
        }
    }
}

void SingleSort(International *InternationalStudent, int num, char type)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - 1; j++)
        {
            if (((type == 'F' || type == 'f') && (compareFirstName(InternationalStudent[j], InternationalStudent[j + 1]) > 0)) || ((type == 'L' || type == 'l') && (compareLastName(InternationalStudent[j], InternationalStudent[j + 1]) > 0)) || ((type == 'G' || type == 'g') && (compareCGPA(InternationalStudent[j], InternationalStudent[j + 1]) > 0)) || ((type == 'R' || type == 'r') && (compareResearchScore(InternationalStudent[j], InternationalStudent[j + 1]) > 0)) || ((type == 'C' || type == 'c') && (compareCountry(InternationalStudent[j], InternationalStudent[j + 1]) > 0)))
            {
                International tmpStudent;
                tmpStudent = InternationalStudent[j];
                InternationalStudent[j] = InternationalStudent[j + 1];
                InternationalStudent[j + 1] = tmpStudent;
            }
        }
    }
}