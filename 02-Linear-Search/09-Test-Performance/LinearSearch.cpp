#include <iostream>
#include <chrono>
#include <array>
#include "ArrayGenerator.h"

using namespace std;
using namespace chrono;


class LinearSearch
{
private:
    LinearSearch() { }
public:
    template <typename T>
    static int search(T data[], int n, T target)
    {
        for(int i = 0; i < n; i++)
        {
            if(data[i] == target)
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    // int n = 10000;
    // int* data = ArrayGenerator::generateOrderedArray(n);

    // auto start = std::chrono::steady_clock::now();

    // for(int i = 0; i < 100; ++i)
    // {
    //     LinearSearch::search(data, n, n);
    // }

    // auto end = std::chrono::steady_clock::now();
    // std::chrono::duration<double> time = end - start;

    // cout << "n = " << n << " , 100 runs : " << time.count() << "s" << endl;

    std::array<int, 2> dataSize = {1000000, 10000000};
    for(int n: dataSize)
    {
        int* data = ArrayGenerator::generateOrderedArray(n);

        auto start = std::chrono::steady_clock::now();

        for(int i = 0; i < 100; ++i)
        {
            LinearSearch::search(data, n, n);
        }

        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> time = end - start;

        cout << "n = " << n << " , 100 runs : " << time.count() << "s" << endl;

    }

    return 0;
}