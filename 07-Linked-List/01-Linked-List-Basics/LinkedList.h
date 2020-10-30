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
            // os << node.e;

            return os;
        }

        Node(T e, Node* next)
        {
            this->e = e;
            this->next = next;
        }

        Node(T e) : Node(e, nullptr) { }

        Node() : Node(0, nullptr) { }
    };
};

#endif