#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

// 同时也修改 partition 的定义
class Solution {
private:
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    // 在 arr[l, r) 范围里寻找第 k 小的数字
    int selectK(vector<int>& nums, int k) {

        int l = 0, r = nums.size();

        while(l < r) {
            int p = partition(nums, l, r);

            if(p == k) return p;

            if(p > k) {
                r = p;
            } else {
                l = p + 1;
            }
        }

        throw std::runtime_error("No Solution");
    }

    // 在 arr[l, r) 进行 partition
    int partition(vector<int>& nums, int l, int r) {
        int p = (rand() % (r - l)) + l; // r - l + 1改为r - l
        swap(nums, l, p);

        // [l + 1, i - 1] <= v, [j + 1, r) >= v
        int i = l + 1, j = r - 1; // r改为r - 1
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
        int resIndx = selectK(nums, nums.size() - k); // nums.size() - 1改为nums.size()
        return nums[resIndx];
    }
};

int main() {
    vector<int> nums = {3,2,1,5,6,4};
    int k = 1;

    cout << Solution().findKthLargest(nums, k) << endl;

    return 0;
}