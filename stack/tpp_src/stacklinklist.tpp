// definations of the Stack class
template <class T>
StackLinkList<T>::StackLinkList()
{
    this->top = NULL;
    this->size = 0;
}

/*
    @param: None;
    @return: None;
    @description: its check the stack is empty or not
*/
template <class T>
bool StackLinkList<T>::isEmpty()
{
    return this->top == NULL;
}

/*
    @param: None;
    @return: None;
    @description: its check the stack is full or not
*/
template <class T>
bool StackLinkList<T>::isFull()
{
    SingleNode<int> *temp = new SingleNode<int>(0);
    if (temp == NULL)
        return true;
    else
    {
        delete temp;
        return false;
    }
}

/*
    @param: item: the item to be pushed into the stack;
    @return: None;
    @description: it's push the item into the stack.
*/
template <class T>
void StackLinkList<T>::push(T item)
{
    if (isFull()) // check the stack is full or not
        throw overflow_error("Stack is full");
    SingleNode<T> *temp = this->top;            // make temp point to the top of the stack
    SingleNode<T> *newNode = new SingleNode<T>(item); // make newNode point to the new node
    if (isEmpty())                        // check top is NULL or Not
    {
        this->top = newNode;
    }
    else
    {
        // find the last node
        while (temp->getNext() != NULL)
            temp = temp->getNext();
        // link the new node to the last node
        temp->setNext(newNode);
    }
    this->size++; // increase the size of the stack
}

/*
    @param: None;
    @return: None;
    @description: it's pop the top element from the stack.
*/
template <class T>
T StackLinkList<T>::pop()
{
    if (isEmpty())
        throw underflow_error("Stack is empty");
    SingleNode<T> *temp = this->top; // make pointer to the top node
    T item;
    if (temp->getNext() != NULL)
    {
        // find the defroe top node
        while (temp->getNext()->getNext() != NULL)
            temp = temp->getNext();
        item = temp->getNext()->getData(); // get the top element
        temp->freeNext();                  // free the next node
        this->size--;                      // decrease the size of the stack
        return item;
    }
    else
    {
        item = temp->getData(); // get the top element
        delete this->top;       // free the top node
        this->top = NULL;       // set the top node to NULL
        this->size--;           // decrease the size of the stack
        return item;
    }
}

/*
 * @param: i: the index of the item to be peeked
 * @return: int: return the peek position
 * @description: peek the item from the stack
 */
template <class T>
int StackLinkList<T>::findPeek(int i)
{
    return (this->size - i) + 1; // (top - position  + 1) == top
}

/*
 * @param: None:
 * @return: Int: return the size of the stack
 * @description: return the size of the stack
 */
template <class T>
int StackLinkList<T>::getSize()
{
    return this->size;
}

/*
 * @param: i: the index of the item to be peeked
 * @return: T: return the peeked item
 * @description: peek the item from the stack
 */
template <class T>
T StackLinkList<T>::peek(int i)
{
    int peek_pos = this->findPeek(i);          // find the peek position
    if (peek_pos < 0 || peek_pos > this->size) // check the peek position is valid or not
        throw out_of_range("Peek position is out of range");
    else if (this->isEmpty()) // check the stack is empty or not
        throw underflow_error("Stack is empty");
    SingleNode<T> *temp = this->top;         // make temp point to the top of the stack
    for (int j = 1; j < peek_pos; j++) // find the peek position node
        temp = temp->getNext();
    return temp->getData(); // return the peeked item
}

/*
 * @param: None:
 * @return: T: return the top element of the stack
 * @description: return the top element of the stack
 */
template <class T>
T StackLinkList<T>::getTop()
{
    if (this->isEmpty()) // check the stack is empty or not
        throw underflow_error("Stack is empty");
    SingleNode<T> *temp = this->top;      // make temp point to the top of the stack
    while (temp->getNext() != NULL) // find the top most node
        temp = temp->getNext();
    return temp->getData(); // return the top element
}

/*
 * @param: None:
 * @return: T: return the bottom element
 * @description: return the bottom element
 */
template <class T>
T StackLinkList<T>::getBottom()
{
    if (this->isEmpty()) // check the stack is empty or not
        throw underflow_error("Stack is empty");
    return this->top->getData(); // return the bottom element
}