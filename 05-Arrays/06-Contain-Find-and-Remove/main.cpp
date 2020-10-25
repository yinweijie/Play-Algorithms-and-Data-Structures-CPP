#include <iostream>
#include "Array.h"

using namespace std;

int main()
{
    Array arr(20);

    for(int i = 0; i < 10; i++)
    {
        arr.addLast(i);
    }
    cout << arr << endl;

    arr.add(1, 100);
    cout << arr << endl;

    arr.addFirst(-1);
    cout << arr << endl;

    arr.remove(2);
    cout << arr << endl;

    arr.removeElement(4);
    cout << arr << endl;

    arr.removeFirst();
    cout << arr << endl;

    return 0;
}