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
#include "HashTable.h"

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
    vector<string> words;
    wordToVector(words, "pride-and-prejudice.txt");

    cout << "Total words: " << words.size() << endl;

    // std::sort(words.begin(), words.end());

    // Test BST

    auto start = std::chrono::steady_clock::now();

    BST<string, int> bst;
    for(auto word : words)
    {
        if(bst.contains(word))
        {
            bst.set(word, bst.get(word) + 1);
        }
        else
        {
            bst.add(word, 1);
        }
    }

    auto end = std::chrono::steady_clock::now();
    chrono::duration<double> time = end - start;
    cout << "BST: " << time.count() << " s" << endl;

    // Test AVLTree

    start = std::chrono::steady_clock::now();

    AVLTree<string, int> avlTree;
    for(auto word : words)
    {
        if(avlTree.contains(word))
        {
            avlTree.set(word, avlTree.get(word) + 1);
        }
        else
        {
            avlTree.add(word, 1);
        }
    }

    end = std::chrono::steady_clock::now();
    time = end - start;
    cout << "AVLTree: " << time.count() << " s" << endl;

    // Test RBTree

    start = std::chrono::steady_clock::now();

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

    end = std::chrono::steady_clock::now();
    time = end - start;
    cout << "RBTree: " << time.count() << " s" << endl;

    // Test HashTable

    start = std::chrono::steady_clock::now();

    HashTable<string, int> ht;
    // HashTable<string, int> ht(131071);
    for(auto word : words)
    {
        if(ht.contains(word))
        {
            ht.set(word, ht.get(word) + 1);
        }
        else
        {
            ht.add(word, 1);
        }
    }

    end = std::chrono::steady_clock::now();
    time = end - start;
    cout << "HashTable: " << time.count() << " s" << endl;

    return 0;
}