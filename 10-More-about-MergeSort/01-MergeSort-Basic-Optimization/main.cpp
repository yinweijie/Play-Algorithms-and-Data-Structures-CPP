#include <array>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "ArrayGenerator.h"
#include "SortingHelper.h"
#include "MergeSort.h"

using namespace std;

int main()
{
    int n = 100000;

    cout << "Random Array : " << endl;

    int* arr = ArrayGenerator::generateRandomArray(n, n);
    int arr2[n];
    std::copy(arr, arr + n, arr2);

    SortingHelper::sortTest("MergeSort", arr, n);
    SortingHelper::sortTest("MergeSort2", arr2, n);

    delete[] arr;

    cout << "Ordered Array : " << endl;

    arr = ArrayGenerator::generateOrderedArray(n);
    std::copy(arr, arr + n, arr2);

    SortingHelper::sortTest("MergeSort", arr, n);
    SortingHelper::sortTest("MergeSort2", arr2, n);

    delete[] arr;

    return 0;
}