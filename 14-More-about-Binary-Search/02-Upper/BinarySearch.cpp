#include <iostream>

using namespace std;

class BinarySearch
{
private:
    BinarySearch() { }

public:
    // 非递归实现二分查找法
    template <typename T>
    static int search(T data[], T target, int n)
    {
        int l = 0, r = n - 1;

        // 在 data[l, r] 的范围中查找 target
        while(l <= r)
        {
            int mid = l + (r - l) / 2;

            if(data[mid] == target) return mid;

            if(data[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
    }

public:
    // 递归实现二分查找法
    template <typename T>
    static int searchR(T data[], T target, int n)
    {
        return searchR(data, 0, n - 1, target);
    }

private:
    template <typename T>
    static int searchR(T data[], int l, int r, T target)
    {
        if(l > r) return -1;

        int mid = l + (r - l) / 2;

        if(data[mid] == target) return mid;

        if(data[mid] < target) return searchR(data, mid + 1, r, target);

        return searchR(data, l, mid - 1, target);
    }

public:
    // > target 的最小值索引
    template <typename T>
    static int upper(T data[], T target, int n)
    {
        int l = 0, r = n;

        // 在 data[l, r] 中寻找解
        while(l < r)
        {
            int mid = l + (r - l) / 2;

            if(data[mid] > target)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        return l;
    }
};

int main()
{
    int arr[] = {1, 1, 3, 3, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i <= 6; i++)
    {
        cout << BinarySearch::upper(arr, i, n) << " ";
    }
    cout << endl;

    return 0;
}