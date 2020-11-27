#ifndef __BSTMAP_H__
#define __BSTMAP_H__

#include "BST.h"

template <typename K, typename V>
class BSTMap : public BST<K, V>
{
private:
    struct Node
    {
        K Key;
        V Value;
        Node* left;
        Node* right;

        Node(K key, V value)
        {
            Key = key
            Value = value;
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

    int getSize() override
    {
        return m_size;
    }

    bool isEmpty() override
    {
        return m_size == 0;
    }

public:
    // 向二分搜索树中添加新的元素(key, value)
    void add(K key, V value) override
    {
        root = add(root, key, value);
    }
private:
    // 向以node为根的二分搜索树中插入元素(key, value)，递归算法
    // 返回插入新节点后二分搜索树的根
    Node* add(Node* node, K key, V value)
    {
        if(node == nullptr)
        {
            m_size++;
            return new Node(key, value);
        }

        if(key < node->Key)
        {
            node->left = add(node->left, key, value);
        }
        else if(key > node->Key)
        {
            node->right = add(node->right, key, value);
        }
        else
        {
            node->Value = value;
        }

        return node;
    }

    bool contains(K key) override
    {
        
    }
    
    V get(K key) override
    {
        
    }
    
    void set(K key, V newValue) override
    {
        
    }
    
    
    V remove(K key) override
    {
        
    }
};

#endif