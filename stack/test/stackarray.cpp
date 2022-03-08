#include <iostream>
#include "../include/stackarray.hpp"
#include <conio.h>

using namespace std;

int main()
{
    // test the stack
    cout << "<-------(Test the stack)------>" << endl;
    StackArray<float> s(10);
    s.push(1.1);
    s.push(2.2);
    s.push(3.3);
    s.push(4.4);
    s.push(5.5);
    s.push(6.689);
    s.onConsole();
    cout << "The size of the stack is: " << s.getSize() << endl;
    cout << "Pop the last element: " << s.pop() << endl;
    for (int i = 1; i <= s.getSize(); i++)
        cout << "Peek the " << i << "th element: " << s.peek(i) << endl;
    s.onConsole();
    cout << "Stack Last Element: " << s.getTop() << endl;
    cout << "Stack First Element: " << s.getBottom() << endl;
    getch();
    return 0;
}