#ifndef __AVLSET_H__
#define __AVLSET_H__

#include "Set.h"
#include "AVLTree.h"

template <typename T>
class AVLSet : public Set<T>
{
private:
    AVLTree<T, int> avl;

public:
    AVLSet() = default;

    void add(T e) override
    {
        avl.add(e, 0);
    }
    
    bool contains(T e) override
    {
        return avl.contains(e);
    }
    
    void remove(T e) override
    {
        avl.remove(e);
    }

    int getSize() override
    {
        return avl.getSize();
    }

    bool isEmpty() override
    {
        return avl.isEmpty();
    }
};

#endif