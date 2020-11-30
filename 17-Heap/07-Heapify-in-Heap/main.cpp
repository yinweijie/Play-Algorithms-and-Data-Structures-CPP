#include <random>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include "MaxHeap.h"

using namespace std;

double testHeap(vector<int>& testData, bool isHeapify)
{
    auto start = std::chrono::steady_clock::now();

    MaxHeap<int>* maxHeap;
    if(isHeapify)
    {
        maxHeap = new MaxHeap<int>(testData);
    }
    else
    {
        maxHeap = new MaxHeap<int>(testData.size());
        for(auto num: testData)
        {
            maxHeap->add(num);
        }
    }

    vector<int> arr;
    arr.reserve(testData.size());
    for(int i = 0; i < testData.size(); i++)
    {
        // extractMax() 函数比较耗时(O(log(n))，把两种排序时间差距掩盖了
        arr.emplace_back(maxHeap->extractMax());
    }

    for(int i = 1; i < testData.size(); i++)
    {
        if(arr[i - 1] < arr[i])
        {
            throw std::invalid_argument("Error");
        }
    }

    cout << "Test MaxHeap completed." << endl;

    delete maxHeap;
    auto end = std::chrono::steady_clock::now();

    std::chrono::duration<double> time = end - start;

    return time.count();
}

int main()
{
    int n = 1000000;

    std::uniform_int_distribution<int> u(0, std::numeric_limits<int>::max());
    std::default_random_engine e(time(0));

    vector<int> testData;
    testData.reserve(n);
    for(int i = 0; i < n; i++)
    {
        testData.emplace_back(u(e));
    }

    vector<int> testData2 = testData;

    double time1 = testHeap(testData, false);
    cout << "Without heapify: " << time1 << " s" << endl;

    double time2 = testHeap(testData2, true);
    cout << "With heapify: " << time2 << " s" << endl;

    return 0;
}