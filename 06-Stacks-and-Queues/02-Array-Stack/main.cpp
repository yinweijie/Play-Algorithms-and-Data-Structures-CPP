#include <iostream>
#include "ArrayStack.h"

using namespace std;

int main()
{
    ArrayStack<int> stack;

    for(int i = 0; i < 5; i++)
    {
        stack.push(i);
        cout << stack << endl;
    }

    stack.pop();
    cout << stack << endl;

    return 0;
}