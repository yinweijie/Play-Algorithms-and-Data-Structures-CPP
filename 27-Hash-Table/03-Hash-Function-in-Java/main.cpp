#include <iostream>
#include <string>
#include <functional>
#include <limits>
#include <unordered_set>
#include <unordered_map>
#include "Student.h"

using namespace std;

int main()
{
    int a = 42;
    cout << hash<int>()(a) << endl;

    int b = -42;
    cout << hash<int>()(b) << endl;

    double c = 3.1415926;
    cout << hash<double>()(c) << endl;

    string d = "imooc";
    cout << hash<string>()(d) << endl;

    // cout << hash<int>()(std::numeric_limits<int>::max() + 1) << endl;

    cout << endl;

    Student student(3, 2, "Bobo"s, "Liu"s);
    cout << MyHash()(student) << endl;

    unordered_set<Student, MyHash> stu_set;
    stu_set.insert(student);

    unordered_map<Student, int, MyHash> stu_map;
    stu_map[student] = 10;

    Student student2(3, 2, "Bobo"s, "Liu"s);
    cout << MyHash()(student2) << endl;

    return 0;
}