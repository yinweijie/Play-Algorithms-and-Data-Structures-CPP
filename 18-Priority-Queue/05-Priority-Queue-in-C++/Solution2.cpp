// Leetcode 215
// https://leetcode-cn.com/problems/kth-largest-element-in-an-array/

#include <vector>
#include <iostream>
#include <queue>
#include <functional>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for(int i = 0; i < k; i++)
        {
            pq.push(nums[i]);
        }

        for(int i = k; i < nums.size(); i++)
        {
            if(!pq.empty() && nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        vector<int> res;
        res.reserve(k);
        for(int i = 0; i < k; i++)
        {
            int e = pq.top();
            pq.pop();
            res.emplace_back(e);
        }

        return res[0];
    }
};