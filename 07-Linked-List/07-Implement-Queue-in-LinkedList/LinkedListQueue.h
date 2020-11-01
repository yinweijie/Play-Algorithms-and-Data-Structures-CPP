#ifndef __LINKEDLISTQUEUE_H__
#define __LINKEDLISTQUEUE_H__

#include "Queue.h"

template <typename T>
class LinkedListQueue : public Queue<T>
{
private:
    struct Node
    {
        T e;
        Node* next;

        friend ostream& operator<<(ostream& os, const Node& node)
        {
            os << node.e;

            return os;
        }

        Node(T e, Node* next)
        {
            this->e = e;
            this->next = next;
        }

        Node(T e) : Node(e, nullptr) { }

        Node()
        {
            next = nullptr;
        }
    };

    Node* m_head;
    Node* m_tail;
    int m_size;

    friend ostream& operator<<(ostream& os, const LinkedListQueue<T>& list)
    {
        os << "Queue: front ";
        for(Node* cur = list.m_dummyHead->next; cur != nullptr; cur = cur->next)
        {
            os << (*cur) << "->";
        }
        os << "NULL tail";
    }
public:
    LinkedListQueue() : m_head(nullptr), m_tail(nullptr), m_size(0) { }

    ~LinkedListQueue()
    {
        if(m_head)
        {
            Node* toDel = m_head;
            m_head = m_head->next;
            delete toDel;
        }
    }

    int getSize() override
    {
        return m_size;
    }

    bool isEmpty() override
    {
        return (m_size == 0);
    }

    void enqueue(T e) override
    {
        if(m_tail == nullptr)
        {
            m_tail = new Node(e);
            m_head = m_tail;
        }
        else
        {
            m_tail->next = new Node(e);
            m_tail = m_tail->next;
        }
        m_size++;
    }

    T dequeue() override
    {
        if(isEmpty())
        {
            throw std::invalid_argument("Cannot dequeue from an empty queue.");
        }
        T ret = m_head->e;

        Node* toDel = m_head;
        m_head = m_head->next;
        delete toDel;

        if(m_head == nullptr)
        {
            m_tail == nullptr;
        }

        m_size--;

        return ret;
    }

    T getFront() override
    {
        if(isEmpty())
        {
            throw std::invalid_argument("Queue is empty.");
        }

        return m_head->e;
    }
};

#endif