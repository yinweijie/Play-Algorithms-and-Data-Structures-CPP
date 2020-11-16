class BinarySearch
{
private:
    BinarySearch() { }

public:
    template <typename T>
    static int search(T data[], T target, int n)
    {
        return search(data, 0, n - 1, target);
    }

private:
    template <typename T>
    static int search(T data[], int l, int r, T target)
    {
        if(l > r) return -1;

        int mid = l + (r - l) / 2;

        if(data[mid] == target) return mid;

        if(data[mid] < target) return search(data, mid + 1, r, target);

        return search(data, l, mid - 1, target);
    }
};