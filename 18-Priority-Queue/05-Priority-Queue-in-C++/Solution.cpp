/// 剑指 Offer 40
/// https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/submissions/

#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int> pq;
        for(int i = 0; i < k; i++)
        {
            pq.push(arr[i]);
        }

        for(int i = k; i < arr.size(); i++)
        {
            if(!pq.empty() && arr[i] < pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
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

        return res;
    }
};