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

    // 获取链表中的元素个数
    int getSize()
    {
        return m_size;
    }

    // 返回链表是否为空
    bool isEmpty()
    {
        return (m_size == 0);
    }

    // 在链表头添加新的元素e
    void addFirst(T e)
    {
        // Node* node = new Node(e);
        // node->next = m_head;
        // m_head = node;

        m_head = new Node(e, m_head);
        m_size++;
    }

    // 在链表的index(0-based)位置添加新的元素e
    // 在链表中不是一个常用的操作，练习用: )
    void add(int index, T e)
    {
        if(index < 0 || index > m_size)
        {
            throw std::invalid_argument("Add failed. Illegal index.");
        }

        if(index == 0)
        {
            addFirst(e);
        }
        else
        {
            Node* pre = m_head;
            for(int i = 0; i < index - 1; i++)
            {
                pre = pre->next;
            }
            // Node* node = new Node(e);
            // node->next = pre->next;
            // pre->next = node;
            pre->next = new Node(e, pre->next);
            m_size++;
        }
    }

    // 在链表末尾添加新的元素e
    void addLast(T e)
    {
        add(m_size, e);
    }
};

#endif