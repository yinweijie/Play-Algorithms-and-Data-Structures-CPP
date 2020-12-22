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

    // 在链表的index(0-based)位置添加新的元素e
    // 在链表中不是一个常用的操作，练习用: )
    void add(int index, T e)
    {
        if(index < 0 || index > m_size)
        {
            throw std::invalid_argument("Add failed. Illegal index.");
        }

        Node* pre = m_dummyHead;
        for(int i = 0; i < index; i++)
        {
            pre = pre->next;
        }
        pre->next = new Node(e, pre->next);
        m_size++;
    }

    // 在链表头添加新的元素e
    void addFirst(T e)
    {
        add(0, e);
    }

    // 在链表末尾添加新的元素e
    void addLast(T e)
    {
        add(m_size, e);
    }

    // 获得链表的第index(0-based)个位置的元素
    // 在链表中不是一个常用的操作，练习用: )
    T get(int index)
    {
        if(index < 0 || index >= m_size)
        {
            throw std::invalid_argument("Get failed. Illegal index.");
        }

        Node* cur = m_dummyHead->next;
        for(int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        return cur->e;
    }

    // 获得链表的第一个元素
    T getFirst()
    {
        return get(0);
    }

    // 获得链表的最后一个元素
    T getLast()
    {
        return get(m_size - 1);
    }

    // 修改链表的第index(0-based)个位置的元素为e
    // 在链表中不是一个常用的操作，练习用: )
    void set(int index, T e)
    {
        if(index < 0 || index >= m_size)
        {
            throw std::invalid_argument("Set failed. Illegal index.");
        }

        Node* cur = m_dummyHead->next;
        for(int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        cur->e = e;
    }

    // 查找链表中是否有元素e
    bool contains(T e)
    {
        Node* cur = m_dummyHead->next;
        while(cur)
        {
            if(cur->e == e)
            {
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    // 从链表中删除index(0-based)位置的元素, 返回删除的元素
    // 在链表中不是一个常用的操作，练习用: )
    T remove(int index)
    {
        if(index < 0 || index >= m_size)
        {
            throw std::invalid_argument("Remove failed. Illegal index.");
        }

        Node* pre = m_dummyHead;
        for(int i = 0; i < index; i++)
        {
            pre = pre->next;
        }

        Node* toDel = pre->next;
        T ret = toDel->e;
        pre->next = toDel->next;
        delete toDel;
        m_size--;

        return ret;
    }

    // 从链表中删除第一个元素, 返回删除的元素
    T removeFirst()
    {
        return remove(0);
    }

    // 从链表中删除最后一个元素, 返回删除的元素
    T removeLast()
    {
        return remove(m_size - 1);
    }

    // 从链表中删除元素e
    void removeElement(T e)
    {
        Node* pre = m_dummyHead;
        while(pre->next)
        {
            if(pre->next->e == e)
            {
                break;
            }
            pre = pre->next;
        }

        if(pre->next)
        {
            Node* toDel = pre->next;
            pre->next = toDel->next;
            delete toDel;
            m_size--;
        }
    }
};

#endif