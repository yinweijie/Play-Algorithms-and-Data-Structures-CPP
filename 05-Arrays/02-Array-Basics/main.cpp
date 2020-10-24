#include <iostream>

using namespace std;

int main()
{
    int n = 10;
    int* arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
    delete[] arr;

    n = 3;
    int* scores = new int[n] {100, 99, 66};
    for(int i = 0; i < n; i++)
    {
        cout << scores[i] << endl;
    }

    scores[0] = 96;

    for(int i = 0; i < n; i++)
    {
        cout << scores[i] << endl;
    }

    delete[] scores;

    return 0;
}