#include <iostream>
#include "SortingHelper.h"

using namespace std;

int main()
{
    int arr[] = {7, 1, 4, 2, 8, 3, 6, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    SortingHelper::sortTest("MergeSort", arr, n);
    return 0;
}