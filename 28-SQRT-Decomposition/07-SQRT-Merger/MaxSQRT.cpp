#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;

template <typename T>
class SQRTDecomposition
{
private:
    function<T(T, T)> merge;
    vector<T> data, block;
    int N;  // 元素总个数
    int B;  // 每组元素个数
    int Bn; // 组数
public:
    SQRTDecomposition(vector<T>& nums, function<T(T, T)> merge_)
    {
        N = nums.size();
        if(N == 0) return;

        merge = merge_;
        B = static_cast<int>(sqrt(N));
        Bn = static_cast<int>(N / B) + (N % B == 0 ? 0 : 1);
        data = nums;

        block.resize(Bn);
        for(int i = 0; i < data.size(); i++)
        {
            if(i % B == 0)
            {
                block[i / B] = data[i];
            }
            else
            {
                block[i / B] = merge(block[i / B], data[i]);
            }
        }
    }

    void update(int i, T val)
    {
        if(i < 0 || i >= N) return;

        int blockIndex = i / B;
        data[i] = val;

        block[blockIndex] = data[blockIndex * B];
        for(int j = blockIndex * B + 1; j < std::min((blockIndex + 1) * B, N); j++)
        {
            block[j / B] = merge(block[j / B], data[j]);
        }
    }
    
    T queryRange(T x, T y)
    {
        if(x < 0 || x >= N || y < 0 || y >= N || x > y)
        {
            return 0;
        }

        int blockBeg = x / B;
        int blockEnd = y / B;

        T res = data[x];
        if(blockBeg == blockEnd)
        {

            for(int i = x + 1; i <= y ; i++)
            {
                res = merge(res, data[i]);
            }

            return res;
        }

        for(int i = x + 1; i < (blockBeg + 1) * B; i++)
        {
            res = merge(res, data[i]);
        }
        for(int i = blockBeg + 1; i < blockEnd; i++)
        {
            res = merge(res, block[i]);
        }
        for(int i = blockEnd * B; i <= y; i++)
        {
            res = merge(res, data[i]);
        }

        return res;
    }
};

int main()
{
    vector<int> nums = {-8261,2300,-1429,6274,9650,-3267,1414,-8102,6251,-5979,-5291,-4616,-4703};

    SQRTDecomposition<int>* numArray = new SQRTDecomposition<int>(nums, 
            [](int a, int b) {
                return std::max(a, b);
            });
    cout << numArray->queryRange(0, 8) << endl;
    cout << numArray->queryRange(4, 5) << endl;
    cout << numArray->queryRange(9, 11) << endl;

    delete numArray;

    cout << "=====" << endl;

    vector<int> nums2 = {1, 3, 5};

    SQRTDecomposition<int>* numArray2 = new SQRTDecomposition<int>(nums2, 
            [](int a, int b) {
                return a + b;
            });
    cout << numArray2->queryRange(0, 2) << endl;
    numArray2->update(1, 2);
    cout << numArray2->queryRange(0, 2) << endl;

    delete numArray2;

    return 0;
}