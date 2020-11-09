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
};

#endif