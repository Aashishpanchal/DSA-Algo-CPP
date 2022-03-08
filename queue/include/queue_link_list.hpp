#ifndef QUEUE_LINK_LIST_HPP
#define QUEUE_LINK_LIST_HPP
#include "../../linklists/include/node.hpp"

template <class T>
class QueueLinkList 
{
    private:
        SingleNode<T> *front = nullptr;
        SingleNode<T> *rear = nullptr;
        int size;
    public:
        QueueLinkList();
        void enqueue(T item);
        T dequeue();
        bool is_empty();
        bool is_full();
        int get_size();
        void onDisplay();
        void onDisplayNode();
};

#include "../tpp_src/queue_link_list.tpp"

#endif