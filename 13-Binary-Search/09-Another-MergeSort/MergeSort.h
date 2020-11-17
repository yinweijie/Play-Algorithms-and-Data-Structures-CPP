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
    // 自顶向下的归并排序
    template <typename T>
    static void sort(T arr[], int n)
    {
        T* tmp = new T[n];

        sort(arr, 0, n, tmp); // n - 1改成n

        delete[] tmp;
    }

private:
    // 对 arr[l, r) 范围进行排序
    template <typename T>
    static void sort(T arr[], int l, int r, T tmp[])
    {
        if(r - l <= 1) // l >= r改成r - l < = 1
        {
            return;
        }

        int mid = l + (r - l) / 2;
        sort(arr, l, mid, tmp); // 语义有改变，变为对arr[l, mid)进行排序
        sort(arr, mid, r, tmp); // mid + 1改成mid

        if(arr[mid - 1] > arr[mid]) // arr[mid] > arr[mid + 1]改成arr[mid - 1] > arr[mid]
        {
            merge(arr, l, mid, r, tmp);
        }
    }

    // 合并 arr[l, mid) 和 arr[mid, r) 两个区间的元素
    template <typename T>
    static void merge(T arr[], int l, int mid, int r, T tmp[])
    {
        std::copy(arr + l, arr + r, tmp + l); // arr + r + 1改为arr + r

        int i = l, j = mid; // mid + 1改为mid

        for(int k = l; k < r; k++) // k <= r改成k < r
        {
            if(i >= mid) // i > mid改成i >= mid
            {
                arr[k] = tmp[j];
                j++;
            }
            else if(j >= r) // j > r改成j >= r
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