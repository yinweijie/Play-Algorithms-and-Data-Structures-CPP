#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <cctype>
#include "BSTSet.h"

using namespace std;

// 参考：https://en.cppreference.com/w/cpp/string/byte/tolower
std::string str_tolower(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(), 
                   [](unsigned char c){ return std::tolower(c); }
                  );
    return s;
}

void calcWords(string str)
{
    // ifstream fin("test.txt");
    ifstream fin(str);
    string text;
    vector<string> words;
    BSTSet<string> set;

    while(getline(fin, text))
    {
        // 参考：https://www.zhihu.com/question/36642771/answer/865135551
        char* token = strtok(const_cast<char*>(text.data()), " ");
        while(token != NULL)
        {
            string word = str_tolower(token);
            words.push_back(word);
            set.add(word);
            token = strtok(NULL, " ");
        }
    }

    cout << words.size() << endl;
    cout << set.getSize() << endl;
}

int main()
{
    cout << "a tale of two cities: " << endl;
    calcWords("a-tale-of-two-cities.txt");

    cout << "pride and prejudice: " << endl;
    calcWords("pride-and-prejudice.txt");
    return 0;
}