// https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int l = *std::max_element(weights.begin(), weights.end());
        int r = std::accumulate(weights.begin(), weights.end(), 0);

        while(l < r) {
            int mid = l + (r - l) / 2;

            if(days(weights, mid) > D) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l;
    }

private:
    int days(vector<int>& weights, int k) {
        int res = 0;
        int packageWeight = 0;

        for(auto weight: weights) {
            if(packageWeight + weight <= k) {
                packageWeight += weight;
            } else {
                res++;
                packageWeight = weight;
            }
        }

        res++;
        return res;
    }
};