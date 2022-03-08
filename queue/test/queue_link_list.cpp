#include <iostream>
#include "../include/queue_link_list.hpp"

using namespace std;

int main(){
    QueueLinkList<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.onDisplay();
    cout << "Dequeue Element in Queue: " << q.dequeue() << endl;
    q.onDisplay();
    q.onDisplayNode();
    return 0;
}