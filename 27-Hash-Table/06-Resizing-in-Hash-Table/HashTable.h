#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include <map>
#include <vector>
#include <functional>
#include <stdexcept>
#include <sstream>
#include <utility>

using namespace std;

template <typename K, typename V>
class HashTable
{
private:
    static constexpr int upperTol = 10;
    static constexpr int lowerTol = 2;
    static constexpr int initCapacity = 7;

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
            for(const auto& [key, value] : mymap)
            {
                newHashtable[hashFunc(key)][key] = value;
            }
        }

        hashtable = std::move(newHashtable);
    }

public:
    HashTable(int M_) : size(0), M(M_)
    {
        hashtable.resize(M);
    }

    HashTable() : HashTable(initCapacity) { }

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

            if(size >= M * upperTol)
            {
                resize(2 * M);
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

        if(size < M * lowerTol && M / 2 >= initCapacity)
        {
            resize(M / 2);
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