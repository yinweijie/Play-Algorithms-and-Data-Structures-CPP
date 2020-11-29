#ifndef __MAXHEAP_H__
#define __MAXHEAP_H__

#include "Array.h"

template <typename T>
class MaxHeap
{
private:
    Array<T> m_data;

public:
    MaxHeap(int capacity) : m_data(capacity) { }

    MaxHeap() = default;

    // 返回堆中的元素个数
    int size()
    {
        return m_data.getSize();
    }

    // 返回一个布尔值, 表示堆中是否为空
    bool isEmpty()
    {
        return m_data.isEmpty();
    }

private:
    // 返回完全二叉树的数组表示中，一个索引所表示的元素的父亲节点的索引
    int parent(int index)
    {
        if(index == 0)
        {
            throw std::invalid_argument("index-0 doesn't have parent.");
        }

        return (index - 1) / 2;
    }

    // 返回完全二叉树的数组表示中，一个索引所表示的元素的左孩子节点的索引
    int leftChild(int index)
    {
        return (index * 2) + 1;
    }

    // 返回完全二叉树的数组表示中，一个索引所表示的元素的右孩子节点的索引
    int rightChild(int index)
    {
        return (index * 2) + 2;
    }

public:
    // 向堆中添加元素
    void add(T e)
    {
        m_data.addLast(e);
        siftUp(m_data.getSize() - 1);
    }

private:
    void siftUp(int k)
    {
        while(k > 0 && m_data[k] > m_data[parent(k)])
        {
            m_data.swap(k, parent(k));
            k = parent(k);
        }
    }
};

#endif