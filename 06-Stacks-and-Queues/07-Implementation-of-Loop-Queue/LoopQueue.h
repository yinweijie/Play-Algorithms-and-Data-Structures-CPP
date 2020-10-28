#ifndef __LOOPQUEUE_H__
#define __LOOPQUEUE_H__

#include <iostream>
#include "Queue.h"

using namespace std;

template <typename T>
class LoopQueue : public Queue<T>
{
private:
    T* m_data;
    int m_capacity;
    int front, tail;
    int m_size;

    friend ostream& operator<<(ostream& os, const LoopQueue<T>& queue)
    {
        os << "Queue: size = " << queue.m_size << " , capacity = " << queue.getCapacity() << endl;
        os << "front [";
        for(int i = queue.front; i != queue.tail; i = (i + 1) % queue.m_capacity)
        {
            os << queue.m_data[i];
            if((i + 1) % queue.m_capacity != queue.tail)
            {
                os << ", ";
            }
        }
        os << "] tail";

        return os;
    }
public:
    LoopQueue(int capacity = 10)
    {
        m_data = new T[capacity + 1];
        m_capacity = capacity + 1;
        front = 0;
        tail = 0;
        m_size = 0;
    }

    int getCapacity() const
    {
        return m_capacity - 1;
    }

    bool isEmpty() override
    {
        return (front == tail);
    }

    int getSize() override
    {
        return m_size;
    }

    void enqueue(T e) override
    {
        if((tail + 1) % m_capacity == front)
        {
            resize(getCapacity() * 2);
        }

        m_data[tail] = e;
        tail = (tail + 1) % m_capacity;
        m_size++;
    }

    T dequeue() override
    {
        if(isEmpty())
        {
            throw std::invalid_argument("Cannot dequeue from an empty queue.");
        }

        T ret = m_data[front];
        front = (front + 1) % m_capacity;
        m_size--;

        if(m_size == getCapacity() / 4 && getCapacity() / 2 != 0)
        {
            resize(getCapacity() / 2);
        }

        return ret;
    }

    T getFront() override
    {
        if(isEmpty())
        {
            throw std::invalid_argument("Cannot dequeue from an empty queue.");
        }

        return m_data[front];
    }

    void resize(int newCapacity)
    {
        T* toDel = m_data;
        m_data = new T[newCapacity + 1];

        for(int i = 0; i < m_size; i++)
        {
            m_data[i] = toDel[(front + i) % m_capacity];
        }

        m_capacity = newCapacity + 1;
        front = 0;
        tail = m_size;

        delete[] toDel;
    }
};

#endif