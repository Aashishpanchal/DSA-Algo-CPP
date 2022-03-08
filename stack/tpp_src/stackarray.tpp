// definations of the class
/*
 * @param max: the max size of the stack
 * @return: none
 * @description: constructor, initialize the stack
 */
template <class T>
StackArray<T>::StackArray(int max)
{
    this->max = max;
    stack = new T[max];
    top = -1;
}
/*
 * @param: none
 * @return: none
 * @description: destructor, its release the memory
 */
template <class T>
StackArray<T>::~StackArray()
{
    delete[] stack;
}

/*
 * @param: none
 * @return: none
 * @description: return the boolean value of the stack is empty or not
 */
template <class T>
bool StackArray<T>::isEmpty()
{
    return top == -1;
}
/*
 * @param: none
 * @return: none
 * @description: return the boolean value of the stack is full or not
 */
template <class T>
bool StackArray<T>::isFull()
{
    return top == max - 1;
}

/*
 * @param: none:
 * @return: none:
 * @description: print all stack elements in terminal
 */
template <class T>
void StackArray<T>::onConsole()
{
    cout << "Stack: [ ";
    for (int i = 0; i <= this->top; i++)
    {
        if (i == this->top)
            cout << stack[i];
        else
            cout << stack[i] << ", ";
    };
    cout << " ]" << endl;
    ;
}

/*
 * @param: item: the item to be pushed into the stack
 * @return: none
 * @description: push the item into the stack
 */
template <class T>
void StackArray<T>::push(T item)
{
    if (this->isFull())
        throw overflow_error("Stack is full");
    this->stack[++this->top] = item;
}

/*
 * @param: none:
 * @return: T: the item to be popped from the stack
 * @description: pop the item from the stack
 */
template <class T>
T StackArray<T>::pop()
{
    if (this->isEmpty())
        throw underflow_error("Stack is empty");
    else
        return this->stack[this->top--];
}

template <class T>
int StackArray<T>::getSize()
{
    return this->top + 1;
}

/*
 * @param: i: the index of the item to be peeked
 * @return: int: return the peek position
 * @description: peek the item from the stack
 */
template <class T>
int StackArray<T>::findPeek(int i)
{
    return (this->top - i) + 1; // (top - position  + 1) == top
}

template <class T>
T StackArray<T>::peek(int i)
{
    int peek_pos = this->findPeek(i);
    if (peek_pos < 0 || peek_pos > this->top)
        throw out_of_range("Peek position is out of range");
    else if (this->isEmpty())
        throw underflow_error("Stack is empty");
    return this->stack[peek_pos];
}

template <class T>
T StackArray<T>::getTop(){
    if (this->isEmpty())
        throw underflow_error("Stack is empty");
    return this->stack[this->top];
}

template <class T>
T StackArray<T>::getBottom(){
    if (this->isEmpty())
        throw underflow_error("Stack is empty");
    return this->stack[0];
}