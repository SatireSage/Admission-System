// stu_sort.cpp to implement your sorting functions
#include "stu_sort.hpp"

void merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

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
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
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

void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

// Multi Sort functions
void MultiSort(Domestic *DomesticStudent, int num, string type, string order)
{
    for (int i = sizeof(type) - 1; i >= 0; i--)
    {
        SingleSort(DomesticStudent, num, type[i], order);
    }
}

void MultiSort(International *InternationalStudent, int num, string type, string order)
{
    for (int i = sizeof(type) - 1; i >= 0; i--)
    {
        SingleSort(InternationalStudent, num, type[i], order);
    }
}

// Single Sort functions
void SingleSort(Domestic *DomesticStudent, int num, char type, string order)
{
    int ascending = -1;
    if (order == "ascending")
        ascending = 1;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - 1; j++)
        {
            if (((type == 'F') && (compareFirstName(DomesticStudent[j], DomesticStudent[j + 1]) * ascending > 0)) || ((type == 'L') && (compareLastName(DomesticStudent[j], DomesticStudent[j + 1]) * ascending > 0)) || ((type == 'G') && (compareCGPA(DomesticStudent[j], DomesticStudent[j + 1]) * ascending > 0)) || ((type == 'R') && (compareResearchScore(DomesticStudent[j], DomesticStudent[j + 1]) * ascending > 0)))
            {
                Domestic tmpStudent;
                tmpStudent = DomesticStudent[j];
                DomesticStudent[j] = DomesticStudent[j + 1];
                DomesticStudent[j + 1] = tmpStudent;
            }
        }
    }
}

void SingleSort(International *InternationalStudent, int num, char type, string order)
{
    int ascending = -1;
    if (order == "ascending")
        ascending = 1;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - 1; j++)
        {
            if (((type == 'F') && (compareFirstName(InternationalStudent[j], InternationalStudent[j + 1]) * ascending > 0)) || ((type == 'L') && (compareLastName(InternationalStudent[j], InternationalStudent[j + 1]) * ascending > 0)) || ((type == 'G') && (compareCGPA(InternationalStudent[j], InternationalStudent[j + 1]) * ascending > 0)) || ((type == 'R') && (compareResearchScore(InternationalStudent[j], InternationalStudent[j + 1]) * ascending > 0)))
            {
                International tmpStudent;
                tmpStudent = InternationalStudent[j];
                InternationalStudent[j] = InternationalStudent[j + 1];
                InternationalStudent[j + 1] = tmpStudent;
                // auto arr_size = sizeof(InternationalStudent) / sizeof(InternationalStudent[0]);
                // mergeSort(InternationalStudent, 0, arr_size);
            }
        }
    }
}