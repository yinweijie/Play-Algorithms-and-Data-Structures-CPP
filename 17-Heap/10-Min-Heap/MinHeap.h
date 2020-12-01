#ifndef __MINHEAP_H__
#define __MINHEAP_H__

#include <vector>
#include "Array.h"

template <typename T>
class MinHeap
{
private:
    Array<T> m_data;

public:
    MinHeap(int capacity) : m_data(capacity) { }

    MinHeap() = default;

    MinHeap(vector<T>& arr) : m_data(arr)
    {
        for(int i = parent(arr.size() - 1); i >= 0; i--)
        {
            siftDown(i);
        }
    }

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
        while(k > 0 && m_data.get(k) < m_data.get(parent(k)))
        {
            m_data.swap(k, parent(k));
            k = parent(k);
        }
    }

public:
    // 看堆中的最小元素
    T findMin()
    {
        if(m_data.isEmpty())
        {
            throw std::invalid_argument("Can not findMin when heap is empty");
        }

        return m_data.get(0);
    }

    // 取出堆中最大元素
    T extractMin()
    {
        T res = findMin();

        m_data.swap(0, m_data.getSize() - 1);
        m_data.removeLast();
        siftDown(0);

        return res;
    }

private:
    void siftDown(int k)
    {
        while(leftChild(k) < m_data.getSize())
        {
            int j = leftChild(k);
            if(j + 1 < m_data.getSize() && m_data.get(j + 1) < m_data.get(j))
            {
                j++;
            }

            if(m_data.get(k) <= m_data.get(j))
            {
                break;
            }

            m_data.swap(k, j);
            k = j;
        }
    }

public:
    // 取出堆中的最小元素，并且替换成元素e
    T replace(T e)
    {
        T res = findMin();
        m_data.set(0, e);
        siftDown(0);

        return res;
    }
};

#endif