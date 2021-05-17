#ifndef __LSDSORT_H__
#define __LSDSORT_H__

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
    static void sort(string* arr, int w, int n)
    {
        for(int i = 0; i < n; i++)
        {
            if(arr[i].length() != w)
            {
                throw std::invalid_argument("All Strings' length must be the same.");
            }
        }

        // 计数排序过程
        int R = 256; // 0x00 ~ 0xFF

        /// O(w * (n + R)) ==> O(n)
        vector<int> cnt(R , 0);
        vector<int> index(R + 1, 0);
        vector<string> tmp(n);
        for(int r = w - 1; r >= 0; r--)
        {                
            // O(n)
            std::fill(cnt.begin(), cnt.end(), 0);
            for(int i = 0; i < n; i++)
            {
                cnt[arr[i][r]]++;
            }

            // O(R)
            for(int i = 0; i < R; i++)
            {
                index[i + 1] = index[i] + cnt[i];
            }

            // O(n)
            for(int i = 0; i < n; i++)
            {
                tmp[index[arr[i][r]]] = arr[i];
                index[arr[i][r]]++;
            }

            // O(n)
            for(int i = 0; i < tmp.size(); i++)
            {
                arr[i] = tmp[i];
            }
        }
    }
};

#endif