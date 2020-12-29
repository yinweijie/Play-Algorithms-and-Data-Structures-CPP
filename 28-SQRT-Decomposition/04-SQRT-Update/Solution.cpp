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

int main()
{
// [0,8],[4,5],[9,11],[2,11],[0,12],[9,12],[2,5],[0,9],[5,9],[0,1],[12,12],[6,7],[5,8],[1,1],[6,7],[10,11],[11,12],[7,8],[4,11],[8,9],[4,11],[2,9],[2,6],[11,12],[5,8],[11,11],[1,9],[12,12],[10,10],[4,7],[12,12],[8,10],[7,9],[4,7],[0,7],[8,9],[10,12],[0,9],[10,12],[7,12],[9,9],[0,12],[1,3],[8,8],[7,10]]
    vector<int> nums = {-8261,2300,-1429,6274,9650,-3267,1414,-8102,6251,-5979,-5291,-4616,-4703};

    NumArray* numArray = new NumArray(nums);
    numArray->sumRange(0, 8); // return 1 ((-2) + 0 + 3)
    // numArray->sumRange(4, 5); // return -1 (3 + (-5) + 2 + (-1)) 
    // numArray->sumRange(9, 11); // return -3 ((-2) + 0 + 3 + (-5) + 2 + (-1))

    delete numArray;

    return 0;
}