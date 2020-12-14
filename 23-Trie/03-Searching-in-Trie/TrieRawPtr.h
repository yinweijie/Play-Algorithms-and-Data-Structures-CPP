/*
* 裸指针不利于内存管理，这里的实现没考虑最后的内存释放，只是为了对比shared_ptr的性能
*/

#ifndef __TRIERAWPTR_H__
#define __TRIERAWPTR_H__

#include <map>
#include <string>
#include <memory>
#include <utility>

using std::map;
using std::string;
using std::shared_ptr;
using std::make_shared;
using std::pair;

class TrieRawPtr
{
private:
    struct Node
    {
        bool isWord;
        map<char, Node*> next;

        Node(bool isWord_) : isWord(isWord_) { }
        Node() : isWord(false) { };
    };

    Node* root;
    int size;

public:
    TrieRawPtr()
    {
        root = new Node();
        size = 0;
    }

    // 获得Trie中存储的单词数量
    int getSize()
    {
        return size;
    }

    // 向Trie中添加一个新的单词word
    void add(const string& word)
    {
        Node* cur = root;
        for(const char& c: word)
        {
            if(cur->next.find(c) == cur->next.end())
            {   
                Node* node = new Node();
                cur->next.insert(std::make_pair(c, node));
            }

            cur = cur->next.find(c)->second;
        }

        if(!cur->isWord)
        {
            cur->isWord = true;
            size++;
        }
    }

    // 查询单词word是否在Trie中
    bool contains(string word)
    {
        Node* cur = root;
        for(const char& c: word)
        {
            if(cur->next.find(c) == cur->next.end())
            {
                return false;
            }

            cur = cur->next.find(c)->second;
        }

        return cur->isWord;
    }
};

#endif