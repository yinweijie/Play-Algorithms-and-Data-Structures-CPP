/// Leetcode 75. 颜色分类
/// https://leetcode-cn.com/problems/sort-colors/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int R = 3;

        vector<int> cnt(R, 0);
        for(auto num : nums) {
            cnt[num]++;
        }

        vector<int> index(R + 1, 0);
        for(int i = 1; i < index.size(); i++) {
            index[i] = index[i - 1] + cnt[i - 1];
        }
        
        // [index[i], index[i + 1]) 之间的值为i
        for(int i = 0; i + 1 < index.size(); i++) {
            for(int j = index[i]; j < index[i + 1]; j++) {
                nums[j] = i;
            }
        }
    }
};