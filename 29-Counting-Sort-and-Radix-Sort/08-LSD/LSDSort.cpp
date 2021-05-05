#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include <algorithm>

using namespace std;

class LSDSort
{
private:
    LSDSort() { }

public:
    static void sort(vector<string>& arr, int w)
    {
        for(const auto& str : arr)
        {
            if(str.length() != w)
            {
                throw std::invalid_argument("All Strings' length must be the same.");
            }
        }

        // 计数排序过程
        int R = 256; // 0x00 ~ 0xFF+1

        vector<int> cnt(R , 0);
        vector<int> index(R + 1, 0);
        vector<string> tmp(arr.size());
        for(int r = w - 1; r >= 0; r--)
        {                
            std::fill(cnt.begin(), cnt.end(), 0);
            for(const auto& str : arr)
            {
                cnt[str[r]]++;
            }

            for(int i = 0; i < R; i++)
            {
                index[i + 1] = index[i] + cnt[i];
            }

            for(const auto& str : arr)
            {
                tmp[index[str[r]]] = str;
                index[str[r]]++;
            }

            for(int i = 0; i < tmp.size(); i++)
            {
                arr[i] = tmp[i];
            }
        }
    }
};

int main()
{
    vector<string> arr = {"BCA", "CAB", "ACB", "BAC", "ABC", "CBA"};
    LSDSort::sort(arr, 3);

    for(const auto& str : arr)
    {
        cout << str << endl;
    }
    return 0;
}