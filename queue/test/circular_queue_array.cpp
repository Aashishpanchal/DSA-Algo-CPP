#include <iostream>
#include "../include/circular_queue_array.hpp"

using namespace std;

int main(){
    cout << "--------- Circular Queue Array Test ---------" << endl;
    CircularQueue<int> queue(5); // but you can add 4 items
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.onDisplay();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.onDisplay();
    return 0;
}