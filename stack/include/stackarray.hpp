#ifndef STACKARRAY_HPP
#define STACKARRAY_HPP
#include <iostream>

using namespace std;

template <class T>
class StackArray
{
private:
    T *stack; // its array pointer
    int top;  // top store index value
    int max;  // max size of stack array
    int findPeek(int i);

public:
    StackArray(int max);
    ~StackArray();
    void push(T item);
    T pop();
    T peek(int i);
    bool isEmpty();
    bool isFull();
    int getSize();
    T getTop();
    T getBottom();
    void onConsole();
};

#include "../tpp_src/stackarray.tpp"

#endif