#ifndef __MAP_H__
#define __MAP_H__

template <typename K, typename V>
class Map
{
public:
    virtual add(K key, V value) = 0;
    virtual V remove(K key) = 0;
    bool contains(K key) = 0;
    V get(K key) = 0;
    void set(K key, V newValue) = 0;
    int getSize() = 0;
    bool isEmpty() = 0;
};

#endif