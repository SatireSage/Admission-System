// stu_sort.cpp to implement your sorting functions
#include "stu_sort.hpp"

// Multi Sort functions
void MultiSort(Domestic *DomesticStudent, int num)
{
    char sortOptions[] = {'p', 'g', 'r'};
    for (int sort : sortOptions)
    {
        SingleSort(DomesticStudent, 0, num, sort);
    }
}

void MultiSort(International *InternationalStudent, int num)
{
    char sortOptions[] = {'c', 'g', 'r'};
    for (int sort : sortOptions)
    {
        SingleSort(InternationalStudent, 0, num, sort);
    }
}

void MultiSort(Student *Students, int num)
{
    char sortOptions[] = {'g', 'r'};
    for (int sort : sortOptions)
    {
        SingleSort(Students, 0, num, sort);
    }
}

// Single Sort functions
void SingleSort(Domestic *DomesticStudent, int low, int high, char type)
{
    if (low < high)
    {
        int pi;
        Domestic pivot = DomesticStudent[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++)
        {
            if (((type == 'F' || type == 'f') && (compareFirstName(DomesticStudent[j], DomesticStudent[high]) < 0)) || ((type == 'L' || type == 'l') && (compareLastName(DomesticStudent[j], DomesticStudent[high]) < 0)) || ((type == 'G' || type == 'g') && (compareCGPA(DomesticStudent[j], DomesticStudent[high]) < 0)) || ((type == 'R' || type == 'r') && (compareResearchScore(DomesticStudent[j], DomesticStudent[high]) < 0)) || ((type == 'P' || type == 'p') && (compareProvince(DomesticStudent[j], DomesticStudent[high]) < 0)))
            {
                i++;
                Domestic tmpStudent;
                tmpStudent = DomesticStudent[i];
                DomesticStudent[i] = DomesticStudent[j];
                DomesticStudent[j] = tmpStudent;
            }
        }
        Domestic tmpStudent;
        tmpStudent = DomesticStudent[i + 1];
        DomesticStudent[i + 1] = DomesticStudent[high];
        DomesticStudent[high] = tmpStudent;
        pi = i + 1;

        SingleSort(DomesticStudent, low, pi - 1, type);
        SingleSort(DomesticStudent, pi + 1, high, type);
    }
}

void SingleSort(International *InternationalStudent, int low, int high, char type)
{
    if (low < high)
    {
        int pi;
        International pivot = InternationalStudent[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++)
        {
            if (((type == 'F' || type == 'f') && (compareFirstName(InternationalStudent[j], InternationalStudent[high]) < 0)) || ((type == 'L' || type == 'l') && (compareLastName(InternationalStudent[j], InternationalStudent[high]) < 0)) || ((type == 'G' || type == 'g') && (compareCGPA(InternationalStudent[j], InternationalStudent[high]) < 0)) || ((type == 'R' || type == 'r') && (compareResearchScore(InternationalStudent[j], InternationalStudent[high]) < 0)) || ((type == 'C' || type == 'c') && (compareCountry(InternationalStudent[j], InternationalStudent[high]) < 0)))
            {
                i++;
                International tmpStudent;
                tmpStudent = InternationalStudent[i];
                InternationalStudent[i] = InternationalStudent[j];
                InternationalStudent[j] = tmpStudent;
            }
        }
        International tmpStudent;
        tmpStudent = InternationalStudent[i + 1];
        InternationalStudent[i + 1] = InternationalStudent[high];
        InternationalStudent[high] = tmpStudent;
        pi = i + 1;

        SingleSort(InternationalStudent, low, pi - 1, type);
        SingleSort(InternationalStudent, pi + 1, high, type);
    }
}

void SingleSort(Student *Students, int low, int high, char type)
{
    if (low < high)
    {
        int pi;
        Student pivot = Students[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++)
        {
            if ((compareResearchScore(Students[j], Students[high]) == 0) && (compareCGPA(Students[j], Students[high]) < 0))
            {
                i++;
                Student tmpStudent;
                tmpStudent = Students[i];
                Students[i] = Students[j];
                Students[j] = tmpStudent;
            }
            else if ((compareResearchScore(Students[j], Students[high]) < 0))
            {
                i++;
                Student tmpStudent;
                tmpStudent = Students[i];
                Students[i] = Students[j];
                Students[j] = tmpStudent;
            }
        }
        Student tmpStudent;
        tmpStudent = Students[i + 1];
        Students[i + 1] = Students[high];
        Students[high] = tmpStudent;
        pi = i + 1;

        SingleSort(Students, low, pi - 1, type);
        SingleSort(Students, pi + 1, high, type);
    }
}