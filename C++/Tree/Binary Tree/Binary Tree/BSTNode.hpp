//
//  BSTNode.hpp
//  Binary Tree
//
//  Created by mye on 2018/9/15.
//  Copyright © 2018 mye. All rights reserved.
//

#ifndef BSTNode_hpp
#define BSTNode_hpp

#include <stdio.h>

using namespace std;

template <class T>
class BSTNode {
public:
    BSTNode();
    BSTNode(const T &el);
    
    BSTNode<T> *left;
    BSTNode<T> *right;
    T el;
};

template <class T>
BSTNode<T>::BSTNode() {
    this->left = this->right = 0;
}

template <class T>
BSTNode<T>::BSTNode(const T &el) {
    this->left = this->right = 0;
    this->el = el;
}

#endif /* BSTNode_hpp */
