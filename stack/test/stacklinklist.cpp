#include <iostream>
#include "../include/stacklinklist.hpp"

int main()
{
    cout << "Test Stack with LinkList" << endl;
    StackLinkList<float> s;
    s.push(1.1);
    s.push(2.2);
    s.push(3.3);
    s.push(4.4);
    s.push(5.5);
    s.push(6.689);
    cout << s << endl;
    cout << "The size of the stack is: " << s.getSize() << endl;
    cout << "Pop the last element: " << s.pop() << endl;
    for (int i = 1; i <= s.getSize(); i++)
        cout << "Peek the " << i << "th element: " << s.peek(i) << endl;
    cout << s << endl;
    cout << "Stack Last Element: " << s.getTop() << endl;
    cout << "Stack First Element: " << s.getBottom() << endl;
    return 0;
}