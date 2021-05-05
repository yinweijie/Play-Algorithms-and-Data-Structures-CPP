#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
#include <iostream>

using namespace std;

class MaxSQRT
{
private:
    vector<int> data, block;
    int N;  // 元素总个数
    int B;  // 每组元素个数
    int Bn; // 组数
public:
    MaxSQRT(vector<int>& nums)
    {
        N = nums.size();
        if(N == 0) return;

        B = static_cast<int>(sqrt(N));
        Bn = static_cast<int>(N / B) + (N % B == 0 ? 0 : 1);
        data = nums;

        block.assign(Bn, std::numeric_limits<int>::min());
        for(int i = 0; i < data.size(); i++)
        {
            block[i / B] = std::max(block[i / B], data[i]);
        }
    }

    void update(int i, int val)
    {
        if(i < 0 || i >= N) return;

        int blockIndex = i / B;
        data[i] = val;

        block[blockIndex] = std::numeric_limits<int>::min();
        for(int j = blockIndex * B; j < std::min((blockIndex + 1) * B, N); j++)
        {
            block[j / B] = std::max(block[j / B], data[j]);
        }
    }
    
    int maxRange(int x, int y) {
        if(x < 0 || x >= N || y < 0 || y >= N || x > y)
        {
            return 0;
        }

        int blockBeg = x / B;
        int blockEnd = y / B;

        int res = std::numeric_limits<int>::min();
        if(blockBeg == blockEnd)
        {

            for(int i = x; i <= y ; i++)
            {
                res = std::max(res, data[i]);
            }

            return res;
        }

        for(int i = x; i < (blockBeg + 1) * B; i++)
        {
            res = std::max(res, data[i]);
        }
        for(int i = blockBeg + 1; i < blockEnd; i++)
        {
            res = std::max(res, block[i]);
        }
        for(int i = blockEnd * B; i <= y; i++)
        {
            res = std::max(res, data[i]);
        }

        return res;
    }
};

int main()
{
    vector<int> nums = {-8261,2300,-1429,6274,9650,-3267,1414,-8102,6251,-5979,-5291,-4616,-4703};

    MaxSQRT* numArray = new MaxSQRT(nums);
    cout << numArray->maxRange(0, 8) << endl;
    cout << numArray->maxRange(4, 5) << endl;
    cout << numArray->maxRange(9, 11) << endl;

    delete numArray;

    return 0;
}