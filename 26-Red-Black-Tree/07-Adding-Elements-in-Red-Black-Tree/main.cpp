#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <chrono>
#include <cctype>
#include <exception>
#include "BST.h"
#include "AVLTree.h"
#include "RBTree.h"

using namespace std;

// 参考：https://en.cppreference.com/w/cpp/string/byte/tolower
std::string str_tolower(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(), 
                   [](unsigned char c){ return std::tolower(c); }
                  );
    return s;
}

void calcWords(AVLTree<string, int>& map, string fileName)
{
    // ifstream fin("test.txt");
    ifstream fin(fileName);
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

    cout << "is BST: " << boolalpha << map.isBST() << endl;
    cout << "is Balanced: " << boolalpha << map.isBalanced() << endl;
}

void wordToVector(vector<string>& words, string fileName)
{
    ifstream fin(fileName);
    string text;

    while(getline(fin, text))
    {
        // 参考：https://www.zhihu.com/question/36642771/answer/865135551
        char* token = strtok(const_cast<char*>(text.data()), " ");
        while(token != NULL)
        {
            string word = str_tolower(token);
            words.push_back(word);
            token = strtok(NULL, " ");
        }
    }
}

int main()
{
    // AVLTree<string, int> AVL;

    // calcWords(AVL, "pride-and-prejudice.txt");

    vector<string> words;
    wordToVector(words, "pride-and-prejudice.txt");

    // std::sort(words.begin(), words.end());

    // Test AVLTree

    RBTree<string, int> rbTree;
    for(auto word : words)
    {
        if(rbTree.contains(word))
        {
            rbTree.set(word, rbTree.get(word) + 1);
        }
        else
        {
            rbTree.add(word, 1);
        }
    }

    cout << "Total different words: " << rbTree.getSize() << endl;
    cout << "Frequency of PRIDE: " << rbTree.get("pride") << endl;
    cout << "Frequency of PREJUDICE: " << rbTree.get("prejudice") << endl;

    return 0;
}