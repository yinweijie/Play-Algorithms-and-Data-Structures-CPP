#ifndef __BST_H__
#define __BST_H__

template <typename T>
class BST
{
private:
    struct Node
    {
        T e;
        Node* left;
        Node* right;

        Node(T e)
        {
            this->e = e;
            left = nullptr;
            right = nullptr;
        }
    };

    Node* root;
    int m_size;

public:
    BST()
    {
        root = nullptr;
        m_size = 0;
    }

    int size()
    {
        return m_size;
    }

    bool isEmpty()
    {
        return m_size == 0;
    }
};

#endif