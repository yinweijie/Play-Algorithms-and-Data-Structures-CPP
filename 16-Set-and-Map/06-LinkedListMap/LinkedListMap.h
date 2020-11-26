#ifndef __LINKEDLISTMAP_H__
#define __LINKEDLISTMAP_H__

#include "Map.h"

template <typename K, typename V>
class LinkedListMap : public Map<K, V>
{
private:
    struct Node
    {
        K Key;
        V Value;
        Node* next;

        friend ostream& operator<<(ostream& os, const Node& node)
        {
            os << node.Key << " : " << node.Value;

            return os;
        }

        Node(K key, V value) : Key(key), Value(value), next(nullptr) { }

        Node()
        {
            next = nullptr;
        }
    };

    Node* m_dummyHead;
    int m_size;

    friend ostream& operator<<(ostream& os, const LinkedList<T>& list)
    {
        for(Node* cur = list.m_dummyHead->next; cur != nullptr; cur = cur->next)
        {
            os << (*cur) << "->";
        }
        os << "NULL";
    }
public:
    LinkedList()
    {
        m_dummyHead = new Node();
        m_size = 0;
    }

    ~LinkedList()
    {
        Node* cur = m_dummyHead;

        while(cur)
        {
            Node* toDel = cur;
            cur = cur->next;
            delete toDel;
        }
    }

};

#endif