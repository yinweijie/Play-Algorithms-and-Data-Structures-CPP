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

    // 向所有元素后添加一个新元素
    void addLast(int e)
    {
        add(m_size, e);
    }

    // 在所有元素前添加一个新元素
    void addFirst(int e)
    {
        add(0, e);
    }

    // 在index索引的位置插入一个新元素e
    void add(int index, int e)
    {
        if(m_size == m_capacity)
        {
            throw std::invalid_argument("Add failed. Array is full.");
        }

        if(index < 0 || index > m_size)
        {
            throw std::invalid_argument("Add failed. Require index >= 0 and index <= size.");
        }

        for(int i = m_size - 1; i >= index; i--)
        {
            m_data[i + 1] = m_data[i];
        }

        m_data[index] = e;

        m_size++;
    }
};

#endif