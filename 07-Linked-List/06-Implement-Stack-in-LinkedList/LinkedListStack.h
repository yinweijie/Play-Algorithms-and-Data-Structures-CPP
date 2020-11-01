#ifndef __LINKEDLISTSTACK_H__
#define __LINKEDLISTSTACK_H__

#include "Stack.h"
#include "LinkedList.h"

template <typename T>
class LinkedListStack : public Stack<T>
{
private:
    LinkedList<T> list;

    friend ostream& operator<<(ostream& os, const LinkedListStack<T>& listStack)
    {
        os << listStack.list;

        return os;
    }
public:
    LinkedListStack() { }

    int getSize() override
    {
        return list.getSize();
    }

    bool isEmpty() override
    {
        return list.isEmpty();
    }

    void push(T e) override
    {
        list.addFirst(e);
    }

    T pop() override
    {
        return list.removeFirst();
    }

    T peek() override
    {
        return list.getFirst();
    }
};

#endif