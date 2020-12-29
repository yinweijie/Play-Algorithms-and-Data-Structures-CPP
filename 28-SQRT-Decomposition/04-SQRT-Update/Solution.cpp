/// Leetcode 307. 区域和检索 - 数组可修改
/// https://leetcode-cn.com/problems/range-sum-query-mutable/

#include <vector>
#include <cmath>

using namespace std;

class NumArray {
private:
    vector<int> data, block;
    int N;  // 元素总个数
    int B;  // 每组元素个数
    int Bn; // 组数
public:
    NumArray(vector<int>& nums) {
        N = nums.size();
        if(N == 0) return;

        B = static_cast<int>(sqrt(N));
        Bn = static_cast<int>(N / B) + (N % B == 0 ? 0 : 1);
        data = nums;

        block.resize(Bn);
        for(int i = 0; i < data.size(); i++) {
            block[i / B] += data[i];
        }
    }

    void update(int i, int val) {
        if(i < 0 || i >= N) return;

        int blockIndex = i / B;
        block[blockIndex] += (val - data[i]);
        data[i] = val;
    }
    
    int sumRange(int x, int y) {
        if(x < 0 || x >= N || y < 0 || y >= N || x > y) {
            return 0;
        }

        int blockBeg = x / B;
        int blockEnd = y / B;

        int sum = 0;
        if(blockBeg == blockEnd) {

            for(int i = x; i <= y ; i++) {
                sum += data[i];
            }

            return sum;
        }

        for(int i = x; i < (blockBeg + 1) * B; i++) {
            sum += data[i];
        }
        for(int i = blockBeg + 1; i < blockEnd; i++) {
            sum += block[i];
        }
        for(int i = blockEnd * B; i <= y; i++) {
            sum += data[i];
        }

        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */