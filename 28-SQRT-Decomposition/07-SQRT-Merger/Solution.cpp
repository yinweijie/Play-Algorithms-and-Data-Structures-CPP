/// Leetcode 307. 区域和检索 - 数组可修改
/// https://leetcode-cn.com/problems/range-sum-query-mutable/

#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;

class NumArray {
private:
    function<int(int, int)> merge;
    vector<int> data, block;
    int N;  // 元素总个数
    int B;  // 每组元素个数
    int Bn; // 组数
public:
    NumArray(vector<int>& nums) {
        N = nums.size();
        if(N == 0) return;

        merge = [](int a, int b) {return a + b;};
        B = static_cast<int>(sqrt(N));
        Bn = static_cast<int>(N / B) + (N % B == 0 ? 0 : 1);
        data = nums;

        block.resize(Bn);
        for(int i = 0; i < data.size(); i++) {
            if(i % B == 0) {
                block[i / B] = data[i];
            } else {
                block[i / B] = merge(block[i / B], data[i]);
            }
        }
    }

    void update(int i, int val) {
        if(i < 0 || i >= N) return;

        int blockIndex = i / B;
        data[i] = val;

        block[blockIndex] = data[blockIndex * B];
        for(int j = blockIndex * B + 1; j < std::min((blockIndex + 1) * B, N); j++) {
            block[j / B] = merge(block[j / B], data[j]);
        }
    }
    
    int sumRange(int x, int y) {
        if(x < 0 || x >= N || y < 0 || y >= N || x > y) {
            return 0;
        }

        int blockBeg = x / B;
        int blockEnd = y / B;

        int res = data[x];
        if(blockBeg == blockEnd) {

            for(int i = x + 1; i <= y ; i++) {
                res = merge(res, data[i]);
            }

            return res;
        }

        for(int i = x + 1; i < (blockBeg + 1) * B; i++) {
            res = merge(res, data[i]);
        }
        for(int i = blockBeg + 1; i < blockEnd; i++) {
            res = merge(res, block[i]);
        }
        for(int i = blockEnd * B; i <= y; i++) {
            res = merge(res, data[i]);
        }

        return res;
    }
};