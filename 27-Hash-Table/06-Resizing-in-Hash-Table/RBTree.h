#ifndef __RBTREE_H__
#define __RBTREE_H__

#include <string>
#include <stdexcept>
#include <sstream>

using namespace std;

template <typename K, typename V>
class RBTree
{
private:
    static constexpr bool RED = true;
    static constexpr bool BLACK = false;

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

private:
    // 判断节点node的颜色
    bool isRed(Node* node)
    {
        if(node == nullptr)
        {
            return BLACK;
        }

        return node->color;
    }

    //   node                     x
    //  /   \     左旋转         /  \
    // T1   x   --------->   node   T3
    //     / \              /   \
    //    T2 T3            T1   T2
    Node* leftRotate(Node* node)
    {
        Node* x = node->right;

        // 左旋转
        node->right = x->left;
        x->left = node;

        x->color = node->color;
        node->color = RED;

        return x;
    }

    //     node                   x
    //    /   \     右旋转       /  \
    //   x    T2   ------->   y   node
    //  / \                       /  \
    // y  T1                     T1  T2
    Node* rightRotate(Node* node)
    {
        Node* x = node->left;

        // 右旋转
        node->left = x->right;
        x->right = node;

        x->color = node->color;
        node->color = RED;

        return x;
    }

    // 颜色翻转
    void flipColors(Node* node)
    {
        node->color = RED;
        node->left->color = BLACK;
        node->right->color = BLACK;
    }

public:
    // 向红黑树中添加新的元素(key, value)
    void add(K key, V value) 
    {
        root = add(root, key, value);
        root->color = BLACK; // 最终根节点为黑色节点
    }

private:
    // 向以node为根的红黑树中插入元素(key, value)，递归算法
    // 返回插入新节点后红黑树的根
    Node* add(Node* node, K key, V value)
    {
        if(node == nullptr)
        {
            m_size++;
            return new Node(key, value); // 默认插入红色节点
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

        if(isRed(node->right) && !isRed(node->left))
        {
            node = leftRotate(node);
        }

        if(isRed(node->left) && isRed(node->left->left))
        {
            node = rightRotate(node);
        }

        if(isRed(node->left) && isRed(node->right))
        {
            flipColors(node);
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
            ostringstream os;
            os << "Key: " << key << " does not exist.";
            throw std::invalid_argument(os.str());
        }
        return node->Value;
    }
    
    void set(K key, V newValue) 
    {
        Node* node = getNode(root, key);
        if(node == nullptr)
        {
            ostringstream os;
            os << "Key: " << key << " does not exist.";
            throw std::invalid_argument(os.str());
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
            ostringstream os;
            os << "Key: " << key << " does not exist.";
            throw std::invalid_argument(os.str());
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