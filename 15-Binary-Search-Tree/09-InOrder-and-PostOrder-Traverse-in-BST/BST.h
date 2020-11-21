#ifndef __BST_H__
#define __BST_H__

#include <iostream>
#include <string>

using namespace std;

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
    bool contains(T e)
    {
        return contains(root, e);
    }

private:
    bool contains(Node* node, T e)
    {
        if(node == nullptr)
        {
            return false;
        }

        if(e == node->e)
        {
            return true;
        }
        else if(e < node->e)
        {
            return contains(node->left, e);
        }
        else
        {
            return contains(node->right, e);
        }
    }

public:
    void preOrder()
    {
        preOrder(root);
    }

private:
    void preOrder(Node* node)
    {
        if(node == nullptr)
        {
            return;
        }

        cout << (node->e) << endl;
        preOrder(node->left);
        preOrder(node->right);
    }

public:
    void inOrder()
    {
        inOrder(root);        
    }

private:
    void inOrder(Node* node)
    {
        if(node == nullptr)
        {
            return;
        }

        inOrder(node->left);
        cout << (node->e) << endl;
        inOrder(node->right);
    }

public:
    void postOrder()
    {
        postOrder(root);
    }

private:
    void postOrder(Node* node)
    {
        if(node == nullptr)
        {
            return;
        }

        postOrder(node->left);
        postOrder(node->right);
        cout << (node->e) << endl;
    }

private:
    friend ostream& operator<<(ostream& os, const BST<T>& bst)
    {
        string res;
        bst.generateBSTString(bst.root, 0, res);
        os << res;

        return os;
    }

    void generateBSTString(Node* node, int depth, string& res) const
    {
        if(node == nullptr)
        {
            res.append(generateDepthString(depth) + "null\n");
            return;
        }

        res.append(generateDepthString(depth) + to_string(node->e) + "\n");
        generateBSTString(node->left, depth + 1, res);
        generateBSTString(node->right, depth + 1, res);
    }

    string generateDepthString(int depth) const
    {
        string res;

        for(int i = 0; i < depth; i++)
        {
            res += "--";
        }

        return res;
    }
};

#endif