#include <vector>
#include "LSDSort.h"

using namespace std;

int main()
{
    string arr[] = {"BCA", "CAB", "ACB", "BAC", "ABC", "CBA"};
    int n = sizeof(arr) / sizeof(arr[0]);
    LSDSort::sort(arr, 3, n);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}