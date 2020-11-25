#ifndef __MAP_H__
#define __MAP_H__

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

#endif