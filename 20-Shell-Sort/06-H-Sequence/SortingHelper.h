#ifndef __SORTINGHELPER_H__
#define __SORTINGHELPER_H__

#include <iostream>
#include <string>
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "BubbleSort.h"
#include "ShellSort.h"

using namespace std;

class SortingHelper
{
private:
    SortingHelper() { }
public:
    template <typename T>
    static bool isSorted(T arr[], int n)
    {
        for(int i = 1; i < n; i++)
        {
            if(arr[i - 1] > arr[i])
            {
                return false;
            }
        }

        return true;
    }

    template <typename T>
    static void sortTest(const string& sortname, T arr[], int n)
    {
        auto start = std::chrono::steady_clock::now();

        if(sortname.compare("SelectionSort") == 0)
        {
            SelectionSort::sort(arr, n);
        }
        else if(sortname.compare("InsertionSort") == 0)
        {
            InsertionSort::sort(arr, n);
        }
        else if(sortname.compare("MergeSort") == 0)
        {
            MergeSort::sort(arr, n);
        }
        else if(sortname.compare("MergeSortBU") == 0)
        {
            MergeSort::sortBU(arr, n);
        }
        else if(sortname.compare("QuickSort") == 0)
        {
            QuickSort::sort(arr, n);
        }
        else if(sortname.compare("QuickSort2Ways") == 0)
        {
            QuickSort::sort2ways(arr, n);
        }
        else if(sortname.compare("QuickSort3Ways") == 0)
        {
            QuickSort::sort3ways(arr, n);
        }
        else if(sortname.compare("HeapSort") == 0)
        {
            HeapSort::sort(arr, n);
        }
        else if(sortname.compare("BubbleSort") == 0)
        {
            BubbleSort::sort(arr, n);
        }
        else if(sortname.compare("ShellSort") == 0)
        {
            ShellSort::sort(arr, n);
        }
        else if(sortname.compare("ShellSort2") == 0)
        {
            ShellSort::sort2(arr, n);
        }

        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> time = end - start;

        if(!SortingHelper::isSorted(arr, n))
        {
            throw std::runtime_error(sortname + " Failed");
        }

        cout << sortname << ", n = " << n << " : " << time.count() << " s" << endl;
    }
};

#endif