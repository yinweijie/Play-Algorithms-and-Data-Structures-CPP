#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

#include <random>
#include <cstdlib>
#include <ctime>

class QuickSort
{
private:
    using uni_dist_int = std::uniform_int_distribution<int>;
    using dft_rdn_egn = std::default_random_engine;
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
        sort(arr, 0, n - 1);
    }

private:
    template <typename T>
    static void sort(T arr[], int l, int r)
    {
        if(l >= r)
        {
            return;
        }

        int p = partition(arr, l, r);
        sort(arr, l, p - 1);
        sort(arr, p + 1, r);
    }

    template <typename T>
    static int partition(T arr[], int l, int r)
    {
        // std::uniform_int_distribution<int> u(l, r);
        std::uniform_int_distribution<int> u;
        std::default_random_engine e;
        int p = (u(e) % (r - l + 1)) + l;
        swap(arr, l, p);

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

public:
    template <typename T>
    static void sort2(T arr[], int n)
    {
        std::uniform_int_distribution<int> u;
        std::default_random_engine e;
        sort2(arr, 0, n - 1, u, e);
    }

private:
    template <typename T>
    static void sort2(T arr[], int l, int r, uni_dist_int& u, dft_rdn_egn& e)
    {
        if(l >= r)
        {
            return;
        }

        int p = partition2(arr, l, r, u, e);
        sort2(arr, l, p - 1, u, e);
        sort2(arr, p + 1, r, u, e);
    }

    template <typename T>
    static int partition2(T arr[], int l, int r, uni_dist_int& u, dft_rdn_egn& e)
    {
        int p = (u(e) % (r - l + 1)) + l;
        swap(arr, l, p);

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
};

#endif