// Leetcode 804. Unique Morse Code Words
// https://leetcode.com/problems/unique-morse-code-words/description/

#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> codes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> set;

        for(auto word: words) {
            string res;
            for(int i = 0; i < word.size(); i++) {
                res.append(codes[word[i] - 'a']);
            }
            set.insert(res);
        }

        return set.size();
    }
};