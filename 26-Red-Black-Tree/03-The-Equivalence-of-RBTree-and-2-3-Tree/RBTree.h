#ifndef __RBTREE_H__
#define __RBTREE_H__

#include <string>

using namespace std;

template <typename K, typename V>
class RBTree
{
private:
    constexpr bool RED = true;
    constexpr bool BLACK = false;

    struct Node
    {
        K Key;
        V Value;
        Node* left;
        Node* right;
        bool color;

        Node(K key, V value)
        {
            Key = key;
            Value = value;
            left = nullptr;
            right = nullptr;
            color = RED;
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
    RBTree()
    {
        root = nullptr;
        m_size = 0;
    }

    ~RBTree()
    {
        delete root;
        m_size = 0;
    }

    int getSize()
    {
        return m_size;
    }

    bool isEmpty()
    {
        return m_size == 0;
    }

    // 判断节点node的颜色
    bool isRed(Node* node)
    {
        if(node == nullptr)
        {
            return BLACK;
        }

        return node->color;
    }

public:
    // 向二分搜索树中添加新的元素(key, value)
    void add(K key, V value) 
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

private:
    // 返回以node为根节点的二分搜索树中，key所在的节点
    Node* getNode(Node* node, K key)
    {
        if(node == nullptr)
        {
            return nullptr;
        }

        if(node->Key == key)
        {
            return node;
        }
        else if(key > node->Key)
        {
            return getNode(node->right, key);
        }
        else
        {
            return getNode(node->left, key);
        }
    }

public:
    bool contains(K key)
    {
        return (getNode(root, key) != nullptr);
    }
    
    V get(K key)
    {
        Node* node = getNode(root, key);
        if(node == nullptr)
        {
            throw std::invalid_argument("Key: " + key + " does not exist.");
        }
        return node->Value;
    }
    
    void set(K key, V newValue) 
    {
        Node* node = getNode(root, key);
        if(node == nullptr)
        {
            throw std::invalid_argument("Key: " + key + " does not exist.");
        }
        node->Value = newValue;
    }
    
private:
    Node* minimum(Node* node)
    {
        if(node->left == nullptr)
        {
            return node;
        }
        return minimum(node->left);
    }

    Node* removeMin(Node* node)
    {
        if(node->left == nullptr)
        {
            Node* rightNode = node->right;
            node->right = nullptr;
            delete node;
            m_size--;
            return rightNode;
        }
        node->left = removeMin(node->left);
        return node;
    }

public:
    // 从二分搜索树中删除键为key的节点
    V remove(K key) 
    {
        Node* node = getNode(root, key);
        if(node == nullptr)
        {
            throw std::invalid_argument("Key: " + key + " does not exist.");
        }
        root = remove(root, key);

        return node->Value;
    }

private:
    Node* remove(Node* node, K key)
    {
        if(node == nullptr)
        {
            return nullptr;
        }

        if(key > node->Key)
        {
            node->right = remove(node->right, key);
            return node;
        }
        else if(key < node->Key)
        {
            node->left = remove(node->left, key);
            return node;
        }
        else
        {
            if(node->left == nullptr)
            {
                Node* rightNode = node->right;
                node->right = nullptr;
                delete node;
                m_size--;
                return rightNode;
            }

            if(node->right == nullptr)
            {
                Node* leftNode = node->left;
                node->left = nullptr;
                delete node;
                m_size--;
                return leftNode;
            }

            Node* succNode = minimum(node->right);
            Node* successor = new Node(succNode->Key, succNode->Value);
            successor->right = removeMin(node->right);
            successor->left = node->left;

            node->left = nullptr;
            node->right = nullptr;
            delete node;

            return successor;
        }
    }
};

#endif