#include <iostream>
#include "Deque.h"

using namespace std;

int main()
{
    Deque<int> queue;

    for(int i = 0; i < 16; i++)
    {
        if(i % 2 == 0)
        {
            queue.addLast(i);
        }
        else
        {
            queue.addFront(i);
        }
        cout << queue << endl;
    }

    for(int i = 0; i < 16; i++)
    {
        if(i % 2 == 0)
        {
            queue.removeFront();
        }
        else
        {
            queue.removeLast();
        }
        cout << queue << endl;
    }
}