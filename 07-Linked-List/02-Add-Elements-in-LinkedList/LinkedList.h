#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <iostream>

using namespace std;

template <typename T>
class LinkedList
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
    int m_size;
public:
    LinkedList()
    {
        m_head = nullptr;
        m_size = 0;
    }
};

#endif