#ifndef STACKLINKLIST_HPP
#define STACKLINKLIST_HPP
#include <iostream>
#include "../../linklists/include/node.hpp"

using namespace std;

template <class T>
class StackLinkList
{
private:
    SingleNode<T> *top;
    int size;
    int findPeek(int i);

public:
    StackLinkList();
    void push(T item);
    T pop();
    T peek(int i);
    bool isEmpty();
    bool isFull();
    int getSize();
    T getTop();
    T getBottom();
    // override the << operator to display the stack
    friend ostream &operator<<(ostream &out, const StackLinkList<T> &stack)
    {
        out << "LinkList: data: [ ";
        SingleNode<T> *temp = stack.top;
        while (temp != NULL)
        {
            if (temp->getNext() == NULL)
                out << temp->getData();
            else
                out << temp->getData() << ", ";
            temp = temp->getNext();
        };
        out << " ]";
        return out;
    }
};

#include "../tpp_src/stacklinklist.tpp"

#endif