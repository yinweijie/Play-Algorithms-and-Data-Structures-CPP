#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include <map>
#include <vector>
#include <functional>
#include <stdexcept>
#include <sstream>
#include <utility>
#include <array>

using namespace std;

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

#endif