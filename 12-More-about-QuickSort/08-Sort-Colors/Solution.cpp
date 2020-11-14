#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
public:
    void sortColors(vector<int>& nums) {

        // nums[0...lt] == 0, nums[lt + 1, i - 1] == 1, nums[gt, n - 1] == 2
        int lt = -1, gt = nums.size(), i = 0;
        while(i < gt) {
            if(nums[i] == 0) {
                lt++;
                swap(nums, i, lt);
                i++;
            } else if(nums[i] == 2) {
                gt--;
                swap(nums, i, gt);
            } else {
                i++;
            }
        }
    }
};