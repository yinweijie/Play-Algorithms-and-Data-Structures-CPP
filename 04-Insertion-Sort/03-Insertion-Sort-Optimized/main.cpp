#include <array>
#include "ArrayGenerator.h"
#include "SortingHelper.h"

int main()
{
    std::array<int, 2> dataSize = {10000, 100000};

    for(int n: dataSize)
    {
        int* arr = ArrayGenerator::generateRandomArray(n, n);

        // SortingHelper::sortTest("SelectionSort", arr, n);
        SortingHelper::sortTest("InsertionSort", arr, n);

        delete[] arr;
    }


    return 0;
}