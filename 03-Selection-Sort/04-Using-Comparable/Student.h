#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    string m_name;
    int m_score;

    friend ostream& operator<<(ostream& os, const Student& student);
public:
    Student(const string& name, int score) : m_name(name), m_score(score) { }

    bool operator==(const Student& rhs) const
    {
        if(this == &rhs)
        {
            return true;
        }

        if(&rhs == nullptr)
        {
            return false;
        }

        if(typeid(*this) != typeid(rhs))
        {
            return false;
        }
        
        return (m_name.compare(rhs.m_name) == 0);
    }

    bool operator<(const Student& rhs) const
    {
        return m_score < rhs.m_score;
    }
};

ostream& operator<<(ostream& os, const Student& student)
{
    os << "Student(name: " << student.m_name << ", score: " << student.m_score << ")";

    return os;
}

#endif