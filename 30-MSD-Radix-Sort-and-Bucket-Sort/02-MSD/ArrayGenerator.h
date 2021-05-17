#ifndef __ARRAYGENERATOR_H__
#define __ARRAYGENERATOR_H__

#include <random>
#include <cstdlib>
#include <ctime>
#include <string>

using std::string;

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

    static string* generateRandomStringArray(int n, int w)
    {
        // https://www.ascii-code.com/
        // 33-126 可打印字符
        string* arr = new string[n];
        std::uniform_int_distribution<int> u(33, 126);
        std::default_random_engine e(time(0));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < w; j++)
            {
                arr[i] += static_cast<char>(u(e));
            }
        }

        return arr;
    }
};

#endif