#include <array>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "ArrayGenerator.h"
#include "SortingHelper.h"

using namespace std;

int main()
{
    int n = 5000000;

    int* arr = ArrayGenerator::generateRandomArray(n, n);
    int* arr2 = new int[n];
    std::copy(arr, arr + n, arr2);

    cout << "Random Array" << endl;
    SortingHelper::sortTest("ShellSort", arr, n);
    SortingHelper::sortTest("ShellSort2", arr2, n);
    delete[] arr;
    delete[] arr2;

    return 0;
}