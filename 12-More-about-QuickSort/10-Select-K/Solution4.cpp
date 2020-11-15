#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        std::sort(arr.begin(), arr.end());

        vector<int> res;
        res.resize(k);

        std::copy(arr.begin(), arr.begin() + k, res.begin());

        return res;
    }
};