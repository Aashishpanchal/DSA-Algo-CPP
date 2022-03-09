// -------------- Binary Tree Nodes Class --------------
/*
 * BinaryTreeNode class
 * This class is used to create a node for a binary tree.
 * */
template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(T data, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right)
{
    this->data = data;
    this->left = left;
    this->right = right;
}
/*
 * Free the memory of the node
 * */
template <typename T>
BinaryTreeNode<T>::~BinaryTreeNode()
{
    delete left;
    delete right;
}
/*
 * Set the left node of the current node
 * */
template <typename T>
void BinaryTreeNode<T>::setLeft(BinaryTreeNode<T> *left)
{
    this->left = left;
}
/*
 * Set the right node of the current node
 * */
template <typename T>
void BinaryTreeNode<T>::setRight(BinaryTreeNode<T> *right)
{
    this->right = right;
}
/*
 * Get the left node of the current node
 * */
template <typename T>
BinaryTreeNode<T> *BinaryTreeNode<T>::getLeft()
{
    return this->left;
}
/*
 * Get the right node of the current node
 * */
template <typename T>
BinaryTreeNode<T> *BinaryTreeNode<T>::getRight()
{
    return this->right;
}
/*
 * Check if the current node is a leaf node
 * */
template <typename T>
bool BinaryTreeNode<T>::isLeaf()
{
    return (this->left == NULL && this->right == NULL);
}
/*
 * Set the data of the current node
 * */
template <typename T>
void BinaryTreeNode<T>::setData(T data)
{
    this->data = data;
}
/*
 * Get the data of the current node
 * */
template <typename T>
T BinaryTreeNode<T>::getData()
{
    return this->data;
}