#include <array>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "ArrayGenerator.h"
#include "SortingHelper.h"

using namespace std;

int main()
{
    int n = 100000, w = 200;

    string* arr = ArrayGenerator::generateRandomStringArray(n, w);
    int* arr2 = new int[n];
    int* arr3 = new int[n];
    std::copy(arr, arr + n, arr2);
    std::copy(arr, arr + n, arr3);

    SortingHelper::sortTest("QuickSort", arr, n);
    SortingHelper::sortTest("LSDSort", arr2, n);
    SortingHelper::sortTest("QuickSort3Ways", arr3, n);
    delete[] arr;
    delete[] arr2;
    delete[] arr3;

    return 0;
}