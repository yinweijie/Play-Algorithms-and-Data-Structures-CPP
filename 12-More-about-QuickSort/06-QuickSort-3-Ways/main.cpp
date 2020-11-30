/*
 * @Author: your name
 * @Date: 2020-11-30 20:50:00
 * @LastEditTime: 2020-11-30 20:50:00
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: /Play-Algorithms-and-Data-Structures-CPP/12-More-about-QuickSort/06-QuickSort-3-Ways/main.cpp
 */
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
    int n = 1000000;

    int* arr = ArrayGenerator::generateRandomArray(n, n);
    int* arr2 = new int[n];
    int* arr3 = new int[n];
    std::copy(arr, arr + n, arr2);
    std::copy(arr, arr + n, arr3);

    cout << "Random Array" << endl;
    SortingHelper::sortTest("QuickSort", arr, n);
    SortingHelper::sortTest("QuickSort2Ways", arr2, n);
    SortingHelper::sortTest("QuickSort3Ways", arr3, n);
    delete[] arr;
    delete[] arr2;
    delete[] arr3;

    arr = ArrayGenerator::generateOrderedArray(n);
    arr2 = new int[n];
    arr3 = new int[n];
    std::copy(arr, arr + n, arr2);
    std::copy(arr, arr + n, arr3);

    cout << "Ordered Array" << endl;
    SortingHelper::sortTest("QuickSort", arr, n);
    SortingHelper::sortTest("QuickSort2Ways", arr2, n);
    SortingHelper::sortTest("QuickSort3Ways", arr3, n);
    delete[] arr;
    delete[] arr2;
    delete[] arr3;

    arr = ArrayGenerator::generateRandomArray(n, 1);
    arr2 = new int[n];
    arr3 = new int[n];
    std::copy(arr, arr + n, arr2);
    std::copy(arr, arr + n, arr3);

    cout << "Same Value Array" << endl;
    // SortingHelper::sortTest("QuickSort", arr, n);
    SortingHelper::sortTest("QuickSort2Ways", arr2, n);
    SortingHelper::sortTest("QuickSort3Ways", arr3, n);
    delete[] arr;
    delete[] arr2;
    delete[] arr3;

    return 0;
}