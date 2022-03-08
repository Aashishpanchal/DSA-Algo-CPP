// definaion of the queue array class
/*
 * description: initializes the queue array and sets the max size of the queue
 */
template <class T>
QueueArray<T>::QueueArray(int max)
{
    this->queuearray = new T[max];
    this->max = max;
}
/*
 * description: check if the queue is empty, then return true or false
 */
template <class T>
bool QueueArray<T>::isEmpty()
{
    return this->back == -1;
}

/*
 * description: check if the queue is full, then return true or false
 */
template <class T>
bool QueueArray<T>::isFull()
{
    return this->back == this->max - 1;
}

/*
 * description: returns the size of the queue
 */
template <class T>
int QueueArray<T>::getSize()
{
    return this->back + 1;
}

/*
 * description: enqueue the item to the queue,
 * meaning add the item to the back of the queue
 */
template <class T>
void QueueArray<T>::enqueue(T item)
{
    if (isFull())
    {
        throw overflow_error("Queue is full");
    }
    this->queuearray[++this->back] = item;
}

template <class T>
T QueueArray<T>::shirtright()
{
    T item = this->queuearray[0];
    for (int i = 0; i < this->back; i++)
    {
        this->queuearray[i] = this->queuearray[i + 1];
    }
    this->back--;
    return item;
}

/*
 * description: dequeue the item from the queue,
 * meaning remove the item from the front of the queue
 */
template <class T>
T QueueArray<T>::dequeue()
{
    if (isEmpty())
    {
        throw underflow_error("Queue is empty");
    }
    return this->shirtright();
}

/*
 * description: return the item from the front of the queue
 */
template <class T>
T QueueArray<T>::getFist()
{
    if (isEmpty())
    {
        throw underflow_error("Queue is empty");
    }
    return this->queuearray[0];
}

/*
 * description: return the item from the back of the queue
 */
template <class T>
T QueueArray<T>::getLast()
{
    if (isEmpty())
    {
        throw underflow_error("Queue is empty");
    }
    return this->queuearray[this->back];
}

/*
 * description: print all elements of the queue on console
 */
template <class T>
void QueueArray<T>::onDisplay()
{
    cout << "Queue: [ ";
    for (int i = 0; i <= this->back; i++)
    {
        if (i == this->back)
        {
            cout << this->queuearray[i] << " ";
        }
        else
        {
            cout << this->queuearray[i] << ", ";
        }
    }
    cout << "]" << endl;
}

/*
 * description: return the item from the given index
 */
template <class T>
T QueueArray<T>::getElement(int i)
{
    if (i < 0 || i > this->getSize())
    {
        throw out_of_range("Index out of range");
    }
    return this->queuearray[i];
}

/*
 * @param: i: the index of the item to be peeked
 * @return: int: return the peek position
 * @description: peek the item from the stack
 */
template <class T>
int QueueArray<T>::findPeek(int i)
{
    return (this->back - i) + 1;
}

/*
 * @description: return peek element form QueueArray
 */
template <class T>
T QueueArray<T>::peek(int i)
{
    if (i < 0 || i > this->getSize())
    {
        throw out_of_range("Index out of range");
    }
    return this->queuearray[this->findPeek(i)];
}