#ifndef __TRIE_H__
#define __TRIE_H__

#include <map>
#include <string>
#include <memory>
#include <utility>

using std::map;
using std::string;
using std::shared_ptr;
using std::make_shared;
using std::pair;
using std::make_pair;

class Trie
{
private:
    struct Node
    {
        bool isWord;
        map<char, shared_ptr<Node>> next;

        Node(bool isWord_) : isWord(isWord_) { }
        Node() : isWord(false) { };
    };

    shared_ptr<Node> root;
    int size;

public:
    Trie()
    {
        root = make_shared<Node>();
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
        shared_ptr<Node> cur = root;
        for(const char& c: word)
        {
            if(cur->next.find(c) == cur->next.end())
            {
                cur->next.insert(make_pair(c, make_shared<Node>()));
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
        shared_ptr<Node> cur = root;
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

    // 查询是否在Trie中有单词以prefix为前缀
    bool isPrefix(string prefix)
    {
        shared_ptr<Node> cur = root;
        for(const char& c: prefix)
        {
            if(cur->next.find(c) == cur->next.end())
            {
                return false;
            }

            cur = cur->next.find(c)->second;
        }

        return true;
    }
};

#endif