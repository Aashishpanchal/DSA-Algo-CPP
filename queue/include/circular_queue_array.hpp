#ifndef CIRCULAR_QUEUE_ARRAY_HPP
#define CIRCULAR_QUEUE_ARRAY_HPP
#include <iostream>

using namespace std;

template <typename T>
class CircularQueue
{
    private:
        T *data = nullptr;
        int front = 0;
        int rear = 0;
        int size = 0;
        int next(int index);
public:
    CircularQueue(int size);
    ~CircularQueue();
    void enqueue(T item);
    T dequeue();
    bool isEmpty();
    bool isFull();
    void onDisplay();
};

#include "../tpp_src/circular_queue_array.tpp"
#endif