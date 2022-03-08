#include <iostream>
#include "../include/DEQueue.hpp"

using namespace std;

int main()
{
    cout << "Welcome to DEQueue" << endl;
    DEQueue<int> dq;
    dq.enqueue_rear(1);
    dq.enqueue_front(5);
    dq.enqueue_front(4);
    dq.enqueue_rear(3);
    dq.on_display();
    cout << "Dequeue from Rear: " << dq.dequeue_rear() << endl;
    cout << "Dequeue from Front: " << dq.dequeue_front() << endl;
    dq.on_display();
    dq.on_display_node();
    return 0;
}
