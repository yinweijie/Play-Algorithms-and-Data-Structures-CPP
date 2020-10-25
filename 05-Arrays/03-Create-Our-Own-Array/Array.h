#ifndef __ARRAY_H__
#define __ARRAY_H__

class Array
{
private:
    int* m_data;
    int m_size;
    int m_capacity;
public:
    Array(int capacity = 10) : m_capacity(capacity)
    {
        m_data = new int[capacity];
        m_size = 0;
    }

    int getCapacity() const
    {
        return m_capacity;
    }

    int getSize() const
    {
        return m_size;
    }

    int isEmpty() const
    {
        return m_size == 0;
    }
};

#endif