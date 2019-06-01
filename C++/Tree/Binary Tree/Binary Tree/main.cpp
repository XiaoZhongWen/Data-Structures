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
    binaryTree->insert(25);
    binaryTree->insert(15);
    binaryTree->insert(40);
    binaryTree->insert(12);
    binaryTree->insert(20);
    binaryTree->insert(30);
    binaryTree->insert(45);
    binaryTree->insert(8);
    binaryTree->insert(16);
    binaryTree->insert(23);
    binaryTree->insert(35);
    binaryTree->insert(10);
    binaryTree->insert(22);
    binaryTree->insert(24);
    binaryTree->insert(9);
    
//    binaryTree->insert(50);
//    binaryTree->insert(55);
//    binaryTree->insert(60);
//    binaryTree->insert(65);
    
//    binaryTree->preorder();
    binaryTree->iterativePostorder();
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
    
    int height = binaryTree->heightOfBinaryTree_iterativeBreadth();
    cout << "<iterativeBreadth> the height of tree is " << height << endl;
    
    height = binaryTree->heightOfBinaryTree_iterativePostorder();
    cout << "<iterativePostorder> the height of tree is " << height << endl;
    
    height = binaryTree->heightOfBinaryTree_recursion();
    cout << "<recursion> the height of tree is " << height << endl;
    
//    binaryTree->createBinaryTreeMirror();
//    binaryTree->preorder();
//    
//    if (binaryTree->isBinarySearchTree()) {
//        cout << "this is a binary search tree" << endl;
//    } else {
//        cout << "this is not a binary search tree" << endl;
//    }
    
    return 0;
}
