#ifndef QUEUE_ARRAY_HPP
#define QUEUE_ARRAY_HPP
#include <iostream>

using namespace std;

template <typename T>
class QueueArray
{
private:
    T *queuearray = nullptr;
    int back = -1;
    int max = 0;
    int findPeek(int i);
    T shirtright();
public:
    QueueArray(int max);
    void enqueue(T item);
    void onDisplay();
    bool isEmpty();
    bool isFull();
    int getSize();
    T getElement(int i);
    T dequeue();
    T peek(int i);
    T getFist();
    T getLast();
};

#include "../tpp_src/queue_array.tpp"

#endif