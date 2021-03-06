#ifndef __SORTINGHELPER_H__
#define __SORTINGHELPER_H__

#include <iostream>
#include <string>
#include <chrono>
#include "MergeSort.h"

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

        if(sortname.compare("MergeSort") == 0)
        {
            MergeSort::sort(arr, n);
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