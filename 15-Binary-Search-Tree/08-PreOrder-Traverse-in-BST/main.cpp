#include <iostream>
#include <vector>
#include "BST.h"

using namespace std;

int main()
{
    BST<int> bst;
    vector<int> nums = {5, 3, 6, 8, 4, 2};
    for(auto num: nums)
    {
        bst.add(num);
    }

    bst.preOrder();

    cout << bst << endl;

    return 0;
}