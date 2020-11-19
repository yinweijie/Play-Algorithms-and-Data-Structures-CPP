// https://leetcode-cn.com/problems/koko-eating-bananas/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1, r = *std::max_element(piles.begin(), piles.end());

        while(l < r) {
            int mid = l + (r - l) / 2;

            if(eatingTime(piles, mid) > H) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l;
    }

private:
    int eatingTime(vector<int>& piles, int k) {
        int res = 0;

        for(auto e: piles) {
            int time = e / k + (e % k == 0 ? 0 : 1);
            res += time;
        }

        return res;
    }
};

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int H = 8;

    cout << Solution().minEatingSpeed(piles, H) << endl;

    return 0;
}