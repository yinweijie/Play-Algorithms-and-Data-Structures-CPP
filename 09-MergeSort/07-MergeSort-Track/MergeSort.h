#ifndef __MERGESORT_H__
#define __MERGESORT_H__

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class MergeSort
{
public:
    template <typename T>
    static void sort(T arr[], int n)
    {
        sort(arr, 0, n - 1, 0, n);
    }

private:
    template <typename T>
    static void sort(T arr[], int l, int r, int depth, int n)
    {
        string depthString = generateDepthString(depth);
        cout << depthString;
        cout << "mergesort arr[" << l << ", " << r << "]" << endl;

        if(l >= r)
        {
            return;
        }

        int mid = l + (r - l) / 2;
        sort(arr, l, mid, depth + 1, n);
        sort(arr, mid + 1, r, depth + 1, n);

        cout << depthString;
        cout << "merge arr[" << l << ", " << mid << "]" << " and arr[" << mid + 1 << ", " << r << "]" << endl;

        merge(arr, l, mid, r);
        cout << depthString;
        cout << "after mergesort arr[" << l << ", " << r << "] : ";
        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    static string generateDepthString(int depth)
    {
        string s;
        for(int i = 0; i < depth; i++)
        {
            s += "--";
        }

        return s;
    }

    // 合并两个有序的区间 arr[l, mid] 和 arr[mid + 1, r]
    template <typename T>
    static void merge(T arr[], int l, int mid, int r)
    {
        int n = r - l + 1;
        T tmp[n];
        std::copy(arr + l, arr + r + 1, tmp);

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
    }
};

#endif