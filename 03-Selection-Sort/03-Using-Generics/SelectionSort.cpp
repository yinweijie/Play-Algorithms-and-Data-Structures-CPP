#include <iostream>

using namespace std;

class SelectionSort
{
private:
    SelectionSort() { }

    template <typename T>
    static void swap(T arr[], int i, int j)
    {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
public:
    template <typename T>
    static void sort(T arr[], int n)
    {
        // arr[0...i) 是有序的；arr[i...n) 是无序的
        for(int i = 0; i < n; i++)
        {
            // 选择 arr[i...n) 中的最小值的索引
            int minIndex = i;
            for(int j = i; j < n; j++)
            {
                if(arr[j] < arr[minIndex])
                {
                    minIndex = j;
                }
            }

            swap(arr, minIndex, i);
        }
    }
};

int main()
{
    int arr[] = {1, 4, 2, 3, 6, 5};
    int n = sizeof(arr) / sizeof(int);

    SelectionSort::sort(arr, n);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}