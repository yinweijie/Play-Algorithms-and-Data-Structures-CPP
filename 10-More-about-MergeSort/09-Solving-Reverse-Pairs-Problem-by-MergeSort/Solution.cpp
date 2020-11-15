#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int res = 0;
public:
    int reversePairs(vector<int>& nums) {
        vector<int> tmp;
        tmp.resize(nums.size());

        res = 0;
        sort(nums, 0, nums.size() - 1, tmp);
        return res;
    }
private:
    void sort(vector<int>& arr, int l, int r, vector<int>& tmp)
    {
        if(l >= r)
        {
            return;
        }

        int mid = l + (r - l) / 2;
        sort(arr, l, mid, tmp);
        sort(arr, mid + 1, r, tmp);

        if(arr[mid] > arr[mid + 1])
        {
            merge(arr, l, mid, r, tmp);
        }
    }

    void merge(vector<int>& arr, int l, int mid, int r, vector<int>& tmp)
    {
        std::copy(arr.begin() + l, arr.begin() + r + 1, tmp.begin() + l);

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
    }
};

int main()
{
    vector<int> nums = {2, 1, 4, 3};

    cout << Solution().reversePairs(nums) << endl;

    return 0;
}