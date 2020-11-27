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
class LinkedListMap : public Map<K, V>
{
private:
    struct Node
    {
        K Key;
        V Value;
        Node* next;

        friend ostream& operator<<(ostream& os, const Node& node)
        {
            os << node.Key << " : " << node.Value;

            return os;
        }

        Node(K key, V value, Node* next)
        {
            this->Key = key;
            this->Value = value;
            this->next = next;
        }

        Node(K key, V value) : Key(key), Value(value), next(nullptr) { }

        Node()
        {
            next = nullptr;
        }
    };

    Node* m_dummyHead;
    int m_size;

public:
    LinkedListMap()
    {
        m_dummyHead = new Node();
        m_size = 0;
    }

    ~LinkedListMap()
    {
        Node* cur = m_dummyHead;

        while(cur)
        {
            Node* toDel = cur;
            cur = cur->next;
            delete toDel;
        }
    }

    void add(K key, V value) override
    {
        Node* node = getNode(key);
        if(node == nullptr)
        {
            m_dummyHead->next = new Node(key, value, m_dummyHead->next);
            m_size++;
        }
        else
        {
            node->Value = value;
        }
    }

    V remove(K key) override
    {
        Node* pre = m_dummyHead;
        while(pre->next != nullptr)
        {
            if(pre->next->Key == key)
            {
                break;
            }
            pre = pre->next;
        }

        if(pre->next != nullptr)
        {
            Node* toDel = pre->next;
            V res = toDel->Value;

            pre->next = toDel->next;
            toDel->next = nullptr;
            delete toDel;
            m_size--;

            return res;
        }
        else
        {
            // throw std::invalid_argument("Key :" + string(key) + " does not exist.");
            return 0;
        }
    }

private:
    Node* getNode(K key)
    {
        Node* cur = m_dummyHead->next;
        while(cur != nullptr)
        {
            if(cur->Key == key)
            {
                return cur;
            }
            cur = cur->next;
        }
        return nullptr;
    }

public:
    bool contains(K key) override
    {
        return (getNode(key) != nullptr);
    }
    
    V get(K key) override
    {
        Node* node = getNode(key);
        if(node == nullptr)
        {
            // throw std::invalid_argument("Key: " + string(key) + " does not exist.");
            return 0;
        }
        return node->Value;
    }

    void set(K key, V newValue) override
    {
        Node* node = getNode(key);
        if(node == nullptr)
        {
            // throw std::invalid_argument("Key: " + string(key) + " does not exist.");
            return;
        }
        node->Value = newValue;
    }
    
    int getSize() override
    {
        return m_size;
    }
    
    bool isEmpty() override
    {
        return m_size == 0;
    }
    
};

public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        LinkedListMap<int, int> map;
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