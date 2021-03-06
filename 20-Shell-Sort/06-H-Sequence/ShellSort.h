#ifndef __SHELLSORT_H__
#define __SHELLSORT_H__

#include <iostream>

class ShellSort
{
private:
    ShellSort() { }

public:
    template <typename T>
    static void sort(T arr[], int n)
    {
        int h = n / 2;

        while(h >= 1)
        {
            for(int i = h; i < n; i++)
            {
                int t = arr[i];
                int j;
                for(j = i; j - h >= 0 && arr[j - h] > t; j -= h)
                {
                    arr[j] = arr[j - h];
                }
                arr[j] = t;
            }

            h /= 2;
        }
    }

    template <typename T>
    static void sort2(T arr[], int n)
    {
        int h = 1;
        while(h < n)
        {
            h = h * 3 + 1;
        }
        // 1, 4, 13, 40 ...

        while(h >= 1)
        {
            for(int i = h; i < n; i++)
            {
                int t = arr[i];
                int j;
                for(j = i; j - h >= 0 && arr[j - h] > t; j -= h)
                {
                    arr[j] = arr[j - h];
                }
                arr[j] = t;
            }

            h /= 3;
        }
    }
};

#endif