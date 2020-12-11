#include "SegmentTree.h"

int main()
{
    vector<int> nums = {-2, 0, 3, -5, 2, -1};

    SegmentTree<int> segTree(nums, 
            [](int a, int b)
            {
                return a + b;
            });

    cout << segTree << endl;

    return 0;
}