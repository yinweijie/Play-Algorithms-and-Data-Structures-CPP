#ifndef __ARRAYQUEUE_H__
#define __ARRAYQUEUE_H__

#include "Queue.h"
#include "Array.h"

template <typename T>
class ArrayQueue : public Queue<T>
{
private:
    Array<T> array;

    friend ostream& operator<<(ostream& os, const ArrayQueue<T>& queue)
    {
        os << "Queue: front [";

        for(int i = 0; i < queue.array.getSize(); i++)
        {
            os << queue.array.get(i);
            if(i != queue.array.getSize() - 1)
            {
                os << ", ";
            }
        }

        os << "] tail";

        return os;
    }
public:
    ArrayQueue(int capacity = 10) : array(capacity) { }

    int getSize() override
    {
        return array.getSize();
    }

    bool isEmpty() override
    {
        return array.isEmpty();
    }

    int getCapacity()
    {
        return array.getCapacity();
    }

    void enqueue(T e) override
    {
        array.addLast(e);
    }

    T dequeue() override
    {
        return array.removeFirst();
    }

    T getFront() override
    {
        return array.getFirst();
    }
};

#endif