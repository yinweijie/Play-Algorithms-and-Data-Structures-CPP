#ifndef __UNIONFIND3_H__
#define __UNIONFIND3_H__

#include <vector>
#include <stdexcept>
#include "UF.h"

using std::vector;

// 我们的第三版Union-Find
class UnionFind3 : public UF
{
private:
    vector<int> parent;  // parent[i]表示第一个元素所指向的父节点
    vector<int> sz;    // sz[i]表示以i为根的集合中元素个数

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
            p = parent[p];
        }

        return p;
    }
public:
    // 构造函数
    UnionFind3(int size)
    {
        parent.reserve(size);
        sz.reserve(size);

        // 初始化, 每一个parent[i]指向自己, 表示每一个元素自己自成一个集合
        for(int i = 0; i < size; i++)
        {
            parent.emplace_back(i);
            sz.emplace_back(1);
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

        // 根据两个元素所在树的元素个数不同判断合并方向
        // 将元素个数少的集合合并到元素个数多的集合上
        if(sz[pRoot] < sz[qRoot])
        {
            parent[pRoot] = qRoot;
            sz[qRoot] += sz[pRoot];
        }
        else
        {
            parent[qRoot] = pRoot;
            sz[pRoot] += sz[qRoot];
        }
    }
};

#endif