class BinarySearch
{
private:
    BinarySearch() { }

public:
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
};