/// Leetcode 350. Intersection of Two Arrays II
/// https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
///
/// 课程中在这里暂时没有介绍这个问题
/// 该代码主要用于使用Leetcode上的问题测试我们的HashTable类

#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
private:

template <typename K, typename V>
class HashTable
{
private:
    int size;
    int M;
    vector<map<K, V>> hashtable;

public:
    HashTable(int M_) : size(0), M(M_)
    {
        hashtable.resize(M);
    }

    HashTable() : HashTable(97) { }

    size_t hashFunc(K key)
    {
        return (hash<K>()(key)) % M;
    }

    int getSize()
    {
        return size;
    }

    void add(K key, V value)
    {
        map<K, V>& mymap = hashtable[hashFunc(key)];

        if(mymap.find(key) != mymap.end())
        {
            mymap[key] = value;
        }
        else
        {
            mymap[key] = value;
            size++;
        }
    }

    V remove(K key)
    {
        map<K, V>& mymap = hashtable[hashFunc(key)];

        auto it = mymap.find(key);
        if(it == mymap.end())
        {
            ostringstream os;
            os << key << " does not exist.";
            throw std::invalid_argument(os.str());
        }

        V ret = it->second;
        mymap.erase(key);
        size--;

        return ret;
    }

    void set(K key, V value)
    {
        map<K, V>& mymap = hashtable[hashFunc(key)];

        auto it = mymap.find(key);
        if(it == mymap.end())
        {
            ostringstream os;
            os << key << " does not exist.";
            throw std::invalid_argument(os.str());
        }

        it->second = value;
    }

    bool contains(K key)
    {
        map<K, V>& mymap = hashtable[hashFunc(key)];
        return mymap.find(key) != mymap.end();
    }

    V get(K key)
    {
        return hashtable[hashFunc(key)].find(key)->second;
    }
};
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        HashTable<int, int> m_map;
        for(auto num: nums1) {
            if(!m_map.contains(num)) {
                m_map.add(num, 1);
            } else {
                m_map.set(num, m_map.get(num) + 1);
            }
        }

        vector<int> res;
        for(auto num: nums2) {
            if(m_map.contains(num)) {
                m_map.set(num, m_map.get(num) - 1);
                res.push_back(num);
                if(m_map.get(num) == 0) {
                    m_map.remove(num);
                }
            }
        }

        return res;
    }
};

int main()
{
    vector<int> nums1 {4,9,5};
    vector<int> nums2 {9,4,9,8,4};

    vector<int> ret = Solution().intersect(nums1, nums2);

    for(auto e : ret)
    {
        cout << e << endl;
    }

    return 0;
}