// stu_sort.cpp to implement your sorting functions
#include "stu_sort.hpp"

// Using quick sort for sorting alg

// sorts domestic by RS then gpa then province
void MultiSort(Domestic *DomesticStudent, int low, int high)
{
    if (low < high)
    {
        int pi;
        Domestic pivot = DomesticStudent[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++)
        {
            if ((compareResearchScore(DomesticStudent[j], DomesticStudent[high]) == 0) && (compareCGPA(DomesticStudent[j], DomesticStudent[high]) == 0) && (compareProvince(DomesticStudent[j], DomesticStudent[high]) < 0))
            {
                i++;
                Domestic tmpStudent;
                tmpStudent = DomesticStudent[i];
                DomesticStudent[i] = DomesticStudent[j];
                DomesticStudent[j] = tmpStudent;
            }
            else if ((compareResearchScore(DomesticStudent[j], DomesticStudent[high]) == 0) && (compareCGPA(DomesticStudent[j], DomesticStudent[high]) < 0))
            {
                i++;
                Domestic tmpStudent;
                tmpStudent = DomesticStudent[i];
                DomesticStudent[i] = DomesticStudent[j];
                DomesticStudent[j] = tmpStudent;
            }
            else if (compareResearchScore(DomesticStudent[j], DomesticStudent[high]) < 0)
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

        MultiSort(DomesticStudent, low, pi - 1);
        MultiSort(DomesticStudent, pi + 1, high);
    }
}

// sorts international students by RS then Gpa then country
void MultiSort(International *InternationalStudent, int low, int high)
{
    if (low < high)
    {
        int pi;
        International pivot = InternationalStudent[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++)
        {
            if ((compareResearchScore(InternationalStudent[j], InternationalStudent[high]) == 0) && (compareCGPA(InternationalStudent[j], InternationalStudent[high]) == 0) && (compareCountry(InternationalStudent[j], InternationalStudent[high]) < 0))
            {
                i++;
                International tmpStudent;
                tmpStudent = InternationalStudent[i];
                InternationalStudent[i] = InternationalStudent[j];
                InternationalStudent[j] = tmpStudent;
            }
            else if ((compareResearchScore(InternationalStudent[j], InternationalStudent[high]) == 0) && (compareCGPA(InternationalStudent[j], InternationalStudent[high]) < 0))
            {
                i++;
                International tmpStudent;
                tmpStudent = InternationalStudent[i];
                InternationalStudent[i] = InternationalStudent[j];
                InternationalStudent[j] = tmpStudent;
            }
            else if (compareResearchScore(InternationalStudent[j], InternationalStudent[high]) < 0)
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

        MultiSort(InternationalStudent, low, pi - 1);
        MultiSort(InternationalStudent, pi + 1, high);
    }
}

// sort all students
void MultiSort(Student *Students, int num)
{
    char sortOptions[] = {'g', 'r'};
    for (int sort : sortOptions)
    {
        SingleSort(Students, 0, num, sort);
    }
}

// Single Sort domestic for one parameter sorting
void SingleSort(Domestic *DomesticStudent, int low, int high, char type)
{
    if (low < high)
    {
        int pi;
        Domestic pivot = DomesticStudent[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) // sorts based on user selection
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

// single sort for international students based on a single sorting parameter
void SingleSort(International *InternationalStudent, int low, int high, char type)
{
    if (low < high)
    {
        int pi;
        International pivot = InternationalStudent[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) // sorts based on user parameter
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

// sort all students
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