/*
Binary Search Tree
      8
     / \
    4   12
   / \   \
  2   6   10
-> Left node are smaller than the parent node
-> Right node are bigger than the parent node
Note:
    duplicate keys are allowed in BST
You can use and edit my code.
Date: 05/03/2022
*/
#include <iostream>
#include "../include/binary_tree.hpp"

using namespace std;

template <typename T>
class BinarySearchTree {
private:
    // create a root node pointer
    BinaryTreeNode<T>* root;
public:
    BinarySearchTree() {
        // firstly, root is NULL
        this->root = NULL;
    }
    ~BinarySearchTree() {
        delete this->root;
    }
    bool is_empty() {
        return (this->root == NULL);
    }
    bool is_full() {
        BinaryTreeNode<int>* node = new BinaryTreeNode<int>(0);
        if (node == NULL) {
            return true;
        }
        delete node;
        return false;
    }
    // insertion
    void insert(T data) {
        if (this->is_full()) {
            cout << "Tree is full" << endl;
            return;
        }
        // create a new node
        BinaryTreeNode<T>* new_node = new BinaryTreeNode<T>(data);
        // if root is NULL, set root to new node
        if (this->is_empty()) {
            this->root = new_node;
        } else {
            // create a pointer to root
            BinaryTreeNode<T>* current = this->root;
            // create a pointer to parent
            BinaryTreeNode<T>* parent = NULL;
            // loop until current is NULL
            while (current != NULL) {
                // set parent to current
                parent = current;
                // if data is same as current data, return because BST does not allow duplicate keys/data
                if (data == current->getData()) {
                    cout << "Duplicate key " << data << endl;
                    return;
                } else if (data < current->getData()) {
                    // if data is smaller than current, go to left
                    current = current->getLeft();
                } else {
                    // if data is bigger than current, go to right
                    current = current->getRight();
                }
            }
            // if data is smaller than parent, set new node to left
            if (data < parent->getData()) {
                parent->setLeft(new_node);
            } else {
                // if data is bigger than parent, set new node to right
                parent->setRight(new_node);
            }
        }
    }
    // search with loop
    bool search(T data){
        // create a pointer to root
        BinaryTreeNode<T>* current = this->root;
        // loop until current is NULL
        while (current != NULL) {
            // if data is same as current data, return true
            if (data == current->getData()) {
                return true;
            } else if (data < current->getData()) {
                // if data is smaller than current, go to left
                current = current->getLeft();
            } else {
                // if data is bigger than current, go to right
                current = current->getRight();
            }
        }
        // if current is NULL, return false
        return false;
    }
    // search with recursion
    bool search_recursive(T data) {
        return this->search_recursive(this->root, data);
    }
    // search with recursion
    bool search_recursive(BinaryTreeNode<T>* node, T data){
        // if node is NULL, return false
        if (node == NULL) {
            return false;
        }
        // if data is same as current data, return true
        if (data == node->getData()) {
            return true;
        } else if (data < node->getData()) {
            // if data is smaller than current, go to left
            return this->search_recursive(node->getLeft(), data);
        } else {
            // if data is bigger than current, go to right
            return this->search_recursive(node->getRight(), data);
        }
    }
    BinaryTreeNode<T>* get_root(){
        return this->root;
    }
};

int main() {
    BinarySearchTree<int> bst;
    cout << "Insert: " << endl;
    bst.insert(10);bst.insert(5);bst.insert(15);bst.insert(3);bst.insert(7);bst.insert(13);
    bnt::print_inorder(bst.get_root());
    cout << "Search using Loop in BST: " << endl;
    cout << "Search 2: " << (bst.search(2)?"True":"False") << endl;
    cout << "Search 23: " << (bst.search(23)?"True":"False") << endl;
    cout << "Search using Recursion in BST: " << endl;
    cout << "Search 4: " << (bst.search_recursive(4)?"True":"False") << endl;
    cout << "Search 5: " << (bst.search_recursive(5)?"True":"False") << endl;
    bnt::print_inorder(bst.get_root());
    cout << "Level Order Traversal: " << endl;
    bnt::print_level_order(bst.get_root());
    cout << "Count Nodes: " << bnt::count_nodes(bst.get_root()) << endl;

    // Sum of all nodes
    cout << "Sum of all nodes: " << bnt::sum_intergers_nodes(bst.get_root()) << endl;
    // Height of tree
    cout << "Height of tree: " << bnt::height(bst.get_root()) << endl;
    return 0;
}