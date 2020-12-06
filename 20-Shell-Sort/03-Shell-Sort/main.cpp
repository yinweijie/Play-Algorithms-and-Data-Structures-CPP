#include <iostream>
#include "ShellSort.h"

using namespace std;

int main()
{
    int arr[] = {5, 4, 3, 2, 1};

    ShellSort::sort(arr);

    for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}