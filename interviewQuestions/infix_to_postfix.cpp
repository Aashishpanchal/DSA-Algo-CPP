#include <iostream>
#include "../stack/include/stacklinklist.hpp"

using namespace std;

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    return 0;
}

string infix_to_postfix(string infix)
{
    StackLinkList<char> s;
    string postfix = "";
    for (size_t i = 0; i < infix.length(); i++)
    {
        if (isOperator(infix[i]))
        {
            if (s.isEmpty())
            {
                s.push(infix[i]);
            }
            else
            {
                while (!s.isEmpty() && precedence(s.getTop()) >= precedence(infix[i]))
                {
                    postfix += s.pop();
                }
                s.push(infix[i]);
            }
        }
        else
        {
            postfix += infix[i];
        }
    }
    while (!s.isEmpty())
    {
        postfix += s.pop();
    }
    return postfix;
}

int main()
{
    cout << "Infix to Postfix Expression With Stack" << endl;

    cout << "This expression convert (x-y/z-k*d) in postfix (" << infix_to_postfix("x-y/z-k*d") << ")" << endl;
    return 0;
}