#include <random>
#include <stdexcept>
#include <vector>
#include <ctime>
#include <sstream>
#include <iostream>
#include "Student.h"

using namespace std;

int main()
{
    int n = 26 * 26 * 26 * 26;
    vector<Student> students;
    students.reserve(n);
    uniform_int_distribution<int> u(0, 100);
    default_random_engine e(time(0));

    int k = 0;
    for(char c1 = 'a'; c1 <= 'z'; c1++)
    {
        for(char c2 = 'a'; c2 <= 'z'; c2++)
        {
            for(char c3 = 'a'; c3 <= 'z'; c3++)
            {
                for(char c4 = 'a'; c4 <= 'z'; c4++)
                {
                    stringstream os;
                    os << c1 << c2 << c3 << c4;
                    students.emplace_back(os.str(), u(e));
                }
            }
        }
    }

    // 计数排序过程
    int R = 101;

    vector<int> cnt(R , 0);
    for(auto student : students)
    {
        cnt[student.getScore()]++;
    }

    vector<int> index(R + 1, 0);
    for(int i = 0; i < R; i++)
    {
        index[i + 1] = index[i] + cnt[i];
    }

    vector<Student> tmp(students.size(), Student("", 0));
    for(auto student : students)
    {
        tmp[index[student.getScore()]] = student;
        index[student.getScore()]++;
    }

    for(int i = 0; i < n; i++)
    {
        students[i] = tmp[i];
    }

    // 验证计数排序算法
    for(int i = 1; i < n; i++)
    {
        if(students[i - 1].getScore() > students[i].getScore())
        {
            throw std::runtime_error("Sort failed.");
        }

        if(students[i - 1].getScore() == students[i].getScore())
        {
            if(students[i - 1].getName() > students[i].getName())
            {
                throw std::runtime_error("Non-Stable Counting Sort.");
            }
        }
    }
    return 0;
}