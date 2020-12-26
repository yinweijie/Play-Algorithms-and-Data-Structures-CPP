/// Leetcode 387: 字符串中的第一个唯一字符
/// https://leetcode-cn.com/problems/first-unique-character-in-a-string/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq;
        freq.resize(26);

        for(int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }

        for(int i = 0; i < s.size(); i++) {
            if(freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};