#ifndef __SEGMENTTREE_H__
#define __SEGMENTTREE_H__

#include <vector>

using namespace std;

template <typename T>
class SegmentTree
{
private:
    vector<T> data;
    vector<T> tree;

public:
    SegmentTree(vector<T>& arr) : data(arr)
    {
        tree.resize(arr.size());
    }

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