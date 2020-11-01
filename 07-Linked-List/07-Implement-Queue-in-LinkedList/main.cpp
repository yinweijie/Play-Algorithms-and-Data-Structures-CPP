#include <iostream>
#include <chrono>
#include <random>
#include <limits>
#include "LoopQueue.h"
#include "ArrayQueue.h"
#include "LinkedListQueue.h"

using namespace std;

double testQueue(Queue<int>& q, int opCount)
{
    auto startTime = std::chrono::steady_clock::now();

    std::uniform_int_distribution<int> u(0, std::numeric_limits<int>::max());
    std::default_random_engine e(time(0));

    for(int i = 0; i < opCount; ++i)
    {
        q.enqueue(u(e));
    }
    for(int i = 0; i < opCount; ++i)
    {
        q.dequeue();
    }

    auto endTime = std::chrono::steady_clock::now();
    std::chrono::duration<double> time = endTime - startTime;

    return time.count();
}

int main()
{
    int opCount = 100000;

    ArrayQueue<int> arrayQueue;
    double time1 = testQueue(arrayQueue, opCount);
    cout << "ArrayQueue, time: " << time1 << " s" << endl;

    LoopQueue<int> loopQueue;
    double time2 = testQueue(loopQueue, opCount);
    cout << "LoopQueue, time: " << time2 << " s" << endl;

    LinkedListQueue<int> linkedListQueue;
    double time3 = testQueue(linkedListQueue, opCount);
    cout << "LoopQueue, time: " << time3 << " s" << endl;

    return 0;
}