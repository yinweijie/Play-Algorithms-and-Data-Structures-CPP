#include <iostream>
#include <chrono>
#include "Array.h"
#include "LinkedList.h"

using namespace std;

int main()
{
    // 创建一个动态数组，再创建一个链表
    Array<int> array;
    LinkedList<int> list;

    // 对于 1000 万规模的数据
    int n = 10000000;
    cout << "n = " << n << endl;

    // 计时，看将 1000 万个元素放入数组中，时间是多少
    auto startTime = std::chrono::steady_clock::now();

    // 对于数组，我们使用 addLast，每一次操作时间复杂度都是 O(1) 的
    for(int i = 0; i < n; i++)
    {
        array.addLast(i);
    }

    auto endTime = std::chrono::steady_clock::now();
    std::chrono::duration<double> time = endTime - startTime;

    cout << "Array: " << time.count() << " s" << endl;

    // 计时，看将 1000 万个元素放入链表中，时间是多少
    startTime = std::chrono::steady_clock::now();

    // 对于数组，我们使用 addLast，每一次操作时间复杂度都是 O(1) 的
    for(int i = 0; i < n; i++)
    {
        list.addFirst(i);
    }

    endTime = std::chrono::steady_clock::now();
    time = endTime - startTime;

    cout << "LinkedList: " << time.count() << " s" << endl;

    return 0;
}