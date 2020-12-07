#ifndef __MERGESORT_H__
#define __MERGESORT_H__

#include <algorithm>
#include <iostream>

using namespace std;

class MergeSort
{
private:
    MergeSort() { }
public:
    // 自底向上的归并排序
    template <typename T>
    static void sortBU(T arr[], int n)
    {
        T* tmp = new T[n];

        // 遍历合并的区间长度
        // 遍历合并的两个区间的起始位置 i
        // 合并 [i, i + sz - 1] 和 [i + sz, Math.min(i + sz + sz - 1, n - 1)]
        for(int sz = 1; sz < n; sz += sz)
        {
            for(int i = 0; i + sz < n; i += sz + sz)
            {
                merge(arr, i, i + sz - 1, std::min(i + sz + sz - 1, n - 1), tmp);
            }
        }

        delete[] tmp;
    }

public:
    // 自顶向下的归并排序
    template <typename T>
    static void sort(T arr[], int n)
    {
        T* tmp = new T[n];

        sort(arr, 0, n - 1, tmp);

        delete[] tmp;
    }

private:
    template <typename T>
    static void sort(T arr[], int l, int r, T tmp[])
    {
        if(l >= r)
        {
            return;
        }

        int mid = l + (r - l) / 2;
        sort(arr, l, mid, tmp);
        sort(arr, mid + 1, r, tmp);

        if(arr[mid] > arr[mid + 1])
        {
            merge(arr, l, mid, r, tmp);
        }
    }

    // 合并两个有序的区间 arr[l, mid] 和 arr[mid + 1, r]
    template <typename T>
    static void merge(T arr[], int l, int mid, int r, T tmp[])
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