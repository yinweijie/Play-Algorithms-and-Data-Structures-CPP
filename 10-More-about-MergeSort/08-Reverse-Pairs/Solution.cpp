#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {

        int ret = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(nums[j] < nums[i])
                {
                    ret++;
                }
            }
        }

        return ret;
    }
};

int main()
{
    vector<int> nums = {2, 1, 4, 3};

    cout << Solution().reversePairs(nums) << endl;

    return 0;
}