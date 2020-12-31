#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <string>

using std::string;

class Student
{
private:
    string name;
    int score;

public:
    Student(const string& name_, int score_) : name(name_), score(score_) { }

    string getName()
    {
        return name;
    }

    int getScore()
    {
        return score;
    }
};

#endif