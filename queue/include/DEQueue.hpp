#ifndef DEQUEUE_HPP
#define DEQUEUE_HPP
#include <iostream>
#include "../../linklists/include/node.hpp"

using namespace std;

template <class T>
class DEQueue {
private:
    SingleNode<T> *front;
    SingleNode<T> *rear;
    int size;
public:
    DEQueue();
    void enqueue_front(T item);
    void enqueue_rear(T item);
    T dequeue_front();
    T dequeue_rear();
    bool is_empty();
    bool is_full();
    int get_size();
    void on_display();
    void on_display_node();
    T get_front();
    T get_rear();
};

#include "../tpp_src/DEQueue.tpp"

#endif
