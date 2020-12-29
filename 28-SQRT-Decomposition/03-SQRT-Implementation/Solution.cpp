/// Leetcode 303. 区域和检索 - 数组不可变
/// https://leetcode-cn.com/problems/range-sum-query-immutable/

#include <vector>

using namespace std;

class NumArray {
private:
    vector<int> data, block;
    int N;  // 元素总个数
    int B;  // 每组元素个数
    int Bn; // 组数
public:
    NumArray(vector<int>& nums) {

    }
    
    int sumRange(int i, int j) {

    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */