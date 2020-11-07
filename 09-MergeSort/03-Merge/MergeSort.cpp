#include <algorithm>
#include <iostream>

using namespace std;

class MergeSort
{
public:
    template <typename T>
    static void merge(T arr[], int l, int mid, int r)
    {
        int n = r - l + 1;
        T tmp[n];
        std::copy(arr, arr + n, tmp);

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
            else if(tmp[i] < tmp[j])
            {
                arr[k] = tmp[i];
                i++;
            }
            else if(tmp[j] <= tmp[i])
            {
                arr[k] = tmp[j];
                j++;
            }
        }

    }
};

int main()
{
    int arr[] = {1, 3, 5, 7, 2, 4, 6, 8};
    int n =  sizeof(arr)/sizeof(int);

    int l = 0, r = n - 1, mid = (l + r) / 2;
    MergeSort::merge(arr, l, mid, r);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}