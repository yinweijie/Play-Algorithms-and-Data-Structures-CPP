#ifndef __QUEUE_H__
#define __QUEUE_H__

template <typename T>
class Queue
{
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
    virtual void enqueue(T e) = 0;
    virtual T dequeue() = 0;
    virtual T getFront() = 0;
};

#endif