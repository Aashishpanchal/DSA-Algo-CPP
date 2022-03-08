#include "../include/node.hpp"

template <typename T>
SingleNode<T>::SingleNode(T data, SingleNode<T> *next)
{
    this->data = data; // initialize the data
    this->next = next; // initialize the next pointer
};

template <typename T>
T SingleNode<T>::getData()
{
    return this->data; // return the data
};

template <typename T>
SingleNode<T> *SingleNode<T>::getNext()
{
    return this->next; // return the next pointer
}
template <typename T>
void SingleNode<T>::setNext(SingleNode<T> *next)
{
    this->next = next; // set the next pointer
}

template <typename T>
void SingleNode<T>::freeNext()
{
    // check the next pointer is null or not
    if (this->next != NULL)
    {
        delete this->next; // free the next pointer
        this->next = NULL; // set the next pointer to null
    }
}