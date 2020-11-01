#ifndef __ARRAYSTACK_H__
#define __ARRAYSTACK_H__

#include "Stack.h"
#include "Array.h"

template <typename T>
class ArrayStack : public Stack<T>
{
private:
    Array<T> array;

    friend ostream& operator<<(ostream& os, const ArrayStack<T>& stack)
    {
        os << "Stack: [";

        for(int i = 0; i < stack.array.getSize(); i++)
        {
            os << stack.array.get(i);
            if(i != stack.array.getSize() - 1)
            {
                os << ", ";
            }
        }

        os << "] top";

        return os;
    }
public:
    ArrayStack(int capacity = 10) : array(capacity) { }

    int getSize() override
    {
        return array.getSize();
    }

    bool isEmpty() override
    {
        return array.isEmpty();
    }

    void push(T e) override
    {
        array.addLast(e);
    }

    T pop() override
    {
        return array.removeLast();
    }

    T peek() override
    {
        return array.getLast();
    }
};

#endif