#include <iostream>
#include "LinearSearch.h"

using namespace std;

int main()
{
    int data[] = {24, 18, 12, 9, 16, 66, 32, 4};

    int res = LinearSearch::search(data, sizeof(data), 16);

    cout << res << endl;

    int res2 = LinearSearch::search(data, sizeof(data), 666);

    cout << res2 << endl;

    return 0;
}