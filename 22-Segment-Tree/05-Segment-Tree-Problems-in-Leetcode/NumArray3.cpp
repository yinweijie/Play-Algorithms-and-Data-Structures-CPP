/// Leetcode 307. Range Sum Query - Mutable
/// https://leetcode.com/problems/range-sum-query-mutable/description/
///
/// 使用sum数组的思路：TLE

#include <vector>

using namespace std;

class NumArray {
private:
    vector<int> data;
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

        data = nums;
    }

    void update(int index, int val) {
        data[index] = val;
        for(int i = index + 1; i < sum.size(); i++)
        {
            sum[i] = sum[i - 1] + data[i - 1];
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */