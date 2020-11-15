#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
private:
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    int selectK(vector<int>& nums, int l, int r, int k) {
        int p = partition(nums, l, r);

        if(p == k) return p;
        if(p > k) return selectK(nums, l, p - 1, k);
        return selectK(nums, p + 1, r, k);
    }

    int partition(vector<int>& nums, int l, int r) {
        int p = (rand() % (r - l + 1)) + l;
        swap(nums, l, p);

        // [l + 1, i - 1] <= v, [j + 1, r] >= v
        int i = l + 1, j = r;
        while(true) {
            while(i <= j && nums[i] < nums[l]) {
                i++;
            }
            while(i <= j && nums[j] > nums[l]) {
                j--;
            }

            if(i >= j) {
                break;
            }

            swap(nums, i, j);
            i++;
            j--;
        }

        swap(nums, l, j);

        return j;

    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int resIndx = selectK(nums, 0, nums.size() - 1, nums.size() - k);
        return nums[resIndx];
    }
};

int main() {
    vector<int> nums = {3,2,1,5,6,4};
    int k = 1;

    cout << Solution().findKthLargest(nums, k) << endl;

    return 0;
}