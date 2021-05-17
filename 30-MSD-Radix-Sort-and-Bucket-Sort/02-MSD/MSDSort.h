#ifndef __MSDSORT_H__
#define __MSDSORT_H__

#include <string>
#include <vector>

using namespace std;

// 注意：这一小节，这个算法没有完成
class MSDSort
{
private:
    MSDSort() { }

public:
    static void sort(string arr[], int n)
    {
        sort(arr, 0, n - 1, 0);
    }

private:
    // 根据 r 位置的字符，处理 arr[left, right]
    // 注意：这一小节，这个算法没有完成
    static void sort(string arr[], int left, int right, int r)
    {
        if(left >= right) return;

        // 计数排序过程
        int R = 256; // 0x00 ~ 0xFF

        vector<int> cnt(R + 1 , 0); // ' ' 字符的编号为0，其他字符整体编号后移一位
        vector<int> index(R + 2, 0);
        vector<string> tmp(right - left + 1);

        // O(n)
        for(int i = left; i <= right; i++)
        {
            // ' ' 被认为是最小的字符，编号为0，后面的字符编号为ascii码值加一，即整体往后偏移一位
            int p = (r >= arr[i].length()) ? 0 : (arr[i][r] + 1);
            cnt[p]++;
        }

        // O(R)
        for(int i = 0; i < R + 1; i++)
        {
            index[i + 1] = index[i] + cnt[i];
        }

        // O(n)
        for(int i = left; i <= right; i++)
        {
            int p = (r >= arr[i].length()) ? 0 : (arr[i][r] + 1);
            tmp[index[p]] = arr[i];
            index[p]++;
        }

        // O(n)
        for(int i = left; i <= right; i++)
        {
            arr[i] = tmp[i - left];
        }

        // TODO: 递归下去
    }
};

#endif