//
//  DLLNode.cpp
//  DoublyLinkedList
//
//  Created by mye on 2018/8/4.
//  Copyright © 2018 mye. All rights reserved.
//

#include "DLLNode.hpp"
#include <iostream>
using namespace std;

template <typename T>
DLLNode<T>::DLLNode() {
    this->prev = this->next = 0;
}

template <typename T>
DLLNode<T>::DLLNode(const T &el, DLLNode<T> *p, DLLNode<T> *n) {
    this->info = el;
    this->prev = p;
    this->next = n;
}

template <typename T>
DLLNode<T>::~DLLNode<T>() {
    cout << "dealloc DLLNode " << this << endl;
}
