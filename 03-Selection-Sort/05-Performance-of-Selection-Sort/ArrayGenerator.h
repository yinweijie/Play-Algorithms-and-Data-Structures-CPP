#ifndef __ARRAYGENERATOR_H__
#define __ARRAYGENERATOR_H__

#include <random>

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

    static int* generateRandomArray(int n, int bound)
    {
        int* arr = new int[n];

        std::uniform_int_distribution<int> u(0, bound - 1);
        std::default_random_engine e;
        for(int i = 0; i < n; ++i)
        {
            arr[i] = u(e);
        }

        return arr;
    }
};

#endif