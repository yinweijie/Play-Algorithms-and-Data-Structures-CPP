#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

#include <random>
#include <tuple>

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
        std::uniform_int_distribution<int> u;
        std::default_random_engine e;
        sort(arr, 0, n - 1, u, e);
    }

private:
    template <typename T>
    static void sort(T arr[], int l, int r, uni_dist_int& u, dft_rdn_egn& e)
    {
        if(l >= r)
        {
            return;
        }

        int p = partition(arr, l, r, u, e);
        sort(arr, l, p - 1, u, e);
        sort(arr, p + 1, r, u, e);
    }

    template <typename T>
    static int partition(T arr[], int l, int r, uni_dist_int& u, dft_rdn_egn& e)
    {
        int p = (u(e) % (r - l + 1)) + l;
        swap(arr, l, p);

        // arr[l+1...j] < v ; arr[j+1...i-1] >= v
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
    static void sort2ways(T arr[], int n)
    {
        std::uniform_int_distribution<int> u;
        std::default_random_engine e;
        sort2ways(arr, 0, n - 1, u, e);
    }

private:
    template <typename T>
    static void sort2ways(T arr[], int l, int r, uni_dist_int& u, dft_rdn_egn& e)
    {
        if(l >= r)
        {
            return;
        }

        int p = partition2ways(arr, l, r, u, e);
        sort2ways(arr, l, p - 1, u, e);
        sort2ways(arr, p + 1, r, u, e);
    }

    template <typename T>
    static int partition2ways(T arr[], int l, int r, uni_dist_int& u, dft_rdn_egn& e)
    {
        // 生成 [l, r] 之间的随机索引
        int p = (u(e) % (r - l + 1)) + l;
        swap(arr, l, p);

        // arr[l+1...i-1] <= v; arr[j+1...r] >= v
        int i = l + 1, j = r;
        while(true)
        {
            while(i <= j && arr[i] < arr[l])
            {
                i++;
            }

            while(i <= j && arr[j] > arr[l])
            {
                j--;
            }

            if(i >= j)
            {
                break;
            }

            swap(arr, i, j);
            i++;
            j--;
        }

        swap(arr, j, l);
        return j;
    }

public:
    template <typename T>
    static void sort3ways(T arr[], int n)
    {
        std::uniform_int_distribution<int> u;
        std::default_random_engine e;
        sort3ways(arr, 0, n - 1, u, e);
    }

private:
    template <typename T>
    static void sort3ways(T arr[], int l, int r, uni_dist_int& u, dft_rdn_egn& e)
    {
        if(l >= r)
        {
            return;
        }

        auto[lt, gt] = partition3ways(arr, l, r, u, e); // -std=c++17
        sort3ways(arr, l, lt - 1, u, e);
        sort3ways(arr, gt, r, u, e);
    }

    template <typename T>
    static tuple<int, int> partition3ways(T arr[], int l, int r, uni_dist_int& u, dft_rdn_egn& e)
    {
        // 生成 [l, r] 之间的随机索引
        int p = (u(e) % (r - l + 1)) + l;
        swap(arr, l, p);

        // arr[l + 1, lt] < v, arr[lt + 1, i - 1] == v, arr[gt, r] > v
        int lt = l, gt = r + 1, i = l + 1;
        while(i < gt)
        {
            if(arr[i] < arr[l])
            {
                lt++;
                swap(arr, lt, i);
                i++;
            }
            else if(arr[i] > arr[l])
            {
                gt--;
                swap(arr, gt, i);
            }
            else // arr[i] == v
            {
                i++;
            }
        }

        swap(arr, lt, l);

        return std::make_tuple(lt, gt);
    }
};

#endif