#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        return search(nums, 0, nums.size() - 1, target);
    }

private:
    int search(vector<int>& nums, int l, int r, int target) {

        if(l > r) return -1;

        int mid = l + (r - l) / 2;

        if(nums[mid] == target) return mid;

        if(nums[mid] < target) return search(nums, mid + 1, r, target);

        return search(nums, l, mid - 1, target);
    }
};