#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

class QuickSort
{
private:
    QuickSort() { }

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
        sort(arr, 0, n - 1, 0, n);
    }

private:
    template<typename T>
    static void printArray(T arr[], int l, int r)
    {
        cout <<"[";

        for(int i = l; i <= r; i++)
        {
            if(i != r)
            {
                cout << arr[i] << ", ";
            }
            else
            {
                cout << arr[i];
            }
        }

        cout << "]";
    }

    template <typename T>
    static void sort(T arr[], int l, int r, int depth, int n)
    {
        string depthString = generateDepthString(depth);
        cout << depthString;
        cout << "quicksort arr";
        printArray(arr, l, r);
        cout << endl;

        if(l >= r)
        {
            return;
        }

        int p = partition(arr, l, r);

        cout << depthString;
        cout << "partition arr";
        printArray(arr, l, p - 1);
        cout << " " << arr[p] << " ";
        printArray(arr, p + 1, r);
        cout << endl;

        sort(arr, l, p - 1, depth + 1, n);
        sort(arr, p + 1, r, depth + 1, n);

        cout << depthString;
        cout << "after quicksort arr";
        printArray(arr, l, r);
        cout << endl;
    }

    template <typename T>
    static int partition(T arr[], int l, int r)
    {
        // arr[l+1...j] < v ; arr[j+1...i] >= v
        int j = l;
        for(int i = l + 1; i <= r; i++)
        {
            if(arr[i] < arr[l])
            {
                j++;
                swap(arr, i, j);
            }
        }

        swap(arr, j, l);
        return j;
    }

    static string generateDepthString(int depth)
    {
        string s;
        for(int i = 0; i < depth; i++)
        {
            s += "--";
        }

        return s;
    }

};

#endif