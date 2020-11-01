#include <iostream>
#include <chrono>
#include <random>
#include <limits>
#include "Stack.h"
#include "ArrayStack.h"
#include "LinkedListStack.h"

using namespace std;

double testQueue(Stack<int>& stack, int opCount)
{
    auto startTime = std::chrono::steady_clock::now();

    std::uniform_int_distribution<int> u(0, std::numeric_limits<int>::max());
    std::default_random_engine e(time(0));

    for(int i = 0; i < opCount; ++i)
    {
        stack.push(u(e));
    }
    for(int i = 0; i < opCount; ++i)
    {
        stack.pop();
    }

    auto endTime = std::chrono::steady_clock::now();
    std::chrono::duration<double> time = endTime - startTime;

    return time.count();
}

int main()
{
    // LinkedListStack<int> linkedListStack;
    // for(int i = 0; i < 5; i++)
    // {
    //     linkedListStack.push(i);
    //     cout << linkedListStack << endl;
    // }

    int opCount = 1000000;

    ArrayStack<int> arrayStack;
    double time1 = testQueue(arrayStack, opCount);
    cout << "ArrayQueue, time: " << time1 << " s" << endl;

    LinkedListStack<int> linkedListStack;
    double time2 = testQueue(linkedListStack, opCount);
    cout << "LoopQueue, time: " << time2 << " s" << endl;

    return 0;
}