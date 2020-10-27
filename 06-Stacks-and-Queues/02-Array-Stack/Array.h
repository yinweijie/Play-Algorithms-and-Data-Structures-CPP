#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <iostream>

using namespace std;

template<typename T>
class Array
{
private:
    T* m_data;
    int m_size;
    int m_capacity;

    friend ostream& operator<<(ostream& os, const Array<T>& array)
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

    void resize(int newCapacity)
    {
        T* toDel = m_data;
        m_data = new T[newCapacity];
        m_capacity = newCapacity;

        for(int i = 0; i < m_size; i++)
        {
            m_data[i] = toDel[i];
        }

        delete[] toDel;
    }
public:
    Array(int capacity = 10) : m_capacity(capacity)
    {
        m_data = new T[capacity];
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
    void addLast(T e)
    {
        add(m_size, e);
    }

    // 在所有元素前添加一个新元素
    void addFirst(T e)
    {
        add(0, e);
    }

    // 在index索引的位置插入一个新元素e
    void add(int index, T e)
    {
        if(index < 0 || index > m_size)
        {
            throw std::invalid_argument("Add failed. Require index >= 0 and index <= size.");
        }

        if(m_size == m_capacity)
        {
            resize(2 * m_capacity);
        }

        for(int i = m_size - 1; i >= index; i--)
        {
            m_data[i + 1] = m_data[i];
        }

        m_data[index] = e;

        m_size++;
    }

    T get(int index) const
    {
        if(index < 0 || index >= m_size)
        {
            throw std::invalid_argument("Get failed. Index is illegal.");
        }

        return m_data[index];
    }

    T getLast() const
    {
        return get(m_size - 1);
    }

    T getFirst() const
    {
        return get(0);
    }

    void set(int index, T e)
    {
        if(index < 0 || index >= m_size)
        {
            throw std::invalid_argument("Get failed. Index is illegal.");
        }

        m_data[index] = e;
    }

    // 查找数组中是否有元素e
    bool contains(T e)
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
    int find(T e)
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
    T remove(int index)
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

        if((m_size == m_capacity / 4) && (m_capacity / 2 != 0))
        {
            resize(m_capacity / 2);
        }

        return ret;
    }

    // 从数组中删除第一个元素, 返回删除的元素
    T removeFirst()
    {
        return remove(0);
    }

    // 从数组中删除最后一个元素, 返回删除的元素
    T removeLast()
    {
        return remove(m_size - 1);
    }

    // 从数组中删除元素e
    void removeElement(T e)
    {
        int index = find(e);

        if(index != -1)
        {
            remove(index);
        }
    }
};


#endif