#include <iostream>
#include "../include/binary_tree.hpp"

using namespace std;


int main() {
    BinaryTreeNode<int>* tree = new BinaryTreeNode<int>(5);
    bnt::insert(tree, 1);
    bnt::insert(tree, 2);
    bnt::insert(tree, 3);
    bnt::print_inorder(tree);
    cout << bnt::sum_intergers_nodes(tree) << endl;
}