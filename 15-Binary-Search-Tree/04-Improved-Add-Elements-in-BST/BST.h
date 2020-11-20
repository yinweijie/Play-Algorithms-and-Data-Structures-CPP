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

        ~Node()
        {
            if(left != nullptr) delete left;
            if(right != nullptr) delete right;
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

    ~BST()
    {
        delete root;
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

    // 向以node为根的二分搜索树中插入元素e，递归算法
    // 返回插入新节点后二分搜索树的根
    void add(T e)
    {
        root = add(root, e);
    }

private:
    Node* add(Node* node, T e)
    {
        if(node == nullptr)
        {
            m_size++;
            return new Node(e);
        }

        if(e > node->e)
        {
            node->right = add(node->right, e);
        }
        else if(e < node->e)
        {
            node->left = add(node->left, e);
        }

        return node;
    }
};

#endif