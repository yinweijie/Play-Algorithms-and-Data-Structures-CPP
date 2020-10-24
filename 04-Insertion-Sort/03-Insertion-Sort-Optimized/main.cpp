#include <array>
#include <algorithm>
#include <iterator>
#include "ArrayGenerator.h"
#include "SortingHelper.h"

int main()
{
    std::array<int, 2> dataSize = {10000, 100000};

    for(int n: dataSize)
    {
        int* arr = ArrayGenerator::generateRandomArray(n, n);
        int arr2[n];
        std::copy(arr, arr + n, arr2);

        SortingHelper::sortTest("InsertionSort", arr, n);
        SortingHelper::sortTest("InsertionSort2", arr2, n);

        delete[] arr;
    }


    return 0;
}