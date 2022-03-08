#include <iostream>
#include "../include/queue_link_list.hpp"
#include "../../linklists/include/node.hpp"

using namespace std;

template <class T>
QueueLinkList<T>::QueueLinkList()
{
    this->front = NULL;
    this->rear = NULL;
    this->size = 0;
}

template <class T>
bool QueueLinkList<T>::is_empty()
{
    return this->front == NULL;
}

template <class T>
bool QueueLinkList<T>::is_full()
{
    SingleNode<int> *newNode = new SingleNode<int>(0);
    if (newNode == NULL)
    {
        return true;
    }
    else
    {
        delete newNode;
        return false;
    }
}

template <class T>
int QueueLinkList<T>::get_size()
{
    return this->size;
}

template <class T>
void QueueLinkList<T>::enqueue(T item)
{
    SingleNode<T> *newNode = new SingleNode<T>(item);
    if (this->is_empty())
    {
        this->front = this->rear = newNode;
    }
    else
    {
        this->rear->setNext(newNode);
        this->rear = newNode;
    }
    this->size++;
}

template <class T>
T QueueLinkList<T>::dequeue()
{
    if (this->is_empty())
    {
        throw underflow_error("bhai queue empty hai please add kar elements ko");
    }
    else if (this->is_full())
    {
        throw overflow_error("Queue Link List is full");
    }
    else
    {

        SingleNode<T> *temp = this->front;
        this->front = this->front->getNext();
        if (this->front == NULL)
        {
            this->rear = NULL;
        }
        T item = temp->getData();
        delete temp;
        this->size--;
        return item;
    }
}

template <class T>
void QueueLinkList<T>::onDisplay()
{
    cout << "Queue Link List:([";
    SingleNode<T> *temp = this->front;
    while (temp != NULL)
    {
        if (temp == this->rear)
        {
            cout << temp->getData();
        }
        else
        {
            cout << temp->getData() << ", ";
        }
        temp = temp->getNext();
    }
    cout << "]"
         << " size: " << this->get_size() << ")" << endl;
}

template <class T>
void QueueLinkList<T>::onDisplayNode()
{
    cout << "Queue Link List: (";
    cout << "Front: (" << *this->front << "), ";
    cout << "Rear: (" << *this->rear << "), ";
    cout << "Size: (" << this->get_size() << "), "
         << ")" << endl;
}