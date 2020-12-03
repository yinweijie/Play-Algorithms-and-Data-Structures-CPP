#include <array>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "ArrayGenerator.h"
#include "SortingHelper.h"
#include "BubbleSort.h"

using namespace std;

int main()
{
    int n = 10000;

    int* arr = ArrayGenerator::generateRandomArray(n, n);

    SortingHelper::sortTest("BubbleSort", arr, n);
    delete[] arr;

    return 0;
}