#include <iostream>

using namespace std;

class LinearSearch
{
private:
    LinearSearch() { }
public:
    template <typename T>
    static int search(T data[], int n, T target)
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

int main()
{
    int data[] = {24, 18, 12, 9, 16, 66, 32, 4};

    int res = LinearSearch::search(data, sizeof(data)/sizeof(int), 16);

    cout << res << endl;

    int res2 = LinearSearch::search(data, sizeof(data)/sizeof(int), 666);

    cout << res2 << endl;

    return 0;
}