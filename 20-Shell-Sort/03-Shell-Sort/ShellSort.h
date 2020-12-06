#ifndef __SHELLSORT_H__
#define __SHELLSORT_H__

#include <iostream>

class ShellSort
{
private:
    ShellSort() { }

public:
    template <typename T, int N>
    static void sort(T(&arr)[N])
    {
        int h = N / 2;

        while(h >= 1)
        {
            for(int start = 0; start < h; start++)
            {
                // 对 data[start, start + h, start + 2h, start + 3h ...], 进行插入排序
                for(int i = start + h; i < N; i += h)
                {
                    T t = arr[i];
                    int j;
                    for(j = i; j - h >= start && arr[j - h] > t; j -= h)
                    {
                        arr[j] = arr[j - h];
                    }
                    arr[j] = t;
                }
            }

            h /= 2;
        }
    }
};

#endif