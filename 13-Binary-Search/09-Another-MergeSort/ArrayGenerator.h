#ifndef __ARRAYGENERATOR_H__
#define __ARRAYGENERATOR_H__

#include <random>
#include <cstdlib>
#include <ctime>

class ArrayGenerator
{
private:
    ArrayGenerator() { }
public:
    static int* generateOrderedArray(int n)
    {
        int* arr = new int[n];

        for(int i = 0; i < n; ++i)
        {
            arr[i] = i;
        }

        return arr;
    }

    // 生成一个长度为 n 的随机数组，每个数字的范围是 [0, bound)
    static int* generateRandomArray(int n, int bound)
    {
        int* arr = new int[n];

        std::uniform_int_distribution<int> u(0, bound - 1);
        std::default_random_engine e(time(0));
        for(int i = 0; i < n; ++i)
        {
            arr[i] = u(e);
        }

        return arr;
    }

    // 针对以中间点为标定点的快速排序，生成一个特殊的测试用例
    // 使得这样的快速排序产生退化
    static int* generateSpecialArray(int n)
    {
        int* arr = new int[n];
        generateSpecialArray(arr, 0, n - 1, 0);
        return arr;
    }

    static void generateSpecialArray(int arr[], int l, int r, int value)
    {
        if(l > r) return;

        int mid = (l + r) / 2;
        arr[mid] = value;

        swap(arr, mid, l);
        generateSpecialArray(arr, l + 1, r, value + 1);
        swap(arr, mid, l);
    }

    template <typename T>
    static void swap(T arr[], int i, int j)
    {
        T t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
};

#endif