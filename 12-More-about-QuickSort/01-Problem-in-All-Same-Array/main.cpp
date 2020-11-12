#include <array>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "ArrayGenerator.h"
#include "SortingHelper.h"
#include "MergeSort.h"
#include "QuickSort.h"

using namespace std;

int main()
{
    int n = 100000;

    int* arr = ArrayGenerator::generateRandomArray(n, n);
    SortingHelper::sortTest("QuickSort", arr, n);
    delete[] arr;

    arr = ArrayGenerator::generateOrderedArray(n);
    SortingHelper::sortTest("QuickSort", arr, n);
    delete[] arr;

    arr = ArrayGenerator::generateRandomArray(n, 1);
    SortingHelper::sortTest("QuickSort", arr, n);
    delete[] arr;

    return 0;
}