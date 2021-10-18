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
            if (((type == 'F') && (compareFirstName(DomesticStudent[j], DomesticStudent[j + 1]) > 0)) || ((type == 'L') && (compareLastName(DomesticStudent[j], DomesticStudent[j + 1]) > 0)) || ((type == 'C') && (compareCGPA(DomesticStudent[j], DomesticStudent[j + 1]) > 0)) || ((type == 'R') && (compareResearchScore(DomesticStudent[j], DomesticStudent[j + 1]) > 0)))
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
            if (((type == 'F') && (compareFirstName(InternationalStudent[j], InternationalStudent[j + 1]) > 0)) || ((type == 'L') && (compareLastName(InternationalStudent[j], InternationalStudent[j + 1]) > 0)) || ((type == 'C') && (compareCGPA(InternationalStudent[j], InternationalStudent[j + 1]) > 0)) || ((type == 'R') && (compareResearchScore(InternationalStudent[j], InternationalStudent[j + 1]) > 0)))
            {
                International tmpStudent;
                tmpStudent = InternationalStudent[j];
                InternationalStudent[j] = InternationalStudent[j + 1];
                InternationalStudent[j + 1] = tmpStudent;
            }
        }
    }
}