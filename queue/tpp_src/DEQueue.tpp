template <class T>
DEQueue<T>::DEQueue()
{
    this->front = NULL;
    this->rear = NULL;
    this->size = 0;
}

template <class T>
bool DEQueue<T>::is_empty()
{
    return this->front == NULL;
}

template <class T>
bool DEQueue<T>::is_full()
{
    SingleNode<int> *temp = new SingleNode<int>(0);
    if (temp == NULL)
    {
        return true;
    }
    delete temp;
    return false;
}

template <class T>
int DEQueue<T>::get_size()
{
    return this->size;
}

template <class T>
void DEQueue<T>::enqueue_rear(T item)
{
    SingleNode<T> *newNode = new SingleNode<T>(item);
    if (this->is_full())
    {
        throw overflow_error("DEQueue is full");
    }
    else if (this->is_empty())
    {
        this->rear = this->front = newNode;
    }
    else
    {
        this->rear->setNext(newNode);
        this->rear = newNode;
    }
    this->size++;
}

template <class T>
void DEQueue<T>::enqueue_front(T item)
{
    SingleNode<T> *newNode = new SingleNode<T>(item);
    if (this->is_full())
    {
        throw overflow_error("DEQueue is full");
    }
    else if (this->is_empty())
    {
        this->front = this->rear = newNode;
    }
    else
    {
        newNode->setNext(this->front);
        this->front = newNode;
    }
    this->size++;
}

template <class T>
T DEQueue<T>::dequeue_front()
{
    if (this->is_empty())
    {
        throw underflow_error("DEQueue is empty");
    }
    else if (this->is_full())
    {
        throw overflow_error("DEQueue is full");
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
T DEQueue<T>::dequeue_rear()
{
    if (this->is_empty())
    {
        throw underflow_error("DEQueue is empty");
    }
    else if (this->front->getNext() != NULL)
    {
        SingleNode<T> *temp = this->front;
        while (temp->getNext()->getNext() != NULL)
        {
            temp = temp->getNext();
        }
        T item = temp->getNext()->getData();
        this->rear = temp;
        temp->freeNext();
        this->size--;
        return item;
    }
    else
    {
        T item = this->front->getData();
        delete this->front;
        this->front = this->rear = NULL;
        this->size--;
        return item;
    }
}

template <class T>
void DEQueue<T>::on_display()
{
    cout << "DEQueue Link List:([";
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
void DEQueue<T>::on_display_node()
{
    cout << "Queue Link List: (";
    cout << "Front: (" << *this->front << "), ";
    cout << "Rear: (" << *this->rear << "), ";
    cout << "Size: (" << this->get_size() << "), "
         << ")" << endl;
}