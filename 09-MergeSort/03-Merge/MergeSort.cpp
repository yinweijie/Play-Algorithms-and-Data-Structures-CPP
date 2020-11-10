#include <algorithm>
#include <iostream>

using namespace std;

class MergeSort
{
private:
    MergeSort() { }
public:
    template <typename T>
    static void sort(T arr[], int n)
    {

    }
private:
    // 合并两个有序的区间 arr[l, mid] 和 arr[mid + 1, r]
    template <typename T>
    static void merge(T arr[], int l, int mid, int r)
    {
        int n = r - l + 1;
        T* tmp = new T[n];
        std::copy(arr, arr + n, tmp);

        int i = l, j = mid + 1;

        for(int k = l; k <= r; k++)
        {
            if(i > mid)
            {
                arr[k] = tmp[j - l]; // temp索引从0开始，arr索引从l开始
                j++;
            }
            else if(j > r)
            {
                arr[k] = tmp[i - l];
                i++;
            }
            else if(tmp[i - l] < tmp[j - l])
            {
                arr[k] = tmp[i - l];
                i++;
            }
            else
            {
                arr[k] = tmp[j - l];
                j++;
            }
        }

        delete[] tmp;
    }
};

int main()
{
    int arr[] = {1, 3, 5, 7, 2, 4, 6, 8};
    int n =  sizeof(arr)/sizeof(int);

    int l = 0, r = n - 1, mid = (l + r) / 2;
    // MergeSort::merge(arr, l, mid, r);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}