// --------------- Binary Tree NameSpace ---------------
/*
Definations of bnt namespace
*/

template <typename T>
int bnt::count_nodes(BinaryTreeNode<T> *root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + count_nodes(root->getLeft()) + count_nodes(root->getRight());
};

// print the tree in inorder
template <typename T>
void node_print_inorder(BinaryTreeNode<T> *root)
{
    if (root == NULL)
        return;
    node_print_inorder(root->getLeft());
    cout << root->getData() << " ";
    node_print_inorder(root->getRight());
};
// print the tree in inorder
template <typename T>
void bnt::print_inorder(BinaryTreeNode<T> *root)
{
    if (root == NULL)
        return;
    cout << "Inorder: [ ";
    node_print_inorder(root);
    cout << "]\n";
};

// level order traversal
template <typename T>
void bnt::print_level_order(BinaryTreeNode<T> *root)
{
    /*
    This method is not recursive, like inorder_print()
    its a iterative method and use queue
    you know, queue is a FIFO data structure
    */
    BinaryTreeNode<T> *current = root;
    QueueLinkList<BinaryTreeNode<T> *> q;
    // if root is NULL, return
    if (root == NULL)
    {
        cout << "Root Node is NULL....." << endl;
        std::exit(1);
    }
    // push root to queue
    q.enqueue(current);
    q.enqueue(NULL); // add NULL for break link
    while (!q.is_empty())
    {
        current = q.dequeue(); // get current node
        if (current == NULL)
        {
            cout << endl; // break line
            if (q.is_empty())
            {
                break; // if queue is empty, break current loop
            }
            else
            {
                q.enqueue(NULL);
            }
        }
        else
        {
            cout << current->getData() << " "; // print current data
            if (current->getLeft() != NULL)
            {
                q.enqueue(current->getLeft());
            }
            if (current->getRight() != NULL)
            {
                q.enqueue(current->getRight());
            }
        }
    }
};

// sum of all Intergers Node in a binary tree
int bnt::sum_intergers_nodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int leftSum = sum_intergers_nodes(root->getLeft());
    int rightSum = sum_intergers_nodes(root->getRight());

    return root->getData() + leftSum + rightSum;
};

// Height of a binary tree
template <typename T>
int bnt::height(BinaryTreeNode<T> *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = height(root->getLeft());
    int rightHeight = height(root->getRight());
    int maxHeight = max(leftHeight, rightHeight) + 1;
    return maxHeight;
};

// insert a node to a binary tree
template <typename T>
void bnt::insert(BinaryTreeNode<T> *root, T data){
    BinaryTreeNode<T> *newNode = new BinaryTreeNode<T>(data);
    if (newNode == NULL){
        cout << "Memory allocation failed" << endl;
        std::exit(1);
    }
    if (root == NULL){
        root = newNode;
        return;
    }
    BinaryTreeNode<T> *current = root;
    QueueLinkList<BinaryTreeNode<T> *> q;
    q.enqueue(current);
    while (!q.is_empty())
    {
        current = q.dequeue();
        if (current->getLeft() == NULL){
            current->setLeft(newNode);
            break;
        }else {
            q.enqueue(current->getLeft());
        }
        if (current->getRight() == NULL){
            current->setRight(newNode);
            break;
        }else {
            q.enqueue(current->getRight());
        }
    }
}

// /*
//  * Delete a node from a binary tree
//  * */
// template <typename T>
// void bnt::delete_node(BinaryTreeNode<T> *root, T data)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     if (root->getData() == data)
//     {
//         if (root->isLeaf())
//         {
//             delete root;
//             return;
//         }
//         if (root->getLeft() == NULL)
//         {
//             BinaryTreeNode<T> *temp = root->getRight();
//             delete root;
//             root = temp;
//             return;
//         }
//         if (root->getRight() == NULL)
//         {
//             BinaryTreeNode<T> *temp = root->getLeft();
//             delete root;
//             root = temp;
//             return;
//         }
//         BinaryTreeNode<T> *temp = root->getRight();
//         while (temp->getLeft() != NULL)
//         {
//             temp = temp->getLeft();
//         }
//         root->setData(temp->getData());
//         delete_node(root->getRight(), temp->getData());
//         return;
//     }
//     delete_node(root->getLeft(), data);
//     delete_node(root->getRight(), data);
// }