#ifndef __BSTSET_H__
#define __BSTSET_H__

#include "BST.h"
#include "Set.h"

template <typename T>
class BSTSet : public Set<T>
{
private:
    BST<T> bst;

public:
    BSTSet() = default;

    void add(T e) override
    {
        bst.add(e);
    }

    bool contains(T e) override
    {
        return bst.contains(e);
    }

    void remove(T e) override
    {
        bst.remove(e);
    }

    int getSize() override
    {
        return bst.size();
    }

    bool isEmpty() override
    {
        return bst.isEmpty();
    }
};

#endif