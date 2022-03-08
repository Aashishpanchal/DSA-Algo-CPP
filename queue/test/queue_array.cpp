#include <iostream>
#include "../include/queue_array.hpp"

using namespace std;

int main() {
    // test the Queue
    cout << "<-------(Test the Queue)------>" << endl;
    QueueArray<int> queue(5);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.onDisplay();
    cout << "The size of the queue is: " << queue.getSize() << endl;
    cout << "Dequeue the first element: " << queue.dequeue() << endl;
    cout << "The size of the queue is: " << queue.getSize() << endl;
    queue.onDisplay();
    cout << "First element: " << queue.getFist() << endl;
    cout << "Last element: " << queue.getLast() << endl;
    cout << "Get the element at index 2: " << queue.getElement(2) << endl;
    cout << "Peek the element at index 1: " << queue.peek(1) << endl;
    queue.onDisplay();
    return 0;
}