#ifndef __SET_H__
#define __SET_H__

template <typename T>
class Set
{
public:
    virtual void add(T e) = 0;
    virtual bool contains(T e) = 0;
    virtual void remove(T e) = 0;
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
};

#endif