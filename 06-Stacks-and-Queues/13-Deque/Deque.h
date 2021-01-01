#ifndef __Deque_H__
#define __Deque_H__

#include <iostream>

using namespace std;

template <typename T>
class Deque
{
private:
    T* m_data;
    int m_capacity;
    int front, tail;
    int m_size;

    friend ostream& operator<<(ostream& os, const Deque<T>& queue)
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
    Deque(int capacity = 10)
    {
        // change "capacity + 1" to "capacity"
        m_data = new T[capacity];
        m_capacity = capacity;
        front = 0;
        tail = 0;
        m_size = 0;
    }

    ~Deque()
    {
        delete[] m_data;
    }

    int getCapacity() const
    {
        // change "m_capacity - 1" to "m_capacity"
        return m_capacity;
    }

    bool isEmpty()
    {
        // change return statement
        return (m_size == 0);
    }

    int getSize()
    {
        return m_size;
    }

    void addLast(T e)
    {
        if(m_size == m_capacity)
        {
            resize(getCapacity() * 2);
        }

        m_data[tail] = e;
        tail = (tail + 1) % m_capacity;
        m_size++;
    }

    void addFront(T e)
    {
        if(m_size == m_capacity)
        {
            resize(getCapacity() * 2);
        }

        front = (front - 1) < 0 ? (m_capacity - 1) : (front - 1);
        m_data[front] = e;
        m_size++;
    }

    T removeFront()
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

    T removeLast()
    {
        if(isEmpty())
        {
            throw std::invalid_argument("Cannot dequeue from an empty queue");
        }

        tail = (tail - 1 < 0) ? (m_capacity - 1) : tail - 1;
        T ret = m_data[tail];
        m_size--;

        if(m_size == m_capacity / 4 && m_capacity / 2 != 0)
        {
            resize(m_capacity / 2);
        }

        return ret;
    }

    T getFront()
    {
        if(isEmpty())
        {
            throw std::invalid_argument("Cannot dequeue from an empty queue.");
        }

        return m_data[front];
    }

    T getLast()
    {
        if(isEmpty())
        {
            throw std::invalid_argument("Cannot dequeue from an empty queue.");
        }

        int index = (tail - 1 < 0) ? (m_capacity - 1) : (tail - 1);

        return m_data[index];
    }

private:
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