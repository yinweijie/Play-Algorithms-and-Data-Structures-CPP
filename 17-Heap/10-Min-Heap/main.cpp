#include <iostream>
#include <random>
#include <limits>
#include <array>
#include "MinHeap.h"

using namespace std;

int main()
{
    constexpr int n = 1000000;

    MinHeap<int> minHeap;
    std::uniform_int_distribution<int> u(0, std::numeric_limits<int>::max());
    std::default_random_engine e(time(0));
    for(int i = 0; i < n; i++)
    {
        minHeap.add(u(e));
    }

    array<int, n> arr;
    for(int i = 0; i < n; i++)
    {
        arr[i] = minHeap.extractMin();
    }

    for(int i = 1; i < n; i++)
    {
        if(arr[i - 1] > arr[i])
        {
            throw std::invalid_argument("Error");
        }
    }

    cout << "Test MaxHeap completed." << endl;

    return 0;
}