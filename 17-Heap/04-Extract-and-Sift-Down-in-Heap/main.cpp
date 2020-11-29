#include <iostream>
#include <random>
#include <limits>
#include <array>
#include "MaxHeap.h"

using namespace std;

int main()
{
    constexpr int n = 1000000;

    MaxHeap<int> maxHeap;
    std::uniform_int_distribution<int> u(0, std::numeric_limits<int>::max());
    std::default_random_engine e(time(0));
    for(int i = 0; i < n; i++)
    {
        maxHeap.add(u(e));
    }

    array<int, n> arr;
    for(int i = 0; i < n; i++)
    {
        arr[i] = maxHeap.extractMax();
    }

    for(int i = 1; i < n; i++)
    {
        if(arr[i] < arr[i - 1])
        {
            throw std::invalid_argument("Error");
        }
    }

    cout << "Test MaxHeap completed." << endl;

    return 0;
}