/// Leetcode 677. 键值映射
/// https://leetcode-cn.com/problems/map-sum-pairs/

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

class MapSum {
private:
    struct Node {
        int value;
        map<char, shared_ptr<Node>> next;

        Node(int value_) : value(value_) { }
        Node() : value(0) { }
    };

    shared_ptr<Node> root;

public:
    /** Initialize your data structure here. */
    MapSum() {
        root = make_shared<Node>();
    }
    
    void insert(string key, int val) {
        shared_ptr<Node> cur = root;

        for(const char& c : key) {
            if(cur->next.find(c) == cur->next.end()) {
                cur->next[c] = make_shared<Node>();
            }

            cur = cur->next.find(c)->second;
        }

        cur->value = val;
    }
    
    int sum(string prefix) {
        shared_ptr<Node> cur = root;

        for(const char& c : prefix) {
            if(cur->next.find(c) == cur->next.end()) {
                return 0;
            }

            cur = cur->next.find(c)->second;
        }

        return sum(cur);
    }

private:
    int sum(shared_ptr<Node> node) {
        if(node->next.size() == 0) {
            return node->value;
        }

        int res = node->value;
        for(auto [nextChar, nextElem] : node->next) {
            res += sum(nextElem);
        }

        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */