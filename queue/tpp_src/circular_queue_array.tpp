template <class T>
CircularQueue<T>::CircularQueue(int size)
{
    this->data = new T[size];
    this->size = size;
}

template <class T>
CircularQueue<T>::~CircularQueue()
{
    delete[] this->data;
}

template <class T>
int CircularQueue<T>::next(int index)
{
    return (index + 1) % this->size;
}

template <class T>
bool CircularQueue<T>::isEmpty()
{
    return this->front == this->rear;
}

template <class T>
bool CircularQueue<T>::isFull()
{
    return this->next(this->rear) == this->front;
}

template <class T>
void CircularQueue<T>::enqueue(T item){
    if (this->isFull()){
        throw overflow_error("Circular Queue is full");
    }
    this->rear = this->next(this->rear);
    this->data[this->rear] = item;
}

template <class T>
T CircularQueue<T>::dequeue(){
    if (this->isEmpty()){
        throw underflow_error("Circular Queue is empty");
    }
    T item = this->data[this->front];
    this->front = this->next(this->front);
    return item;
}

template <class T>
void CircularQueue<T>::onDisplay(){
        int index = this->front;
        cout << "Circular Queue: [ ";
        while (index != this->rear){
            index = this->next(index);
            if (index == this->rear){
                cout << this->data[index] << " ";
            } else {
                cout << this->data[index] << ", ";
            }
        }
        cout << "]" << endl;
}