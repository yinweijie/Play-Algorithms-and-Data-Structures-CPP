/// Leetcode 211. Add and Search Word - Data structure design
/// https://leetcode.com/problems/add-and-search-word-data-structure-design/description/

#include <map>
#include <string>
#include <memory>
#include <utility>
#include <iostream>

using std::map;
using std::string;
using std::shared_ptr;
using std::make_shared;
using std::pair;
using std::make_pair;

using std::cout;
using std::endl;

class WordDictionary {
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
    WordDictionary() {
        root = make_shared<Node>();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        shared_ptr<Node> cur = root;

        for(const char& c : word) {
            auto it = cur->next.find(c);

            if(it == cur->next.end()) {
                cur->next[c] = make_shared<Node>();
            }

            cur = cur->next.find(c)->second;
        }

        cur->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return match(root, word, 0);
    }

private:
    bool match(shared_ptr<Node> node, string word, int index) {
        if(word.size() == index) {
            return node->isWord;
        }

        const char& c = word[index];
        if(c != '.') {
            auto it = node->next.find(c);

            if(it == node->next.end()) {
                return false;
            }

            return match(it->second, word, index + 1);
        } else {
            for(const auto& [nextChar, nextElem] : node->next) {
                if(match(nextElem, word, index + 1)) {
                    return true;
                }
            }

            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main() {
    WordDictionary* wordDictionary = new WordDictionary();

    wordDictionary->addWord("bad");
    wordDictionary->addWord("dad");
    wordDictionary->addWord("mad");
    cout << wordDictionary->search("pad") << endl; // return False
    cout << wordDictionary->search("bad") << endl; // return True
    cout << wordDictionary->search(".ad") << endl; // return True
    cout << wordDictionary->search("b..") << endl; // return True

    return 0;
}