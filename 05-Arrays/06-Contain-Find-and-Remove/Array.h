#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <iostream>

using namespace std;

class Array
{
private:
    int* m_data;
    int m_size;
    int m_capacity;

    friend ostream& operator<<(ostream& os, const Array& array);
public:
    Array(int capacity = 10) : m_capacity(capacity)
    {
        m_data = new int[capacity];
        m_size = 0;
    }

    ~Array()
    {
        delete[] m_data;
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

    int get(int index) const
    {
        if(index < 0 || index >= m_size)
        {
            throw std::invalid_argument("Get failed. Index is illegal.");
        }

        return m_data[index];
    }

    void set(int index, int e)
    {
        if(index < 0 || index >= m_size)
        {
            throw std::invalid_argument("Get failed. Index is illegal.");
        }

        m_data[index] = e;
    }

    // 查找数组中是否有元素e
    bool contains(int e)
    {
        for(int i = 0; i < m_size; i++)
        {
            if(m_data[i] == e)
            {
                return true;
            }
        }

        return false;
    }

    // 查找数组中元素e所在的索引，如果不存在元素e，则返回-1
    int find(int e)
    {
        for(int i = 0; i < m_size; i++)
        {
            if(m_data[i] == e)
            {
                return i;
            }
        }

        return -1;
    }

    // 从数组中删除index位置的元素, 返回删除的元素
    int remove(int index)
    {
        if(index < 0 || index >= m_size)
        {
            throw std::invalid_argument("Remove failed. Index is illegal.");
        }

        int ret = m_data[index];

        for(int i = index + 1; i < m_size; i++)
        {
            m_data[i - 1] = m_data[i];
        }

        m_size--;

        return ret;
    }

    // 从数组中删除第一个元素, 返回删除的元素
    int removeFirst()
    {
        return remove(0);
    }

    // 从数组中删除最后一个元素, 返回删除的元素
    int removeLast()
    {
        return remove(m_size - 1);
    }

    // 从数组中删除元素e
    void removeElement(int e)
    {
        int index = find(e);

        if(index != -1)
        {
            remove(index);
        }
    }
};

ostream& operator<<(ostream& os, const Array& array)
{
    os << "Array: size = " << array.m_size << " , capacity = " << array.m_capacity << endl;
    os << "[";
    for(int i = 0; i < array.m_size; i++)
    {
        os << array.m_data[i];
        if(i != array.m_size - 1)
        {
            os << ", ";
        }
    }
    os << "]";

    return os;
}

#endif