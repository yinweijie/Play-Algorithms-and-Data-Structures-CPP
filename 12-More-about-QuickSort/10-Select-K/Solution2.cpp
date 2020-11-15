#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    void swap(vector<int>& arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    int selectK(vector<int>& arr, int l, int r, int k) {
        int p = partition(arr, l, r);

        if(k == p) return p;
        if(k < p) return selectK(arr, l, p - 1, k);
        return selectK(arr, p + 1, r, k);
    }

    int partition(vector<int>& arr, int l, int r) {
        int p = (rand() % (r - l + 1)) + l;
        swap(arr, l, p);

        // [l + 1, i - 1] <= v, [j + 1, r] >= v
        int i = l + 1, j = r;
        while(true) {
            while(i <= j && arr[i] < arr[l]) {
                i++;
            }
            while(i <= j && arr[j] > arr[l]) {
                j--;
            }

            if(i >= j) break;

            swap(arr, i, j);
            i++;
            j--;
        }

        swap(arr, l, j);
        return j;
    }
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;

        if(k < 1) return res;

        res.resize(k);

        int indx = selectK(arr, 0, arr.size() - 1, k - 1);

        // for(int i = 0; i < k; i++) {
        //     res.emplace_back(arr[i]);
        // }
        std::copy(arr.begin(), arr.begin() + k, res.begin());

        return res;
    }
};

int main() {
    vector<int> nums = {1,3,5,7,2,4,6,8};

    int k = 4;

    vector<int> res = Solution().getLeastNumbers(nums, k);

    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

    return 0;
}