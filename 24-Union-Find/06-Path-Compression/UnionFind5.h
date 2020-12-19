#ifndef __UNIONFIND5_H__
#define __UNIONFIND5_H__

#include <vector>
#include <stdexcept>
#include "UF.h"

using std::vector;

// 我们的第五版Union-Find
class UnionFind5 : public UF
{
private:
    // rank[i]表示以i为根的集合所表示的树的层数
    // 在后续的代码中, 我们并不会维护rank的语意, 也就是rank的值在路径压缩的过程中, 有可能不在是树的层数值
    // 这也是我们的rank不叫height或者depth的原因, 他只是作为比较的一个标准
    vector<int> rank;
    vector<int> parent;  // parent[i]表示第i个元素所指向的父节点

    // 查找过程, 查找元素p所对应的集合编号
    // O(h)复杂度, h为树的高度
    int find(int p)
    {
        if(p < 0 || p >= parent.size())
        {
            throw std::invalid_argument("p is out of bound");
        }

        while(p != parent[p])
        {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }

        return p;
    }
public:
    // 构造函数
    UnionFind5(int size)
    {
        parent.reserve(size);
        rank.reserve(size);

        // 初始化, 每一个parent[i]指向自己, 表示每一个元素自己自成一个集合
        for(int i = 0; i < size; i++)
        {
            parent.emplace_back(i);
            rank.emplace_back(1);
        }
    }

    int getSize() override
    {
        return parent.size();
    }

    // 查看元素p和元素q是否所属一个集合
    // O(h)复杂度, h为树的高度
    bool isConnected(int p, int q) override
    {
        return find(p) == find(q);
    }

    // 合并元素p和元素q所属的集合
    // O(h)复杂度, h为树的高度
    void unionElement(int p, int q) override
    {
        int pRoot = find(p);
        int qRoot = find(q);

        if(pRoot == qRoot)
        {
            return;
        }

        // 根据两个元素所在树的rank不同判断合并方向
        // 将rank低的集合合并到rank高的集合上
        if(rank[pRoot] < rank[qRoot])
        {
            parent[pRoot] = qRoot;
        }
        else if(rank[pRoot] > rank[qRoot])
        {
            parent[qRoot] = pRoot;
        }
        else
        {
            parent[pRoot] = qRoot;
            rank[qRoot] += 1; // 此时, 我维护rank的值
        }
    }
};

#endif