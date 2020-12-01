#ifndef __PRIORITYQUEUE_H__
#define __PRIORITYQUEUE_H__

#include "Queue.h"
#include "MaxHeap.h"

template <typename T>
class PriorityQueue : public Queue<T>
{
private:
    MaxHeap<T> maxHeap;

public:
    PriorityQueue() = default;

    int getSize() override
    {
        return maxHeap.size();
    }

    bool isEmpty() override
    {
        return maxHeap.isEmpty();
    }

    void enqueue(T e) override
    {
        maxHeap.add(e);
    }

    T dequeue() override
    {
        maxHeap.extractMax();
    }

    T getFront() override
    {
        return maxHeap.findMax();
    }
};

#endif