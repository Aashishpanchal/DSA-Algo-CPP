#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

using namespace std;

template <typename T>
class SingleNode
{
    private:
        T data;
        SingleNode<T>* next;
    public:
        SingleNode(T data, SingleNode<T>* next = nullptr);
        T getData();
        SingleNode<T> *getNext();
        void setNext(SingleNode<T> *next);
        void freeNext();
        // override the operator << to print the node
        friend ostream& operator<<(ostream& os, SingleNode<T>& node)
        {
            os << "Node: head->";
            SingleNode<T> *temp = &node;
            do
            {
                if (temp == nullptr)
                {
                    os << "NULL";
                    break;
                }
                os << temp->getData() << "->";
                temp = temp->getNext();
                if (temp == &node)
                    os << "---same-repeat--->";
            } while (temp != &node);
            return os;
        }
};

#include "../tpp_src/node.tpp"

#endif