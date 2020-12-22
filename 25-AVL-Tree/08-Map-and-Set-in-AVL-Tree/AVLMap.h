#ifndef __AVLMAP_H__
#define __AVLMAP_H__

#include "Map.h"
#include "AVLTree.h"

template <typename K, typename V>
class AVLMap : public Map<K, V>
{
private:
    AVLTree<K, V> avl;

public:
    AVLMap() = default;

    void add(K key, V value) override
    {
        avl.add(key, value);
    }
    
    V remove(K key) override
    {
        avl.remove(key);
    }
    
    bool contains(K key) override
    {
        return avl.contains(key);
    }
    
    V get(K key) override
    {
        return avl.get(key);
    }
    
    void set(K key, V newValue) override
    {
        avl.set(key, newValue);
    }
    
    int getSize() override
    {
        return avl.getSize();
    }

    bool isEmpty() override
    {
        return avl.isEmpty();
    }
};

#endif