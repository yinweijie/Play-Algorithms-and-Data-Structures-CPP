/// 208. Implement Trie (Prefix Tree)
/// https://leetcode.com/problems/implement-trie-prefix-tree/description/

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

class Trie {
private:
    struct Node {
        bool isWord;
        map<char, shared_ptr<Node>> next;

        Node(bool isWord_) : isWord(isWord_) { }
        Node() : isWord(false) { }
    };

    shared_ptr<Node> root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = make_shared<Node>();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        shared_ptr<Node> cur = root;

        for(const char& c: word) {
            auto it = cur->next.find(c);

            if(it == cur->next.end()) {
                cur->next[c] = make_shared<Node>();
            }

            cur = cur->next.find(c)->second;
        }

        cur->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        shared_ptr<Node> cur = root;

        for(const char& c: word) {
            auto it = cur->next.find(c);

            if(it == cur->next.end()) {
                return false;
            }

            cur = it->second;
        }

        return cur->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        shared_ptr<Node> cur = root;

        for(const char& c: prefix) {
            auto it = cur->next.find(c);

            if(it == cur->next.end()) {
                return false;
            }

            cur = it->second;
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    Trie* trie = new Trie();

    trie->insert("apple");
    trie->search("apple");   // 返回 true
    trie->search("app");     // 返回 false
    trie->startsWith("app"); // 返回 true
    trie->insert("app");   
    trie->search("app");     // 返回 true

    delete trie;

    return 0;
}