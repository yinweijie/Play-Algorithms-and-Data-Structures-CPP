/// 303. Range Sum Query - Immutable
/// https://leetcode.com/problems/range-sum-query-immutable/description/

#include <vector>

using namespace std;

class NumArray {
private:
    vector<int> sum; // sum[i]存储前i个元素和, sum[0] = 0
                     // 即sum[i]存储nums[0...i-1]的和
                     // sum(i, j) = sum[j + 1] - sum[i]
public:
    NumArray(vector<int>& nums) {
        sum = vector<int>(nums.size() + 1);
        sum[0] = 0;
        for(int i = 1; i < sum.size(); i++)
        {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */