#include <iostream>

using namespace std;

// 计算arr[l...n)这个区间内所有数字的和
int sum(int* arr, int n, int l)
{
    if(l == n)
    {
        return 0;
    }
    return arr[l] + sum(arr, n, l + 1);
}

int sum(int* arr, int n)
{
    return sum(arr, n, 0);
}

int main()
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(nums) / sizeof(int);
    cout << sum(nums, n) << endl;
}