// stu_sort.cpp to implement your sorting functions
#include "stu_sort.hpp"

// Multi Sort functions
void MultiSort(Domestic *DomesticStudent, int num, string type)
{
    for (int i = sizeof(type) - 1; i >= 0; i--)
    {
        SingleSort(DomesticStudent, num, type[i]);
    }
}

void MultiSort(International *InternationalStudent, int num, string type)
{
    for (int i = sizeof(type) - 1; i >= 0; i--)
    {
        SingleSort(InternationalStudent, num, type[i]);
    }
}

// Single Sort functions
void SingleSort(Domestic *DomesticStudent, int num, char type)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - 1; j++)
        {
            if (((type == 'F' || type == 'f') && (compareFirstName(DomesticStudent[j], DomesticStudent[j + 1]) > 0)) || ((type == 'L' || type == 'l') && (compareLastName(DomesticStudent[j], DomesticStudent[j + 1]) > 0)) || ((type == 'G' || type == 'g') && (compareCGPA(DomesticStudent[j], DomesticStudent[j + 1]) > 0)) || ((type == 'R' || type == 'r') && (compareResearchScore(DomesticStudent[j], DomesticStudent[j + 1]) > 0)) || ((type == 'P' || type == 'p') && (compareProvince(DomesticStudent[j], DomesticStudent[j + 1]))))
            {
                Domestic tmpStudent;
                tmpStudent = DomesticStudent[j];
                DomesticStudent[j] = DomesticStudent[j + 1];
                DomesticStudent[j + 1] = tmpStudent;
            }
        }
    }
    if (type == 'G' || type == 'R' || type == 'g' || type == 'r')
    {
        int start = 0;
        int end = num - 1;
        while (start < end)
        {
            Domestic tmpStudent;
            tmpStudent = DomesticStudent[start];
            DomesticStudent[start] = DomesticStudent[end];
            DomesticStudent[end] = tmpStudent;
            start++;
            end--;
        }
    }
}

void SingleSort(International *InternationalStudent, int num, char type)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - 1; j++)
        {
            if (((type == 'F' || type == 'f') && (compareFirstName(InternationalStudent[j], InternationalStudent[j + 1]) > 0)) || ((type == 'L' || type == 'l') && (compareLastName(InternationalStudent[j], InternationalStudent[j + 1]) > 0)) || ((type == 'G' || type == 'g') && (compareCGPA(InternationalStudent[j], InternationalStudent[j + 1]) > 0)) || ((type == 'R' || type == 'r') && (compareResearchScore(InternationalStudent[j], InternationalStudent[j + 1]) > 0)) || ((type == 'C' || type == 'c') && (compareCountry(InternationalStudent[j], InternationalStudent[j + 1]))))
            {
                International tmpStudent;
                tmpStudent = InternationalStudent[j];
                InternationalStudent[j] = InternationalStudent[j + 1];
                InternationalStudent[j + 1] = tmpStudent;
            }
        }
    }
    if (type == 'G' || type == 'R' || type == 'g' || type == 'r')
    {
        int start = 0;
        int end = num - 1;
        while (start < end)
        {
            International tmpStudent;
            tmpStudent = InternationalStudent[start];
            InternationalStudent[start] = InternationalStudent[end];
            InternationalStudent[end] = tmpStudent;
            start++;
            end--;
        }
    }
}