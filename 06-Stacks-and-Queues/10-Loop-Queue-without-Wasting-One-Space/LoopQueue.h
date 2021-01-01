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

        // for loop revised
        for(int i = 0; i < queue.m_size; i++)
        {
            os << queue.m_data[(i + queue.front) % queue.m_capacity];
            if(i + 1 != queue.m_size)
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
        // change "capacity + 1" to "capacity"
        m_data = new T[capacity];
        m_capacity = capacity;
        front = 0;
        tail = 0;
        m_size = 0;
    }

    ~LoopQueue()
    {
        delete[] m_data;
    }

    int getCapacity() const
    {
        // change "m_capacity - 1" to "m_capacity"
        return m_capacity;
    }

    bool isEmpty() override
    {
        // change return statement
        return (m_size == 0);
    }

    int getSize() override
    {
        return m_size;
    }

    void enqueue(T e) override
    {
        // change if statement
        if(m_size == m_capacity)
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

        if(m_size == m_capacity / 4 && m_capacity / 2 != 0)
        {
            resize(m_capacity / 2);
        }

        return ret;
    }

    T getFront() override
    {
        if(isEmpty())
        {
            throw std::invalid_argument("Queue is empty.");
        }

        return m_data[front];
    }

    void resize(int newCapacity)
    {
        T* toDel = m_data;
        m_data = new T[newCapacity]; // change "newCapacity + 1" to "newCapacity"

        for(int i = 0; i < m_size; i++)
        {
            m_data[i] = toDel[(front + i) % m_capacity];
        }

        m_capacity = newCapacity;
        front = 0;
        tail = m_size;

        delete[] toDel;
    }
};

#endif