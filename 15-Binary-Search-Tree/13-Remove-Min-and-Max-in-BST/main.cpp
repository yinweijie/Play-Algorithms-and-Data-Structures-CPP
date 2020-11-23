#include <iostream>
#include <vector>
#include <random>
#include "BST.h"

using namespace std;

int main()
{
    BST<int> bst;
    uniform_int_distribution<int> u(0, 10000);
    default_random_engine e;

    int n = 1000;

    // test removeMin
    for(int i = 0; i < n; i++)
    {
        bst.add(u(e));
    }

    vector<int> nums;
    while(!bst.isEmpty())
    {
        nums.push_back(bst.removeMin());
    }

    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i - 1] > nums[i])
        {
            throw std::invalid_argument("Error!");
        }
    }
    cout << "removeMin test completed." << endl;

    // test removeMax
    for(int i = 0; i < n; i++)
    {
        bst.add(u(e));
    }

    nums.clear();
    while(!bst.isEmpty())
    {
        nums.push_back(bst.removeMax());
    }

    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i - 1] < nums[i])
        {
            throw std::invalid_argument("Error!");
        }
    }
    cout << "removeMax test completed." << endl;

    return 0;
}