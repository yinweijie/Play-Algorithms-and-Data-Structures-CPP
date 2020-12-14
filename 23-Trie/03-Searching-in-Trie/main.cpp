#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <chrono>
#include "BSTSet.h"
#include "Set.h"
#include "TrieSet.h"
#include "TrieRawPtrSet.h"

using namespace std;

void calcWords(Set<string>& set, string str)
{
    // ifstream fin("test.txt");
    ifstream fin(str);
    string text;
    vector<string> words;

    while(getline(fin, text))
    {
        // 参考：https://www.zhihu.com/question/36642771/answer/865135551
        char* token = strtok(const_cast<char*>(text.data()), " ");
        while(token != NULL)
        {
            words.push_back(token);
            set.add(token);
            token = strtok(NULL, " ");
        }
    }

    for(auto word: words)
    {
        set.contains(word);
    }

    cout << "Total words: " << set.getSize() << endl;
}

int main()
{
    BSTSet<string> bstSet;

    auto start = std::chrono::steady_clock::now();
    calcWords(bstSet, "pride-and-prejudice.txt");
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> time1 = end - start;
    cout << "BST Set: " << time1.count() << " seconds" << endl;

    TrieSet trieSet;

    start = std::chrono::steady_clock::now();
    calcWords(trieSet, "pride-and-prejudice.txt");
    end = std::chrono::steady_clock::now();
    time1 = end - start;
    cout << "Trie Set: " << time1.count() << " seconds" << endl;

    TrieRawPtrSet trieRawPtrSet;

    start = std::chrono::steady_clock::now();
    calcWords(trieRawPtrSet, "pride-and-prejudice.txt");
    end = std::chrono::steady_clock::now();
    time1 = end - start;
    cout << "TrieRawPtr Set: " << time1.count() << " seconds" << endl;

    return 0;
}