#ifndef __LINKEDLISTSET_H__
#define __LINKEDLISTSET_H__

#include "BST.h"
#include "Set.h"
#include "LinkedList.h"

template <typename T>
class LinkedListSet : public Set<T>
{
private:
    LinkedList<T> list;

public:
    void add(T e) override
    {
        if(!list.contains(e))
        {
            list.addFirst(e);
        }
    }

    bool contains(T e) override
    {
        return list.contains(e);
    }

    void remove(T e) override
    {
        list.removeElement(e);
    }
    
    int getSize() override
    {
        return list.getSize();
    }

    bool isEmpty() override
    {
        return list.isEmpty();
    }
};

#endif