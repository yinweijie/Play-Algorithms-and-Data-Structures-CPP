#ifndef __TRIESET_H__
#define __TRIESET_H__

#include "Trie.h"
#include "Set.h"

class TrieSet : public Set<string>
{
private:
    Trie trie;

public:
    void add(string e) override
    {
        trie.add(e);
    }
    
    bool contains(string e) override
    {
        return trie.contains(e);
    }
    
    int getSize() override
    {
        return trie.getSize();
    }

    bool isEmpty() override
    {
        return trie.getSize() == 0;
    }
};

#endif