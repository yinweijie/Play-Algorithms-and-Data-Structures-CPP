#include <iostream>
#include "Array.h"
#include "Student.h"

using namespace std;

int main()
{
    Array<int> arr(20);

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

    Array<Student> arr1;
    arr1.addLast(Student("Alice", 100));
    arr1.addLast(Student("Bob", 66));
    arr1.addLast(Student("Charlie", 88));
    cout << arr1 << endl;

    return 0;
}