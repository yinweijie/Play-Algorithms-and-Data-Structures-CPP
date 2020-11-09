#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> tmp;
        tmp.reserve(nums.size());

        return sort(nums, 0, nums.size() - 1, tmp);
    }
private:
    int sort(vector<int>& arr, int l, int r, vector<int>& tmp)
    {
        if(l >= r)
        {
            return 0;
        }

        int res = 0;

        int mid = l + (r - l) / 2;
        res += sort(arr, l, mid, tmp);
        res += sort(arr, mid + 1, r, tmp);

        if(arr[mid] > arr[mid + 1])
        {
            res += merge(arr, l, mid, r, tmp);
        }

        return res;
    }

    int merge(vector<int>& arr, int l, int mid, int r, vector<int>& tmp)
    {
        std::copy(arr.begin() + l, arr.begin() + r + 1, tmp.begin() + l);

        int res = 0;

        int i = l, j = mid + 1;
        for(int k = l; k <= r; k++)
        {
            if(i > mid)
            {
                arr[k] = tmp[j];
                j++;
            }
            else if(j > r)
            {
                arr[k] = tmp[i];
                i++;
            }
            else if(tmp[i] > tmp[j])
            {
                res += mid - i + 1;
                arr[k] = tmp[j];
                j++;
            }
            else
            {
                arr[k] = tmp[i];
                i++;
            }
        }

        return res;
    }
};

int main()
{
    vector<int> nums = {2, 1, 4, 3};

    cout << Solution().reversePairs(nums) << endl;

    return 0;
}