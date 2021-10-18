// stu_sort.cpp to implement your sorting functions
#include "stu_sort.hpp"

void mergeDom(Domestic array[], int const left, int const mid, int const right, char type)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto *leftArray = new Domestic[subArrayOne],
         *rightArray = new Domestic[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
    {
        leftArray[i] = array[left + i];
    }
    for (auto j = 0; j < subArrayTwo; j++)
    {
        rightArray[j] = array[mid + 1 + j];
    }

    auto indexOfSubArrayOne = 0,   // Initial index of first sub-array
        indexOfSubArrayTwo = 0;    // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (type == 'F')
        {
            if (leftArray[indexOfSubArrayOne].getFirstName() <= rightArray[indexOfSubArrayTwo].getFirstName())
            {
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else
            {
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }
        if (type == 'L')
        {
            if (leftArray[indexOfSubArrayOne].getLastName() <= rightArray[indexOfSubArrayTwo].getLastName())
            {
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else
            {
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }
        if (type == 'C')
        {
            if (leftArray[indexOfSubArrayOne].getCGPA() <= rightArray[indexOfSubArrayTwo].getCGPA())
            {
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else
            {
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }
        if (type == 'R')
        {
            if (leftArray[indexOfSubArrayOne].getResearchScore() <= rightArray[indexOfSubArrayTwo].getResearchScore())
            {
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else
            {
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSortDome(Domestic array[], int const begin, int const end, char type)
{
    if (begin >= end)
        return;
    auto mid = begin + (end - begin) / 2;
    mergeSortDome(array, begin, mid, type);
    mergeSortDome(array, mid + 1, end, type);
    mergeDom(array, begin, mid, end, type);
}

void mergeInt(International array[], int const left, int const mid, int const right, char type)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto *leftArray = new International[subArrayOne],
         *rightArray = new International[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
    {
        leftArray[i] = array[left + i];
    }
    for (auto j = 0; j < subArrayTwo; j++)
    {
        rightArray[j] = array[mid + 1 + j];
    }

    auto indexOfSubArrayOne = 0,   // Initial index of first sub-array
        indexOfSubArrayTwo = 0;    // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (type == 'F')
        {
            if (leftArray[indexOfSubArrayOne].getFirstName() <= rightArray[indexOfSubArrayTwo].getFirstName())
            {
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else
            {
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }
        if (type == 'L')
        {
            if (leftArray[indexOfSubArrayOne].getLastName() <= rightArray[indexOfSubArrayTwo].getLastName())
            {
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else
            {
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }
        if (type == 'C')
        {
            if (leftArray[indexOfSubArrayOne].getCGPA() <= rightArray[indexOfSubArrayTwo].getCGPA())
            {
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else
            {
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }
        if (type == 'R')
        {
            if (leftArray[indexOfSubArrayOne].getResearchScore() <= rightArray[indexOfSubArrayTwo].getResearchScore())
            {
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else
            {
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSortInt(International array[], int const begin, int const end, char type)
{
    if (begin >= end)
        return;
    auto mid = begin + (end - begin) / 2;
    mergeSortInt(array, begin, mid, type);
    mergeSortInt(array, mid + 1, end, type);
    mergeInt(array, begin, mid, end, type);
}

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
    int ascending = 1;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - 1; j++)
        {
            if (((type == 'F') && (compareFirstName(DomesticStudent[j], DomesticStudent[j + 1]) * ascending > 0)) || ((type == 'L') && (compareLastName(DomesticStudent[j], DomesticStudent[j + 1]) * ascending > 0)) || ((type == 'C') && (compareCGPA(DomesticStudent[j], DomesticStudent[j + 1]) * ascending > 0)) || ((type == 'R') && (compareResearchScore(DomesticStudent[j], DomesticStudent[j + 1]) * ascending > 0)))
            {
                auto arr_size = sizeof(&DomesticStudent) / sizeof(&DomesticStudent[0]);
                mergeSortDome(DomesticStudent, 0, arr_size, type);
            }
        }
    }
}

void SingleSort(International *InternationalStudent, int num, char type)
{
    int ascending = 1;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - 1; j++)
        {
            if (((type == 'F') && (compareFirstName(InternationalStudent[j], InternationalStudent[j + 1]) * ascending > 0)) || ((type == 'L') && (compareLastName(InternationalStudent[j], InternationalStudent[j + 1]) * ascending > 0)) || ((type == 'C') && (compareCGPA(InternationalStudent[j], InternationalStudent[j + 1]) * ascending > 0)) || ((type == 'R') && (compareResearchScore(InternationalStudent[j], InternationalStudent[j + 1]) * ascending > 0)))
            {
                auto arr_size = sizeof(&InternationalStudent) / sizeof(&InternationalStudent[0]);
                mergeSortInt(InternationalStudent, 0, arr_size, type);
            }
        }
    }
}