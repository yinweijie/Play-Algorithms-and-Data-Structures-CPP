class LinearSearch
{
private:
    LinearSearch() { }
public:
    static int search(int data[], int n, int target)
    {
        for(int i = 0; i < n; i++)
        {
            if(data[i] == target)
            {
                return i;
            }
        }

        return -1;
    }
};