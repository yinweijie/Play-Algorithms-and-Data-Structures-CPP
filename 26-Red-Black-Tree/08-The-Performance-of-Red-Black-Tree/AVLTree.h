#ifndef __AVLTree_H__
#define __AVLTree_H__

#include <string>
#include <algorithm>
#include <cstdlib>
#include <stdexcept>
#include <sstream>

using namespace std;

template <typename K, typename V>
class AVLTree
{
private:
    struct Node
    {
        K Key;
        V Value;
        Node* left;
        Node* right;
        int height;

        Node(K key, V value)
        {
            Key = key;
            Value = value;
            left = nullptr;
            right = nullptr;
            height = 1;
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
    AVLTree()
    {
        root = nullptr;
        m_size = 0;
    }

    ~AVLTree()
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

    // 判断该二叉树是否是一棵二分搜索树
    bool isBST()
    {
        vector<K> keys;
        inOrder(root, keys);

        for(int i = 1; i < keys.size(); i++)
        {
            if(keys[i - 1] > keys[i])
            {
                return false;
            }
        }

        return true;
    }

private:
    void inOrder(Node* node, vector<K>& keys)
    {
        if(node == nullptr)
        {
            return;
        }

        inOrder(node->left, keys);
        keys.push_back(node->Key);
        inOrder(node->right, keys);
    }

public:
    // 判断该二叉树是否是一棵平衡二叉树
    bool isBalanced()
    {
        return isBalanced(root);
    }

private:
    // 判断以Node为根的二叉树是否是一棵平衡二叉树，递归算法
    bool isBalanced(Node* node)
    {
        if(node == nullptr)
        {
            return true;
        }

        int balanceFactor = getBalanceFactor(node);
        if(std::abs(balanceFactor) > 1)
        {
            return false;
        }

        return isBalanced(node->left) && isBalanced(node->right);
    }

public:
    // 获得节点node的高度
    int getHeight(Node* node)
    {
        if(node == nullptr)
        {
            return 0;
        }

        return node->height;
    }

    // 获得节点node的平衡因子
    int getBalanceFactor(Node* node)
    {
        return getHeight(node->left) - getHeight(node->right);
    }

    // 对节点y进行向右旋转操作，返回旋转后新的根节点x
    //        y                              x
    //       / \                           /   \
    //      x   T4     向右旋转 (y)        z     y
    //     / \       - - - - - - - ->    / \   / \
    //    z   T3                       T1  T2 T3 T4
    //   / \
    // T1   T2
private:
    Node* rightRotate(Node* y)
    {
        Node* x = y->left;
        Node* T3 = x->right;

        // 向右旋转过程
        x->right = y;
        y->left = T3;

        // 更新height
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    // 对节点y进行向左旋转操作，返回旋转后新的根节点x
    //    y                             x
    //  /  \                          /   \
    // T1   x      向左旋转 (y)       y     z
    //     / \   - - - - - - - ->   / \   / \
    //   T2  z                     T1 T2 T3 T4
    //      / \
    //     T3 T4
private:
    Node* leftRotate(Node* y)
    {
        Node* x = y->right;
        Node* T2 = x->left;

        // 向左旋转过程
        x->left = y;
        y->right = T2;

        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
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

        // 更新height
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

        // 计算平衡因子
        int balanceFactor = getBalanceFactor(node);
        // if(std::abs(balanceFactor) > 1)
        // {
        //     cout << "unbalanced : " << balanceFactor << endl;
        // }

        // 平衡维护
        if(balanceFactor > 1 && getBalanceFactor(node->left) >= 0)
        {
            return rightRotate(node);
        }

        if(balanceFactor < -1 && getBalanceFactor(node->right) <= 0)
        {
            return leftRotate(node);
        }

        if(balanceFactor > 1 && getBalanceFactor(node->left) < 0)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if(balanceFactor < -1 && getBalanceFactor(node->right) > 0)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
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

        Node* retNode = nullptr;
        if(key > node->Key)
        {
            node->right = remove(node->right, key);
            // return node;
            retNode = node;
        }
        else if(key < node->Key)
        {
            node->left = remove(node->left, key);
            // return node;
            retNode = node;
        }
        else
        {
            // 待删除节点左子树为空的情况
            if(node->left == nullptr)
            {
                Node* rightNode = node->right;
                node->right = nullptr;
                delete node;
                m_size--;
                // return rightNode;
                retNode = rightNode;
            }
            // 待删除节点右子树为空的情况
            else if(node->right == nullptr)
            {
                Node* leftNode = node->left;
                node->left = nullptr;
                delete node;
                m_size--;
                // return leftNode;
                retNode = leftNode;
            }
            // 待删除节点左右子树均不为空的情况
            else
            {
                // 找到比待删除节点大的最小节点, 即待删除节点右子树的最小节点
                // 用这个节点顶替待删除节点的位置
                Node* succNode = minimum(node->right);
                Node* successor = new Node(succNode->Key, succNode->Value);
                // successor->right = removeMin(node->right);
                successor->right = remove(node->right, succNode->Key);
                successor->left = node->left;

                node->left = nullptr;
                node->right = nullptr;
                delete node;

                // return successor;
                retNode = successor;
            }
        }

        if(retNode == nullptr)
        {
            return nullptr;
        }

        // 更新height
        retNode->height = 1 + std::max(getHeight(retNode->left), getHeight(retNode->right));

        // 计算平衡因子
        int balanceFactor = getBalanceFactor(retNode);

        // 平衡维护
        // LL
        if(balanceFactor > 1 && getBalanceFactor(retNode->left) >= 0)
        {
            return rightRotate(retNode);
        }

        // RR
        if(balanceFactor < -1 && getBalanceFactor(retNode->right) <= 0)
        {
            return leftRotate(retNode);
        }

        // LR
        if(balanceFactor > 1 && getBalanceFactor(retNode->left) < 0)
        {
            retNode->left = leftRotate(retNode->left);
            return rightRotate(retNode);
        }

        // RL
        if(balanceFactor < -1 && getBalanceFactor(retNode->right) > 0)
        {
            retNode->right = rightRotate(retNode->right);
            return leftRotate(retNode);
        }

        return retNode;
    }
};

#endif