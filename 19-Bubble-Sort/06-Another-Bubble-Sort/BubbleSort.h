#ifndef __BUBBLESORT_H__
#define __BUBBLESORT_H__

class BubbleSort
{
private:
    BubbleSort() { }

    template <typename T>
    static void swap(T arr[], int i, int j)
    {
        T tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

public:
    template <typename T>
    static void sort(T arr[], int n)
    {
        for(int i = 0; i + 1 < n; i++)
        {
            // arr[0, i) 已排好序
            // 通过冒泡在 arr[i] 位置放上合适的元素
            for(int j = n - 1; j - 1 >= i; j--)
            {
                if(arr[j] < arr[j - 1])
                {
                    swap(arr, j, j - 1);
                }
            }
        }
    }

public:
    template <typename T>
    static void sort2(T arr[], int n)
    {
        for(int i = 0; i + 1 < n; i++)
        {
            // arr[i, n) 已排好序
            // 通过冒泡在 arr[i] 位置放上合适的元素
            bool isSwapped = false;
            for(int j = n - 1; j - 1 >= i; j--)
            {
                if(arr[j] < arr[j - 1])
                {
                    isSwapped = true;
                    swap(arr, j, j - 1);
                }
            }

            if(!isSwapped) break;
        }
    }

public:
    template <typename T>
    static void sort3(T arr[], int n)
    {
        for(int i = 0; i + 1 < n; )
        {
            // arr[0, i) 已排好序
            // 通过冒泡在 arr[i] 位置放上合适的元素
            int lastSwappedIndex = n - 1;
            for(int j = n - 1; j - 1 >= i; j--)
            {
                if(arr[j] < arr[j - 1])
                {
                    lastSwappedIndex = j - 1;
                    swap(arr, j, j - 1);
                }
            }

            if(lastSwappedIndex == n - 1) break;

            i = lastSwappedIndex + 1;
        }
    }
};

#endif