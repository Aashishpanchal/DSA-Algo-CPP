#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP
#include <iostream>
#include <cmath>
#include "../../queue/include/queue_link_list.hpp"

using namespace std;

template <typename T>
class BinaryTreeNode
{
private:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

public:
    BinaryTreeNode(T data, BinaryTreeNode<T> *left = NULL, BinaryTreeNode<T> *right = NULL);
    ~BinaryTreeNode();
    void setLeft(BinaryTreeNode<T> *left);
    void setRight(BinaryTreeNode<T> *right);
    BinaryTreeNode<T> *getLeft();
    BinaryTreeNode<T> *getRight();
    bool isLeaf();
    void setData(T data);
    T getData();
};

namespace bnt
{
    // this function calculates the total tree nodes in a binary tree
    template <typename T>
    int count_nodes(BinaryTreeNode<T> *root);

    // print the tree in inorder
    template <typename T>
    void print_inorder(BinaryTreeNode<T> *root);

    // level order traversal
    template <typename T>
    void print_level_order(BinaryTreeNode<T> *root);

    // sum of all Intergers Node in a binary tree
    int sum_intergers_nodes(BinaryTreeNode<int> *root);

    // Height of a binary tree
    template <typename T>
    int height(BinaryTreeNode<T> *root);

    // insert a node to a binary tree
    template <typename T>
    void insert(BinaryTreeNode<T> *root, T data);
};

// All the class definitions are defined in the Tpp file
#include "../tpp_src/binary_tree_node.tpp"
// All the namespace definitions are defined in the Tpp file
#include "../tpp_src/binary_tree_namespace.tpp"

#endif