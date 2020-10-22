#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <string>

using namespace std;

class Student
{
private:
    string m_name;

public:
    Student(const string& name) : m_name(name) { }

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
};

#endif