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

    template <typename T>
    static void sort2(T arr[], int n)
    {
        // Heapify
        for(int i = (n - 2) / 2; i >= 0; i--)
        {
            siftDown(arr, i, n);
        }

        for(int i = n - 1; i >= 0; i--)
        {
            swap(arr, 0, i);
            siftDown(arr, 0, i);
        }
    }

private:
    // 对 data[0, n) 所形成的最大堆中，索引 k 的元素，执行 siftDown
    template <typename T>
    static void siftDown(T data[], int k, int n)
    {
        while(k * 2 + 1 < n)
        {
            int j = k * 2 + 1;
            if(j + 1 < n && data[j + 1] > data[j])
            {
                j++;
            }

            if(data[k] >= data[j])
            {
                break;
            }

            swap(data, k, j);
            k = j;
        }
    }

    template <typename T>
    static void swap(T data[], int i, int j)
    {
        T tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
    }
};

#endif