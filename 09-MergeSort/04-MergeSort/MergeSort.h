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
        merge(arr, l, mid, r);
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
};

#endif