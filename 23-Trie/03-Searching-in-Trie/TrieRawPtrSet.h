#ifndef __TRIERAWPTRSET_H__
#define __TRIERAWPTRSET_H__

#include "TrieRawPtr.h"
#include "Set.h"

class TrieRawPtrSet : public Set<string>
{
private:
    TrieRawPtr trie;

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