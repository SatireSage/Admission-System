// void heapify(Domestic *DomesticStudent, int n, int i, char type)
// {
//     int largest = i;   // Initialize largest as root
//     int l = 2 * i + 1; // left = 2*i + 1
//     int r = 2 * i + 2; // right = 2*i + 2

//     // If left child is larger than root
//     if (l < n &&
//         (((type == 'F' || type == 'f') && (compareFirstName(DomesticStudent[l], DomesticStudent[largest]) > 0)) ||
//          ((type == 'L' || type == 'l') && (compareLastName(DomesticStudent[l], DomesticStudent[largest]) > 0)) || ((type == 'G' || type == 'g') && (compareCGPA(DomesticStudent[l], DomesticStudent[largest]) > 0)) || ((type == 'R' || type == 'r') && (compareResearchScore(DomesticStudent[l], DomesticStudent[largest]) > 0)) || ((type == 'P' || type == 'p') && (compareProvince(DomesticStudent[l], DomesticStudent[largest]) > 0))))
//     {
//         largest = l;
//     }

//     // If right child is larger than largest so far
//     if (r < n &&
//         (((type == 'F' || type == 'f') && (compareFirstName(DomesticStudent[r], DomesticStudent[largest]) > 0)) ||
//          ((type == 'L' || type == 'l') && (compareLastName(DomesticStudent[r], DomesticStudent[largest]) > 0)) || ((type == 'G' || type == 'g') && (compareCGPA(DomesticStudent[r], DomesticStudent[largest]) > 0)) || ((type == 'R' || type == 'r') && (compareResearchScore(DomesticStudent[r], DomesticStudent[largest]) > 0)) || ((type == 'P' || type == 'p') && (compareProvince(DomesticStudent[r], DomesticStudent[largest]) > 0))))
//     {
//         largest = r;
//     }

//     // If largest is not root
//     if (largest != i)
//     {
//         Domestic tmpStudent;
//         tmpStudent = DomesticStudent[i];
//         DomesticStudent[i] = DomesticStudent[largest];
//         DomesticStudent[largest] = tmpStudent;

//         // Recursively heapify the affected sub-tree
//         heapify(DomesticStudent, n, largest, type);
//     }
// }

// void heapify(International *InternationalStudent, int n, int i, char type)
// {
//     int largest = i;   // Initialize largest as root
//     int l = 2 * i + 1; // left = 2*i + 1
//     int r = 2 * i + 2; // right = 2*i + 2

//     // If left child is larger than root
//     if (l < n &&
//         (((type == 'F' || type == 'f') && (compareFirstName(InternationalStudent[l], InternationalStudent[largest]) > 0)) ||
//          ((type == 'L' || type == 'l') && (compareLastName(InternationalStudent[l], InternationalStudent[largest]) > 0)) || ((type == 'G' || type == 'g') && (compareCGPA(InternationalStudent[l], InternationalStudent[largest]) > 0)) || ((type == 'R' || type == 'r') && (compareResearchScore(InternationalStudent[l], InternationalStudent[largest]) > 0)) || ((type == 'P' || type == 'p') && (compareCountry(InternationalStudent[l], InternationalStudent[largest]) > 0))))
//     {
//         largest = l;
//     }

//     // If right child is larger than largest so far
//     if (r < n &&
//         (((type == 'F' || type == 'f') && (compareFirstName(InternationalStudent[r], InternationalStudent[largest]) > 0)) ||
//          ((type == 'L' || type == 'l') && (compareLastName(InternationalStudent[r], InternationalStudent[largest]) > 0)) || ((type == 'G' || type == 'g') && (compareCGPA(InternationalStudent[r], InternationalStudent[largest]) > 0)) || ((type == 'R' || type == 'r') && (compareResearchScore(InternationalStudent[r], InternationalStudent[largest]) > 0)) || ((type == 'P' || type == 'p') && (compareCountry(InternationalStudent[r], InternationalStudent[largest]) > 0))))
//     {
//         largest = r;
//     }

//     // If largest is not root
//     if (largest != i)
//     {
//         International tmpStudent;
//         tmpStudent = InternationalStudent[i];
//         InternationalStudent[i] = InternationalStudent[largest];
//         InternationalStudent[largest] = tmpStudent;

//         // Recursively heapify the affected sub-tree
//         heapify(InternationalStudent, n, largest, type);
//     }
// }

// void SingleSort(Domestic *DomesticStudent, int begin, int end, char type)
// // Build heap (rearrange array);
// for (int i = end / 2 - 1; i >= 0; i--)
//     heapify(DomesticStudent, end, i, type);

// // One by one extract an element from heap
// for (int i = end - 1; i > 0; i--)
// {
//     // Move current root to end
//     Domestic tmpStudent;
//     tmpStudent = DomesticStudent[0];
//     DomesticStudent[0] = DomesticStudent[i];
//     DomesticStudent[i] = tmpStudent;

//     // call max heapify on the reduced heap
//     heapify(DomesticStudent, i, 0, type);
// }

// auto mid = begin + (end - begin) / 2;
// if (begin < end)
// {
//     SingleSort(DomesticStudent, begin, mid, type);
//     SingleSort(DomesticStudent, mid + 1, end, type);
// }
// auto const subArrayOne = mid - begin + 1;
// auto const subArrayTwo = end - mid;

// // Create temp arrays
// auto *leftArray = new Domestic[subArrayOne],
//      *rightArray = new Domestic[subArrayTwo];

// // Copy data to temp arrays leftArray[] and rightArray[]
// for (auto i = 0; i < subArrayOne; i++)
//     leftArray[i] = DomesticStudent[begin + i];
// for (auto j = 0; j < subArrayTwo; j++)
//     rightArray[j] = DomesticStudent[mid + 1 + j];

// auto indexOfSubArrayOne = 0,    // Initial index of first sub-array
//     indexOfSubArrayTwo = 0;     // Initial index of second sub-array
// int indexOfMergedArray = begin; // Initial index of merged array

// // Merge the temp arrays back into array[left..right]
// while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
// {
//     if (((type == 'F' || type == 'f') && (compareFirstName(leftArray[indexOfSubArrayOne], rightArray[indexOfSubArrayTwo]) < 0)) || ((type == 'L' || type == 'l') && (compareLastName(leftArray[indexOfSubArrayOne], rightArray[indexOfSubArrayTwo]) < 0)) || ((type == 'G' || type == 'g') && (compareCGPA(leftArray[indexOfSubArrayOne], rightArray[indexOfSubArrayTwo]) < 0)) || ((type == 'R' || type == 'r') && (compareResearchScore(leftArray[indexOfSubArrayOne], rightArray[indexOfSubArrayTwo]) < 0)) || ((type == 'P' || type == 'p') && (compareProvince(leftArray[indexOfSubArrayOne], rightArray[indexOfSubArrayTwo]) < 0)))
//     {
//         DomesticStudent[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
//         indexOfSubArrayOne++;
//     }
//     else
//     {
//         DomesticStudent[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
//         indexOfSubArrayTwo++;
//     }
//     indexOfMergedArray++;
// }
// // Copy the remaining elements of
// // left[], if there are any
// while (indexOfSubArrayOne < subArrayOne)
// {
//     DomesticStudent[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
//     indexOfSubArrayOne++;
//     indexOfMergedArray++;
// }
// // Copy the remaining elements of
// // right[], if there are any
// while (indexOfSubArrayTwo < subArrayTwo)
// {
//     DomesticStudent[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
//     indexOfSubArrayTwo++;
//     indexOfMergedArray++;
// }

// // Build heap (rearrange array)
// for (int i = end / 2 - 1; i >= 0; i--)
//     heapify(InternationalStudent, end, i, type);

// // One by one extract an element from heap
// for (int i = end - 1; i > 0; i--)
// {
//     // Move current root to end
//     International tmpStudent;
//     tmpStudent = InternationalStudent[0];
//     InternationalStudent[0] = InternationalStudent[i];
//     InternationalStudent[i] = tmpStudent;

//     // call max heapify on the reduced heap
//     heapify(InternationalStudent, i, 0, type);
// }

// auto mid = begin + (end - begin) / 2;
// if (begin < end)
// {
//     SingleSort(InternationalStudent, begin, mid, type);
//     SingleSort(InternationalStudent, mid + 1, end, type);
// }
// auto const subArrayOne = mid - begin + 1;
// auto const subArrayTwo = end - mid;

// // Create temp arrays
// auto *leftArray = new International[subArrayOne],
//      *rightArray = new International[subArrayTwo];

// // Copy data to temp arrays leftArray[] and rightArray[]
// for (auto i = 0; i < subArrayOne; i++)
//     leftArray[i] = InternationalStudent[begin + i];
// for (auto j = 0; j < subArrayTwo; j++)
//     rightArray[j] = InternationalStudent[mid + 1 + j];

// auto indexOfSubArrayOne = 0,    // Initial index of first sub-array
//     indexOfSubArrayTwo = 0;     // Initial index of second sub-array
// int indexOfMergedArray = begin; // Initial index of merged array

// // Merge the temp arrays back into array[left..right]
// while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
// {
//     if (((type == 'F' || type == 'f') && (compareFirstName(leftArray[indexOfSubArrayOne], rightArray[indexOfSubArrayTwo]) < 0)) || ((type == 'L' || type == 'l') && (compareLastName(leftArray[indexOfSubArrayOne], rightArray[indexOfSubArrayTwo]) < 0)) || ((type == 'G' || type == 'g') && (compareCGPA(leftArray[indexOfSubArrayOne], rightArray[indexOfSubArrayTwo]) < 0)) || ((type == 'R' || type == 'r') && (compareResearchScore(leftArray[indexOfSubArrayOne], rightArray[indexOfSubArrayTwo]) < 0)) || ((type == 'P' || type == 'p') && (compareCountry(leftArray[indexOfSubArrayOne], rightArray[indexOfSubArrayTwo]) < 0)))
//     {
//         InternationalStudent[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
//         indexOfSubArrayOne++;
//     }
//     else
//     {
//         InternationalStudent[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
//         indexOfSubArrayTwo++;
//     }
//     indexOfMergedArray++;
// }
// // Copy the remaining elements of
// // left[], if there are any
// while (indexOfSubArrayOne < subArrayOne)
// {
//     InternationalStudent[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
//     indexOfSubArrayOne++;
//     indexOfMergedArray++;
// }
// // Copy the remaining elements of
// // right[], if there are any
// while (indexOfSubArrayTwo < subArrayTwo)
// {
//     InternationalStudent[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
//     indexOfSubArrayTwo++;
//     indexOfMergedArray++;
// }

// cout << "File format: " << line << endl;

// cout << "Domestic student " << stu_count << " " << firstName << " "
//      << lastName << " from " << province << " province has cgpa of "
//      << cgpa << ", and research score of " << researchScore << endl;

// cout << endl
//      << "File format: " << line << endl;

// cout << "International student " << stu_inter_count << " " << firstNameInt << " "
//      << lastNameInt << " from " << country << " has cgpa of "
//      << cgpa2 << ", and research score of " << researchScore2
//      << " Reading Score: " << reading << " "
//      << " Listening Score: " << listening << " "
//      << " Speaking Score: " << speaking << " "
//      << " Writing Score: " << writing << endl;
