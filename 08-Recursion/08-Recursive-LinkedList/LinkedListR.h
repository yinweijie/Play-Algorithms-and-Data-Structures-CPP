#ifndef __LINKEDLISTR_H__
#define __LINKEDLISTR_H__

#include <iostream>

using namespace std;

/// 递归实现的LinkedList
/// 类名称中LinkedListR里的R，是Recursion的意思，表示递归实现:)
template <typename T>
class LinkedListR
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

    // 在链表的递归实现中，我们不使用虚拟头结点，也能无差异的处理位置0的问题:)
    Node* m_head;
    int m_size;

    friend ostream& operator<<(ostream& os, const LinkedListR<T>& list)
    {
        for(Node* cur = list.m_head; cur != nullptr; cur = cur->next)
        {
            os << (*cur) << "->";
        }
        os << "NULL";
    }
public:
    LinkedListR()
    {
        m_head = nullptr;
        m_size = 0;
    }

    ~LinkedListR()
    {
        Node* cur = m_head;

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
    void add(int index, T e)
    {
        if(index < 0 || index > m_size)
        {
            throw std::invalid_argument("Add failed. Illegal index.");
        }

        m_head = add(m_head, index, e);
        m_size++;
    }

    // 在以node为头结点的链表的index位置插入元素e，递归算法
    Node* add(Node* node, int index, T e)
    {
        if(index == 0)
        {
            return new Node(e, node);
        }

        node->next = add(node->next, index - 1, e);

        return node;
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
    T get(int index)
    {
        if(index < 0 || index >= m_size)
        {
            throw std::invalid_argument("Get failed. Illegal index.");
        }

        return get(m_head, index);
    }

    // 在以node为头结点的链表中，找到第index个元素，递归算法
    T get(Node* node, int index)
    {
        if(index == 0)
        {
            return node->e;
        }

        return get(node->next, index - 1);
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
    void set(int index, T e)
    {
        if(index < 0 || index >= m_size)
        {
            throw std::invalid_argument("Set failed. Illegal index.");
        }

        set(m_head, index, e);
    }

    void set(Node* node, int index, T e)
    {
        if(index == 0)
        {
            node->e = e;
            return;
        }

        set(node->next, index - 1, e);
    }

    // 查找链表中是否有元素e
    bool contains(T e)
    {
        return contains(m_head, e);
    }

    // 在以node为头结点的链表中，查找是否存在元素e，递归算法
    bool contains(Node* node, T e)
    {
        if(node == nullptr)
        {
            return false;
        }

        if(node->e == e)
        {
            return true;
        }

        return contains(node->next, e);
    }

    // 从链表中删除index(0-based)位置的元素, 返回删除的元素
    T remove(int index)
    {
        if(index < 0 || index >= m_size)
        {
            throw std::invalid_argument("Remove failed. Illegal index.");
        }

        pair<Node*, T> ret = remove(m_head, index);
        
        return ret.second;
    }

    // 从以node为头结点的链表中，删除第index位置的元素，递归算法
    // 返回值包含两个元素，删除后的链表头结点和删除的值:)
    pair<Node*, T> remove(Node* node, int index)
    {
        if(index == 0)
        {
            Node* ret = node->next;
            T retE = node->e;
            delete node;
            return pair<Node*, T>(ret, retE);
        }

        pair<Node*, T> ret = remove(node->next, index - 1);
        node->next = ret.first;
        ret.first = node;

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
        removeElement(m_head, e);
    }

    Node* removeElement(Node* node, T e)
    {
        if(node->e == e)
        {
            Node* ret = node->next;
            delete node;
            return ret;
        }

        node->next = removeElement(node->next, e);
        
        return node;
    }
};

#endif