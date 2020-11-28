/// Leetcode 350. Intersection of Two Arrays II
/// https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
///
/// 课程中在这里暂时没有介绍这个问题
/// 该代码主要用于使用Leetcode上的问题测试我们的LinkedListMap类

#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:

template <typename K, typename V>
class Map
{
public:
    virtual void add(K key, V value) = 0;
    virtual V remove(K key) = 0;
    virtual bool contains(K key) = 0;
    virtual V get(K key) = 0;
    virtual void set(K key, V newValue) = 0;
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
};

template <typename K, typename V>
class BSTMap : public Map<K, V>
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
            Key = key;
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
    BSTMap()
    {
        root = nullptr;
        m_size = 0;
    }

    ~BSTMap()
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
    bool contains(K key) override
    {
        return (getNode(root, key) != nullptr);
    }
    
    V get(K key) override
    {
        Node* node = getNode(root, key);
        return node->Value;
    }
    
    void set(K key, V newValue) override
    {
        Node* node = getNode(root, key);
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
    V remove(K key) override
    {
        Node* node = getNode(root, key);
        V res = node->Value;
        root = remove(root, key);

        return res;
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

public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        BSTMap<int, int> map;
        for(int num: nums1){
            if(!map.contains(num))
                map.add(num, 1);
            else
                map.set(num, map.get(num) + 1);
        }

        vector<int> res;
        for(int num: nums2){
            if(map.contains(num)){
                res.push_back(num);
                map.set(num, map.get(num) - 1);
                if(map.get(num) == 0)
                    map.remove(num);
            }
        }

        vector<int> ret;
        ret.resize(res.size());
        for(int i = 0 ; i < res.size() ; i ++)
            ret[i] = res[i];

        return ret;
    }
};

int main()
{
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    vector<int> res = Solution().intersect(nums1, nums2);
    return 0;
}