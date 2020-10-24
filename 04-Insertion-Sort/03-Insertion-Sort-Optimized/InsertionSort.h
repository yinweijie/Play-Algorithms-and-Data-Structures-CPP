#ifndef __INSERTIONSORT_H__
#define __INSERTIONSORT_H__

class InsertionSort
{
private:
    InsertionSort() { }

    template <typename T>
    static void swap(T arr[], int i, int j)
    {
        T t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
public:
    template <typename T>
    static void sort(T arr[], int n)
    {
        for(int i = 1; i < n; i++)
        {
            // 将 arr[i] 插入到合适的位置
            for(int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
            {
                swap(arr, j, j - 1);
            }
            // for(int j = i; j > 0; j--)
            // {
            //     if(arr[j] < arr[j - 1])
            //     {
            //         swap(arr, j, j - 1);
            //     }
            //     else
            //     {
            //         break;
            //     }
            // }
        }
    }
    template <typename T>
    static void sort2(T arr[], int n)
    {
        for(int i = 1; i < n; i++)
        {
            // 将 arr[i] 插入到合适的位置
            T t = arr[i];

            int j;
            for(j = i; j > 0 && t < arr[j - 1]; j--)
            {
                arr[j] = arr[j - 1];
            }

            arr[j] = t;
        }
    }
};

#endif