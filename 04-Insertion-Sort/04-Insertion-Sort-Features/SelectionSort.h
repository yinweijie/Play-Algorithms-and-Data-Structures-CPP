#ifndef __SELECTIONSORT_H__
#define __SELECTIONSORT_H__

#include <iostream>
#include <chrono>
#include "ArrayGenerator.h"
#include "SortingHelper.h"

using namespace std;

class SelectionSort
{
private:
    SelectionSort() { }

    template <typename T>
    static void swap(T arr[], int i, int j)
    {
        T t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
public:
    template <typename T>
    static void sort(T arr[], int n)
    {
        // arr[0...i) 是有序的；arr[i...n) 是无序的
        for(int i = 0; i < n; i++)
        {
            // 选择 arr[i...n) 中的最小值的索引
            int minIndex = i;
            for(int j = i; j < n; j++)
            {
                if(arr[j] < arr[minIndex])
                {
                    minIndex = j;
                }
            }

            swap(arr, minIndex, i);
        }
    }
    template <typename T>
    static void sort2(T arr[], int n)
    {
        // arr[0...i) 是无序的；arr[i...n) 是有序的
        for(int i = n - 1; i >= 0; i--)
        {
            // 选择 arr[0...i] 中的最大值的索引
            int maxIndex = i;
            for(int j = i; j >= 0; j--)
            {
                if(arr[j] > arr[maxIndex])
                {
                    maxIndex = j;
                }
            }

            swap(arr, maxIndex, i);
        }
    }
};

#endif