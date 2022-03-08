#include <iostream>
#include "../stack/include/stacklinklist.hpp"

using namespace std;

bool parenthesisCheck(string expresion)
{
    StackLinkList<char> stack; // create a stack to store the parenthesis
    for (size_t i = 0; i < expresion.length(); i++)
    {
        if (expresion[i] == '(')      // if the current element is '('
            stack.push(expresion[i]); // '(' push into the stack
        else if (expresion[i] == ')') // if the current element is ')'
            if (stack.isEmpty())      // check the stack is empty, so it's not valid
                return false;
            else
                stack.pop(); // ')' pop out the stack
    }
    if (stack.isEmpty()) // check the stack is empty, so the parenthesis is valid
        return true;
    else
        return false;
}

bool match(char a, char b)
{
    if (a == '{' && b == '}')
    {
        return true;
    }
    if (a == '(' && b == ')')
    {
        return true;
    }
    if (a == '[' && b == ']')
    {
        return true;
    }
    return false;
}

bool multipleParenthesisCheck(string expresion)
{
    StackLinkList<char> stack; // create a stack to store the parenthesis
    for (size_t i = 0; i < expresion.length(); i++)
    {
        if (expresion[i] == '(' || expresion[i] == '{' || expresion[i] == '[')
        {
            stack.push(expresion[i]);
        }
        else if (expresion[i] == ')' || expresion[i] == '}' || expresion[i] == ']')
        {
            if (stack.isEmpty())
            {
                return false;
            }
            char popped = stack.pop();
            if (!match(popped, expresion[i]))
            {
                return false;
            }
        }
    }
    if (stack.isEmpty())
        return true;
    else
        return false;
}

int main()
{
    string expresion;
    cout << "Enter the expresion: ";
    cin >> expresion;
    if (parenthesisCheck(expresion))
        cout << "The parenthesis expresion is valid" << endl;
    else
        cout << "The parenthesis expresion is invalid" << endl;
    if (multipleParenthesisCheck(expresion))
        cout << "The multipleParenthesis expresion is valid" << endl;
    else
        cout << "The multipleParenthesis expresion is invalid" << endl;
    return 0;
}