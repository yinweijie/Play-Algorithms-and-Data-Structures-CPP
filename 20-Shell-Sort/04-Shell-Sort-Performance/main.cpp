#include <array>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "ArrayGenerator.h"
#include "SortingHelper.h"

using namespace std;

int main()
{
    int n = 1000000;

    int* arr = ArrayGenerator::generateRandomArray(n, n);
    int* arr2 = new int[n];
    int* arr3 = new int[n];
    std::copy(arr, arr + n, arr2);
    std::copy(arr, arr + n, arr3);

    cout << "Random Array" << endl;
    // SortingHelper::sortTest("BubbleSort", arr, n);
    SortingHelper::sortTest("ShellSort", arr2, n);
    SortingHelper::sortTest("MergeSort", arr3, n);
    delete[] arr;
    delete[] arr2;
    delete[] arr3;

    return 0;
}