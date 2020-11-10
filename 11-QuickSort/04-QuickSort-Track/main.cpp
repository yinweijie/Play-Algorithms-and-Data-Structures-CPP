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
    int arr[] = {7, 1, 4, 2, 8, 3, 6, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    SortingHelper::sortTest("QuickSort", arr, n);

    return 0;
}