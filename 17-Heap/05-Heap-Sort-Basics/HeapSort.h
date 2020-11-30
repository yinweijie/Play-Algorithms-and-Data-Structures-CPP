#ifndef __HEAPSORT_H__
#define __HEAPSORT_H__

#include "MaxHeap.h"

class HeapSort
{
private:
    HeapSort() { }

public:
    template <typename T>
    static void sort(T arr[], int n)
    {
        MaxHeap<T> maxHeap;
        for(int i = 0; i < n; i++)
        {
            maxHeap.add(arr[i]);
        }

        for(int i = n - 1; i >= 0; i--)
        {
            arr[i] = maxHeap.extractMax();
        }
    }
};

#endif