#include <iostream>
#include <vector>
#include <random>
#include "BST.h"

using namespace std;

void shuffle(vector<int>& arr)
{
    for(int i = arr.size() - 1; i > 0; i--)
    {
        int pos = std::rand() % i;
        
        int tmp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = tmp;
    }
}

int main()
{
    BST<int> bst;
    int n = 10000;
    uniform_int_distribution<int> u(0, n - 1);
    default_random_engine e;

    for(int i = 0; i < n; i++)
    {
        bst.add(u(e));
    }

    // 注意, 由于随机生成的数据有重复, 所以bst中的数据数量大概率是小于n的

    // order数组中存放[0...n)的所有元素
    vector<int> order;
    order.resize(n);
    for(int i = 0; i < n; i++)
    {
        order[i] = i;
    }
    // 打乱order数组的顺序
    shuffle(order);

    // 乱序删除[0...n)范围里的所有元素
    for(int i = 0; i < n; i++)
    {
        if(bst.contains(order[i]))
        {
            bst.remove(order[i]);
            cout << "After remove " << order[i] << ", size = " << bst.size() << endl;
        }
    }

    cout << boolalpha << bst.isEmpty() << endl;

    return 0;
}