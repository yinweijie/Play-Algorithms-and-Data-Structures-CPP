#ifndef __UNIONFIND1_H__
#define __UNIONFIND1_H__

#include <vector>
#include <stdexcept>
#include "UF.h"

using std::vector;

// 我们的第一版Union-Find
class UnionFind1 : public UF
{
private:
    vector<int> id; // 我们的第一版Union-Find本质就是一个数组

    // 查找元素p所对应的集合编号
    // O(1)复杂度
    int find(int p)
    {
        if(p < 0 || p >= id.size())
        {
            throw std::invalid_argument("p is out of bound");
        }

        return id[p];
    }
public:
    UnionFind1(int size)
    {
        id.reserve(size);

        // 初始化, 每一个id[i]指向自己, 没有合并的元素
        for(int i = 0; i < size; i++)
        {
            id.emplace_back(i);
        }
    }

    int getSize() override
    {
        return id.size();
    }

    bool isConnected(int p, int q) override
    {
        return find(p) == find(q);
    }

    void unionElement(int p, int q) override
    {
        int pId = find(p);
        int qId = find(q);

        if(pId == qId)
        {
            return;
        }

         // 合并过程需要遍历一遍所有元素, 将两个元素的所属集合编号合并
        for(int i = 0; i < id.size(); i++)
        {
            if(id[i] == pId)
            {
                id[i] = qId;
            }
        }
    }
};


#endif