#include <iostream>
#include <random>
#include <limits>
#include <ctime>
#include <vector>
#include <chrono>
#include "BST.h"
#include "AVLTree.h"
#include "RBTree.h"

using namespace std;

int main()
{
    // int n = 20000000;
    int n = 200000;

    vector<int> testData;
    testData.reserve(n);
    for(int i = 0; i < n; i++)
    {
        testData.emplace_back(i);
    }

    // test AVLTree
    auto start = std::chrono::steady_clock::now();

    AVLTree<int, int> avl;
    for(auto e : testData)
    {
        avl.add(e, 0);
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> time = end - start;
    cout << "AVLTree: " << time.count() << " s" << endl;

    // test RBTree
    start = std::chrono::steady_clock::now();

    RBTree<int, int> rbt;
    for(auto e : testData)
    {
        rbt.add(e, 0);
    }

    end = std::chrono::steady_clock::now();
    time = end - start;
    cout << "RBTree: " << time.count() << " s" << endl;

    return 0;
}