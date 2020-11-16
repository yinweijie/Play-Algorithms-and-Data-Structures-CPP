class BinarySearch
{
private:
    BinarySearch() { }

public:
    template <typename T>
    static int search(T data[], T target, int n)
    {
        int l = 0, r = n - 1;

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
};