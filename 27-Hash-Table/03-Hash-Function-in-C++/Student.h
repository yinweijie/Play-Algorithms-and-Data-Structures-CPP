#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <string>
#include <functional>
#include <cctype>
#include <algorithm>

using namespace std;

struct Student
{
    int grade;
    int cls;
    string firstName;
    string lastName;

    Student(int grade_, int cls_, const string& firstName_, const string& lastName_) : 
            grade(grade_), cls(cls_), firstName(firstName_), lastName(lastName_) { }

    bool operator==(const Student& rhs) const
    {
        if(this == &rhs)
        {
            return true;
        }

        return grade == rhs.grade && cls == rhs.cls &&
                firstName == firstName && lastName == rhs.lastName;
    }

};

// 参考：https://en.cppreference.com/w/cpp/string/byte/tolower
std::string str_tolower(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(), 
                   [](unsigned char c){ return std::tolower(c); }
                  );
    return s;
}

class MyHash
{
public:
    size_t operator()(const Student& student) const
    {
        size_t B = 31;
        size_t myhash = 0;
        myhash = myhash * B + hash<int>()(student.grade);
        myhash = myhash * B + hash<int>()(student.cls);
        myhash = myhash * B + hash<string>()(str_tolower(student.firstName));
        myhash = myhash * B + hash<string>()(str_tolower(student.lastName));

        return myhash;
    }
};

#endif