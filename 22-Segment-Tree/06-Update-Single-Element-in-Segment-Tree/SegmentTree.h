#ifndef __SEGMENTTREE_H__
#define __SEGMENTTREE_H__

#include <vector>
#include <functional>
#include <limits>
#include <iostream>

using namespace std;

template <typename T>
class SegmentTree
{
private:
    vector<T> data;
    vector<T> tree;
    function<T(T, T)> merge;

    friend ostream& operator<<(ostream& os, const SegmentTree<T>& segTree)
    {
        os << "[";
        for(int i = 0; i < segTree.tree.size(); i++)
        {
            if(segTree.tree[i] < numeric_limits<T>::max())
            {
                os << segTree.tree[i];
            }
            else
            {
                os << "null";
            }

            if(i != segTree.tree.size() - 1)
            {
                os << ", ";
            }
        }
        os << "]";
    }

public:
    SegmentTree(vector<T>& arr, function<T(T, T)> merge) : data(arr)
    {
        tree = vector<T>(4 * arr.size(), numeric_limits<T>::max());
        this->merge = merge;

        buildSegmentTree(0, 0, data.size() - 1);
    }

    // 在treeIndex的位置创建表示区间[l...r]的线段树
private:
    void buildSegmentTree(int treeIndex, int l, int r)
    {
        if(l == r)
        {
            tree[treeIndex] = data[l];
            return;
        }

        int leftTreeIndex = leftChild(treeIndex);
        int rightTreeIndex = rightChild(treeIndex);

        int mid = l + (r - l) / 2;
        buildSegmentTree(leftTreeIndex, l, mid);
        buildSegmentTree(rightTreeIndex, mid + 1, r);

        tree[treeIndex] = merge(tree[leftTreeIndex], tree[rightTreeIndex]);
    }

public:
    int getSize() const
    {
        return data.size();
    }

    T get(int index) const
    {
        if(index < 0 || index >= data.size())
        {
            throw std::invalid_argument("Index is illegal.");
        }

        return data[index];
    }

private:
    // 返回完全二叉树的数组表示中，一个索引所表示的元素的左孩子节点的索引
    int leftChild(int index)
    {
        return (index * 2 + 1);
    }

    int rightChild(int index)
    {
        return (index * 2 + 2);
    }

public:
    // 返回区间[queryL, queryR]的值
    T query(int queryL, int queryR)
    {
        if(queryL < 0 || queryR >= data.size() || queryL > queryR)
        {
            throw std::invalid_argument("Index is illegal.");
        }

        return query(0, 0, data.size() - 1, queryL, queryR);
    }

    // 在以treeIndex为根的线段树中[l...r]的范围里，搜索区间[queryL...queryR]的值
    T query(int treeIndex, int l, int r, int queryL, int queryR)
    {
        if(queryL == l && queryR == r)
        {
            return tree[treeIndex];
        }

        int mid = l + (r - l) / 2;
        // treeIndex的节点分为[l...mid]和[mid+1...r]两部分

        int leftTreeIndex = leftChild(treeIndex);
        int rightTreeIndex = rightChild(treeIndex);

        if(queryL >= mid + 1)
        {
            return query(rightTreeIndex, mid + 1, r, queryL, queryR);
        }
        else if(queryR <= mid)
        {
            return query(leftTreeIndex, l, mid, queryL, queryR);
        }

        T leftResult = query(leftTreeIndex, l, mid, queryL, mid);
        T rightResult = query(rightTreeIndex, mid + 1, r, mid + 1, queryR);

        return merge(leftResult, rightResult);
    }

    // 将index位置的值，更新为e
    void set(int index, T e)
    {
        if(index < 0 || index >= data.size())
        {
            throw std::invalid_argument("Index is illegal.");
        }

        data[index] = e;
        set(0, 0, data.size() - 1, index, e);
    }

    // 在以treeIndex为根的线段树中更新index的值为e
    void set(int treeIndex, int l, int r, int index, T e)
    {
        if(l == r)
        {
            tree[treeIndex] = e;
        }

        int mid = l + (r - l) / 2;
        // treeIndex的节点分为[l...mid]和[mid+1...r]两部分

        int leftTreeIndex = leftChild(treeIndex);
        int rightTreeIndex = rightChild(treeIndex);

        if(index <= mid)
        {
            set(leftTreeIndex, l, mid, index, e);
        }
        else if(index >= mid + 1)
        {
            set(rightTreeIndex, mid + 1, r, index, e);
        }

        tree[treeIndex] = merge(tree[leftTreeIndex], tree[rightTreeIndex]);
    }
};

#endif