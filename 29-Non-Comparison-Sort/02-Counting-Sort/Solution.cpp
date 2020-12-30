/// Leetcode 75. 颜色分类
/// https://leetcode-cn.com/problems/sort-colors/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> cnt(3, 0);
        for(auto num : nums) {
            cnt[num]++;
        }

        for(int i = 0; i < cnt[0]; i++) {
            nums[i] = 0;
        }
        for(int i = cnt[0]; i < cnt[0] + cnt[1]; i++) {
            nums[i] = 1;
        }
        for(int i = cnt[0] + cnt[1]; i < cnt[0] + cnt[1] + cnt[2]; i++) {
            nums[i] = 2;
        }
    }
};