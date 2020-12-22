#ifndef __LINKEDLISTMAP_H__
#define __LINKEDLISTMAP_H__

#include <iostream>
#include "Map.h"

using namespace std;

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

        Node(K key, V value, Node* next)
        {
            this->Key = key;
            this->Value = value;
            this->next = next;
        }

        Node(K key, V value) : Key(key), Value(value), next(nullptr) { }

        Node()
        {
            next = nullptr;
        }
    };

    Node* m_dummyHead;
    int m_size;

public:
    LinkedListMap()
    {
        m_dummyHead = new Node();
        m_size = 0;
    }

    ~LinkedListMap()
    {
        Node* cur = m_dummyHead;

        while(cur)
        {
            Node* toDel = cur;
            cur = cur->next;
            delete toDel;
        }
    }

    void add(K key, V value) override
    {
        Node* node = getNode(key);
        if(node == nullptr)
        {
            m_dummyHead->next = new Node(key, value, m_dummyHead->next);
            m_size++;
        }
        else
        {
            node->Value = value;
        }
    }

    V remove(K key) override
    {
        Node* pre = m_dummyHead;
        while(pre->next != nullptr)
        {
            if(pre->next->Key == key)
            {
                break;
            }
            pre = pre->next;
        }

        if(pre->next != nullptr)
        {
            Node* toDel = pre->next;
            V res = toDel->Value;

            pre->next = toDel->next;
            toDel->next = nullptr;
            delete toDel;
            m_size--;

            return res;
        }
        else
        {
            throw std::invalid_argument("Key :" + string(key) + " does not exist.");
        }
    }

private:
    Node* getNode(K key)
    {
        Node* cur = m_dummyHead->next;
        while(cur != nullptr)
        {
            if(cur->Key == key)
            {
                return cur;
            }
            cur = cur->next;
        }
        return nullptr;
    }

public:
    bool contains(K key) override
    {
        return (getNode(key) != nullptr);
    }
    
    V get(K key) override
    {
        Node* node = getNode(key);
        if(node == nullptr)
        {
            throw std::invalid_argument("Key: " + string(key) + " does not exist.");
        }
        return node->Value;
    }

    void set(K key, V newValue) override
    {
        Node* node = getNode(key);
        if(node == nullptr)
        {
            throw std::invalid_argument("Key: " + string(key) + " does not exist.");
        }
        node->Value = newValue;
    }
    
    int getSize() override
    {
        return m_size;
    }
    
    bool isEmpty() override
    {
        return m_size == 0;
    }
    
};

#endif