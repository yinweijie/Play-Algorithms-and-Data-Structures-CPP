/// Leetcode 804. Unique Morse Code Words
/// https://leetcode.com/problems/unique-morse-code-words/description/
///
/// 课程中在这里暂时没有介绍这个问题
/// 该代码主要用于使用Leetcode上的问题测试我们的BST类

#include <vector>
#include <string>

using namespace std;

class Solution {
private:
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
        void add(T e)
        {
            if(root == nullptr)
            {
                root = new Node(e);
                m_size++;
            }
            else
            {
                add(root, e);
            }
        }

    private:
        void add(Node* node, T e)
        {
            if(node->e == e)
            {
                return;
            }

            if(e > node->e && node->right == nullptr)
            {
                node->right = new Node(e);
                m_size++;
                return;
            }
            else if(e < node->e && node->left == nullptr)
            {
                node->left = new Node(e);
                m_size++;
                return;
            }

            if(e > node->e)
            {
                add(node->right, e);
            }
            else
            {
                add(node->left, e);
            }
        }
    };

public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string codes[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        BST<string> bst;
        for(string word: words){
            string res;
            for(int i = 0 ; i < word.length() ; i ++)
                res.append(codes[word[i] - 'a']);
            bst.add(res);
        }

        return bst.size();
    }
};