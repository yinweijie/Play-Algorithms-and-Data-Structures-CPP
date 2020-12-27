#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include <map>
#include <vector>
#include <functional>
#include <stdexcept>

using namespace std;

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
            throw std::invalid_argument("key not found");
        }

        size--;
        return it->second;
    }

    void set(K key, V value)
    {
        map<K, V>& mymap = hashtable[hashFunc(key)];

        auto it = mymap.find(key);
        if(it == mymap.end())
        {
            throw std::invalid_argument("key not found");
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