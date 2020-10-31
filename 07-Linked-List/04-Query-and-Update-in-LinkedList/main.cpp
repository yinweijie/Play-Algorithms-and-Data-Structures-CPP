#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList<int> linkedList;

    for(int i = 0; i < 5; i++)
    {
        linkedList.addFirst(i);
        cout << linkedList << endl;
    }

    linkedList.add(2, 666);
    cout << linkedList << endl;

    return 0;
}