#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include "BSTSet.h"

using namespace std;

void calcWords(string str)
{
    // ifstream fin("test.txt");
    ifstream fin(str);
    string text;
    vector<string> words1;
    BSTSet<string> set1;

    while(getline(fin, text))
    {
        // -std=c++17
        // 参考：https://www.zhihu.com/question/36642771/answer/865135551
        std::regex ws_re("\\s+"); // whitespace
        std::vector<std::string> v(std::sregex_token_iterator(text.begin(), text.end(), ws_re, -1), std::sregex_token_iterator());
        for(auto&& s: v)
        {
            // std::cout << s <<"\n";
            words1.push_back(s);
            set1.add(s);
        }
    }

    cout << words1.size() << endl;
    cout << set1.getSize() << endl;
}

int main()
{
    cout << "a tale of two cities: " << endl;
    calcWords("a-tale-of-two-cities.txt");

    cout << "pride and prejudice: " << endl;
    calcWords("pride-and-prejudice.txt");
    return 0;
}