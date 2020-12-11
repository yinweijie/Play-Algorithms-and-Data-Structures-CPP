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
};

#endif