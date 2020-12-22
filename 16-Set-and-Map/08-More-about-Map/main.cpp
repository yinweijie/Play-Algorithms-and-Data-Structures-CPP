#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <chrono>
#include <cctype>
#include "Map.h"
#include "BSTMap.h"
#include "LinkedListMap.h"

using namespace std;

// 参考：https://en.cppreference.com/w/cpp/string/byte/tolower
std::string str_tolower(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(), 
                   [](unsigned char c){ return std::tolower(c); }
                  );
    return s;
}

void calcWords(Map<string, int>& map, string str)
{
    // ifstream fin("test.txt");
    ifstream fin(str);
    string text;

    while(getline(fin, text))
    {
        // 参考：https://www.zhihu.com/question/36642771/answer/865135551
        char* token = strtok(const_cast<char*>(text.data()), " ");
        while(token != NULL)
        {
            string word = str_tolower(token);
            if(map.contains(word))
            {
                map.set(word, map.get(word) + 1);
            }
            else
            {
                map.add(word, 1);
            }
            token = strtok(NULL, " ");
        }
    }

    cout << "Total different words: " << map.getSize() << endl;
    cout << "Frequency of PRIDE: " << map.get("pride") << endl;
    cout << "Frequency of PREJUDICE: " << map.get("prejudice") << endl;
}

int main()
{
    BSTMap<string, int> bstMap;

    auto start = std::chrono::steady_clock::now();
    calcWords(bstMap, "pride-and-prejudice.txt");
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> time1 = end - start;

    cout << "BST Map: " << time1.count() << " s" << endl;

    LinkedListMap<string, int> linkedListMap;
    start = std::chrono::steady_clock::now();
    calcWords(linkedListMap, "pride-and-prejudice.txt");
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> time2 = end - start;

    cout << "LinkedListMap Map: " << time2.count() << " s" << endl;

    return 0;
}