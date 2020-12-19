#include <iostream>
#include <chrono>
#include <random>
#include <ctime>
#include "UnionFind1.h"
#include "UnionFind2.h"
#include "UnionFind3.h"
#include "UnionFind4.h"

double testUF(UF& uf, int m)
{
    int size = uf.getSize();
    std::uniform_int_distribution<int> u(0, size - 1);
    std::default_random_engine e(time(0));

    auto start = std::chrono::steady_clock::now();

    for(int i = 0; i < m; i++)
    {
        int a = u(e);
        int b = u(e);
        uf.unionElement(a, b);
    }

    for(int i = 0; i < m; i++)
    {
        int a = u(e);
        int b = u(e);
        uf.isConnected(a, b);
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> time = end - start;

    return time.count();
}

int main()
{
    // int size = 100000;
    // int m = 10000;

    int size = 10000000;
    int m = 10000000;

    // UnionFind1 uf1(size);
    // std::cout << "UnionFind1 : " << testUF(uf1, m) << " s" << std::endl;

    // UnionFind2 uf2(size);
    // std::cout << "UnionFind2 : " << testUF(uf2, m) << " s" << std::endl;

    UnionFind3 uf3(size);
    std::cout << "UnionFind3 : " << testUF(uf3, m) << " s" << std::endl;

    UnionFind4 uf4(size);
    std::cout << "UnionFind4 : " << testUF(uf4, m) << " s" << std::endl;

    return 0;
}