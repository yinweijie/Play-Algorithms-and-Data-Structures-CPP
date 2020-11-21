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
    int m_size;

public:
    BST()
    {
        root = nullptr;
        m_size = 0;
    }

    ~BST()
    {
        delete root;
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

public:
    void add2(T e)
    {
        if(root == nullptr)
        {
            root = new Node(e);
            m_size++;
            return;
        }

        Node* p = root;
        while(p != nullptr)
        {
            if(e < p->e)
            {
                if(p->left == nullptr)
                {
                    p->left = new Node(e);
                    m_size++;
                    return;
                }

                p = p->left;
            }
            else if(e > p->e)
            {
                if(p->right == nullptr)
                {
                    p->right = new Node(e);
                    m_size++;
                    return;
                }

                p = p->right;
            }
            else
            {
                return;
            }
        }
    }
};

#endif