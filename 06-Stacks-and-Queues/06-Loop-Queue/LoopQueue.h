#ifndef __LOOPQUEUE_H__
#define __LOOPQUEUE_H__

template <typename T>
class LoopQueue : public Queue<T>
{
private:
    T* m_data;
    int m_capacity;
    int front, tail;
    int m_size;
public:
    LoopQueue(int capacity = 10)
    {
        m_data = new T[capacity + 1];
        m_capacity = capacity + 1;
        front = 0;
        tail = 0;
        m_size = 0;
    }

    int getCapacity() const override
    {
        return m_capacity - 1;
    }

    bool isEmpty() const override
    {
        return (front == tail);
    }

    int getSize() const override
    {
        return m_size;
    }

    void enqueue(T e) override
    {

    }

    T dequeue() override
    {
        return 0;
    }

    T getFront() override
    {
        return 0;
    }
};

#endif