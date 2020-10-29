#include <iostream>
#include "Deque.h"

using namespace std;

int main()
{
    Deque<int> queue;

    for(int i = 0; i < 2; i++)
    {
        if(i % 2 == 0)
        {
            queue.addLast(i);
            cout << i << endl;
        }
        else
        {
            queue.addFront(i);
            cout << i << endl;
        }
        cout << queue << endl;
    }
}