// https://leetcode-cn.com/problems/binary-search/

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& data, int target)
    {
        int l = 0, r = data.size();

        // 在 data[l, r) 的范围中查找 target
        while(l < r)
        {
            int mid = l + (r - l) / 2;

            if(data[mid] == target) return mid;

            if(data[mid] < target)
            {
                l = mid + 1; // 继续在 data[mid + 1, r) 范围里寻找解
            }
            else
            {
                r = mid; // 继续在 data[l, mid) 范围里寻找解
            }
        }

        return -1;
    }
};