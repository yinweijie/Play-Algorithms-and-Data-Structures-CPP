#ifndef __MERGESORT_H__
#define __MERGESORT_H__

#include <algorithm>
#include <iostream>

using namespace std;

class MergeSort
{
public:
    template <typename T>
    static void sort(T arr[], int n)
    {
        sort(arr, 0, n - 1);
    }

private:
    template <typename T>
    static void sort(T arr[], int l, int r)
    {
        if(l >= r)
        {
            return;
        }

        int mid = l + (r - l) / 2;
        sort(arr, l, mid);
        sort(arr, mid + 1, r);

        if(arr[mid] > arr[mid + 1])
        {
            merge(arr, l, mid, r);
        }
    }

    // 合并两个有序的区间 arr[l, mid] 和 arr[mid + 1, r]
    template <typename T>
    static void merge(T arr[], int l, int mid, int r)
    {
        int n = r - l + 1;
        T* tmp = new T[n];
        std::copy(arr + l, arr + r + 1, tmp); // 注意索引对应关系

        int i = l, j = mid + 1;

        for(int k = l; k <= r; k++)
        {
            if(i > mid)
            {
                arr[k] = tmp[j - l]; // temp索引从0开始，arr索引从l开始
                j++;
            }
            else if(j > r)
            {
                arr[k] = tmp[i - l];
                i++;
            }
            else if(tmp[i - l] <= tmp[j - l])
            {
                arr[k] = tmp[i - l];
                i++;
            }
            else
            {
                arr[k] = tmp[j - l];
                j++;
            }
        }

        delete[] tmp;
    }

public:
    template <typename T>
    static void sort2(T arr[], int n)
    {
        T* tmp = new T[n];

        sort2(arr, 0, n - 1, tmp);

        delete[] tmp;
    }

private:
    template <typename T>
    static void sort2(T arr[], int l, int r, T tmp[])
    {
        if(l >= r)
        {
            return;
        }

        int mid = l + (r - l) / 2;
        sort2(arr, l, mid, tmp);
        sort2(arr, mid + 1, r, tmp);

        if(arr[mid] > arr[mid + 1])
        {
            merge2(arr, l, mid, r, tmp);
        }
    }

    // 合并两个有序的区间 arr[l, mid] 和 arr[mid + 1, r]
    template <typename T>
    static void merge2(T arr[], int l, int mid, int r, T tmp[])
    {
        std::copy(arr + l, arr + r + 1, tmp + l);

        int i = l, j = mid + 1;

        for(int k = l; k <= r; k++)
        {
            if(i > mid)
            {
                arr[k] = tmp[j];
                j++;
            }
            else if(j > r)
            {
                arr[k] = tmp[i];
                i++;
            }
            else if(tmp[i] <= tmp[j])
            {
                arr[k] = tmp[i];
                i++;
            }
            else
            {
                arr[k] = tmp[j];
                j++;
            }
        }
    }
};

#endif