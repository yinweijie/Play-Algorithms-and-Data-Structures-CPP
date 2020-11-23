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

    /////////////////
    //      5      //
    //    /   \    //
    //   3    6    //
    //  / \    \   //
    // 2  4     8  //
    /////////////////

    // bst.preOrder();
    // cout << endl;

    // bst.inOrder();
    // cout << endl;

    // bst.postOrder();
    // cout << endl;

    bst.levelOrder();
    cout << endl;

    return 0;
}