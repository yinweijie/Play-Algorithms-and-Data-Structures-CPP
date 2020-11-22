#ifndef __BST_H__
#define __BST_H__

#include <iostream>
#include <string>
#include <stack>

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
    void preOrderNR()
    {
        if(root == nullptr)
        {
            return;
        }

        stack<Node*> stk;
        stk.push(root);

        while(!stk.empty())
        {
            Node* node = stk.top();
            stk.pop();

            cout << node->e << endl;

            if(node->right != nullptr)
            {
                stk.push(node->right);
            }
            if(node->left != nullptr)
            {
                stk.push(node->left);
            }
        }
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
    // 参考：https://class.imooc.com/course/qadetail/255505
    void inOrderNR()
    {
        if(root == nullptr)
        {
            return;
        }

        stack<Node*> stk;
        Node* cur = root;
        stk.push(cur);
        while(cur->left != nullptr)
        {
            stk.push(cur->left);
            cur = cur->left;
        }

        while(!stk.empty())
        {
            Node* node = stk.top();
            stk.pop();
            cout << node->e << endl;

            if(node->right != nullptr)
            {
                Node* tmp = node->right->left;
                stk.push(node->right);
                while(tmp != nullptr)
                {
                    stk.push(tmp);
                    tmp = tmp->left;
                }
            }
        }
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
    // 参考：https://class.imooc.com/course/qadetail/255505
    void postOrderNR()
    {
        if(root == nullptr)
        {
            return;
        }

        stack<Node*> stk;
        Node* cur = root;
        stk.push(cur);
        while(cur->left != nullptr)
        {
            stk.push(cur->left);
            cur = cur->left;
        }

        stack<Node*> cpyStack;
        while(!stk.empty())
        {
            Node* node = stk.top();
            stk.pop();
            
            if(node->right != nullptr)
            {
                // 一定要在上面先pop，然后新定义一个Node，push进stack，这样保证该Node没有左右孩子，
                // 否则该节点为top的时候，又会回到该节点的right节点，出现死循环
                Node* cpyNode = new Node(node->e);
                stk.push(cpyNode);
                cpyStack.push(cpyNode);

                Node* tmp = node->right->left;
                stk.push(node->right);
                while(tmp != nullptr)
                {
                    stk.push(tmp);
                    tmp = tmp->left;
                }
            }
            else
            {
                cout << node->e << endl;
                if(!cpyStack.empty() && node == cpyStack.top()) // 保证不出现内存泄漏
                {
                    delete node;
                    cpyStack.pop();
                }
            }
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