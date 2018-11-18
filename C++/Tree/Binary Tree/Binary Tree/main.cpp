//
//  main.cpp
//  Binary Tree
//
//  Created by mye on 2018/9/15.
//  Copyright © 2018 mye. All rights reserved.
//

#include <iostream>
#include "BST.hpp"

template <class T>
void testTemplate(const T &t) {
    
}

int main(int argc, const char * argv[]) {
    
    BST<int> *binaryTree = new BST<int>();
    binaryTree->insert(15);
    binaryTree->insert(10);
    binaryTree->insert(30);
    binaryTree->insert(5);
    binaryTree->insert(4);
    binaryTree->insert(7);
    binaryTree->insert(20);
    binaryTree->insert(40);
    
    binaryTree->insert(3);
//    binaryTree->insert(6);
    
    binaryTree->preorder();
    int normalNodeCount = binaryTree->treeNodeCountWithNodeType(BinaryTreeNormalNode);
    int leftNodeCount = binaryTree->treeNodeCountWithNodeType(BinaryTreeRightNode);
    int leafNodeCount = binaryTree->treeNodeCountWithNodeType(BinaryTreeLeafNode);
    
    
    cout << "count of normal node is : " << normalNodeCount << endl;
    cout << "count of right node is : " << leftNodeCount << endl;
    cout << "count of lead node is : " << leafNodeCount << endl;
    
    if (binaryTree->isBinarySearchTree()) {
        cout << "this is a binary search tree" << endl;
    } else {
        cout << "this is not a binary search tree" << endl;
    }
    
    binaryTree->createBinaryTreeMirror();
    binaryTree->preorder();
    
    if (binaryTree->isBinarySearchTree()) {
        cout << "this is a binary search tree" << endl;
    } else {
        cout << "this is not a binary search tree" << endl;
    }
    
    return 0;
}
