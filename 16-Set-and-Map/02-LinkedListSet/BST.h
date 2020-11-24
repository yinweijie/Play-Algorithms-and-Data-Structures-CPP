#ifndef __BST_H__
#define __BST_H__

#include <iostream>
#include <string>
#include <queue>

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

public:
    // 二分搜索树的层序遍历
    void levelOrder()
    {
        if(root == nullptr)
        {
            return;
        }

        queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
            Node* node = q.front();
            q.pop();

            cout << (node->e) << endl;

            if(node->left != nullptr)
            {
                q.push(node->left);
            }
            if(node->right != nullptr)
            {
                q.push(node->right);
            }
        }
    }

public:
    // 寻找二分搜索树的最小元素
    T minimum()
    {
        if(m_size == 0)
        {
            throw std::invalid_argument("BST is empty");
        }

        return (minimum(root)->e);
    }

private:
    // 返回以node为根的二分搜索树的最小值所在的节点
    Node* minimum(Node* node)
    {
        if(node->left == nullptr)
        {
            return node;
        }

        return minimum(node->left);
    }

public:
    // 寻找二分搜索树的最大元素
    T maximum()
    {
        if(m_size == 0)
        {
            throw std::invalid_argument("BST is empty");
        }

        return (maximum(root)->e);
    }

private:
    // 返回以node为根的二分搜索树的最大值所在的节点
    Node* maximum(Node* node)
    {
        if(node->right == nullptr)
        {
            return node;
        }

        return maximum(node->right);
    }

public:
    // 从二分搜索树中删除最小值所在节点, 返回最小值
    T removeMin()
    {
        T ret = minimum();

        root = removeMin(root);

        return ret;
    }

private:
    // 删除掉以node为根的二分搜索树中的最小节点
    // 返回删除节点后新的二分搜索树的根
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
    // 从二分搜索树中删除最大值所在节点
    T removeMax()
    {
        T ret = maximum();

        root = removeMax(root);

        return ret;
    }

private:
    Node* removeMax(Node* node)
    {
        if(node->right == nullptr)
        {
            Node* leftNode = node->left;
            node->left = nullptr;
            delete node;
            m_size--;
            return leftNode;
        }

        node->right = removeMax(node->right);
        return node;
    }

public:
    // 从二分搜索树中删除元素为e的节点
    void remove(T e)
    {
        root = remove(root, e);
    }

private:
    // 删除掉以node为根的二分搜索树中值为e的节点, 递归算法
    // 返回删除节点后新的二分搜索树的根
    Node* remove(Node* node, T e)
    {
        if(node == nullptr)
        {
            return nullptr;
        }

        if(e < node->e)
        {
            node->left = remove(node->left, e);
            return node;
        }
        else if(e > node->e)
        {
            node->right = remove(node->right, e);
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

            Node* successor = new Node(minimum(node->right)->e);
            successor->right = removeMin(node->right);
            successor->left = node->left;

            node->left = nullptr;
            node->right = nullptr;
            delete node;

            return successor;
        }
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