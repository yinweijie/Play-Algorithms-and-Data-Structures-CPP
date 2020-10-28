#include <iostream>
#include "ArrayQueue.h"

using namespace std;

int main()
{
    ArrayQueue<int> queue;

    for(int i = 0; i < 10; i++)
    {
        queue.enqueue(i);
        cout << queue << endl;

        if(i % 3 == 2)
        {
            queue.dequeue();
            cout << queue << endl;
        }
    }

    return 0;
}