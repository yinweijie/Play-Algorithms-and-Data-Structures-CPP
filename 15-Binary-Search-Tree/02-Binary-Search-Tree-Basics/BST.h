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
    int size;

public:
    BST()
    {
        root = nullptr;
        size = 0;
    }

    int size()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }
};

#endif