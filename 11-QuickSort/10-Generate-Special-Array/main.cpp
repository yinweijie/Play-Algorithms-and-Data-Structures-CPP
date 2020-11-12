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
    int* arr2 = new int[n];
    std::copy(arr, arr + n, arr2);

    cout << "Random Array" << endl;
    SortingHelper::sortTest("QuickSort", arr, n);
    SortingHelper::sortTest("QuickSort2", arr2, n);

    delete[] arr;
    delete[] arr2;

    arr = ArrayGenerator::generateOrderedArray(n);
    arr2 = new int[n];
    std::copy(arr, arr + n, arr2);

    cout << "Ordered Array" << endl;
    SortingHelper::sortTest("QuickSort", arr, n);
    SortingHelper::sortTest("QuickSort2", arr2, n);

    delete[] arr;
    delete[] arr2;

    arr = ArrayGenerator::generateSpecialArray(n);
    arr2 = new int[n];
    std::copy(arr, arr + n, arr2);

    cout << "Special Array" << endl;
    SortingHelper::sortTest("QuickSort", arr, n);
    SortingHelper::sortTest("QuickSort2", arr2, n);

    delete[] arr;
    delete[] arr2;

    return 0;
}