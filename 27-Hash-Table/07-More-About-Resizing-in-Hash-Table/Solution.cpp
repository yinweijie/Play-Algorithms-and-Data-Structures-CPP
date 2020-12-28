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
    static constexpr std::array capacity = 
            {53, 97, 193, 389, 769, 1543, 3079, 6151, 12289, 24593,
            49157, 98317, 196613, 393241, 786433, 1572869, 3145739, 6291469,
            12582917, 25165843, 50331653, 100663319, 201326611, 402653189, 805306457, 1610612741};

    static constexpr int upperTol = 10;
    static constexpr int lowerTol = 2;
    int capacityIndex = 0;

    int size;
    int M;
    vector<map<K, V>> hashtable;

    void resize(int newM)
    {
        vector<map<K, V>> newHashtable(newM);

        int oldM = M;
        M = newM;
        for(int i = 0; i < oldM; i++)
        {
            map<K, V>& mymap = hashtable[i];
            for(const auto&[key, value] : mymap)
            {
                newHashtable[hashFunc(key)][key] = value;
            }
        }

        hashtable = std::move(newHashtable);
    }

public:
    HashTable() : size(0)
    {
        M = capacity[capacityIndex];
        hashtable.resize(M);
    }

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

            if(size >= M * upperTol && capacityIndex + 1 < capacity.size())
            {
                capacityIndex++;
                resize(capacity[capacityIndex]);
            }
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

        if(size < M * lowerTol && capacityIndex - 1 >= 0)
        {
            capacityIndex--;
            resize(capacity[capacityIndex]);
        }

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
        HashTable<int, int> map;
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