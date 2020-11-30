#include <array>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "ArrayGenerator.h"
#include "SortingHelper.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "HeapSort.h"

using namespace std;

int main()
{
    int n = 1000000;

    int* arr = ArrayGenerator::generateRandomArray(n, n);
    int* arr2 = new int[n];
    int* arr3 = new int[n];
    int* arr4 = new int[n];
    std::copy(arr, arr + n, arr2);
    std::copy(arr, arr + n, arr3);
    std::copy(arr, arr + n, arr4);

    SortingHelper::sortTest("MergeSort", arr, n);
    SortingHelper::sortTest("QuickSort2Ways", arr2, n);
    SortingHelper::sortTest("QuickSort3Ways", arr3, n);
    SortingHelper::sortTest("HeapSort", arr4, n);
    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    return 0;
}