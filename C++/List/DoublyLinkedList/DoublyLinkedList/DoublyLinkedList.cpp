//
//  DoublyLinkedList.cpp
//  DoublyLinkedList
//
//  Created by mye on 2018/8/4.
//  Copyright © 2018 mye. All rights reserved.
//

#include "DoublyLinkedList.hpp"
#include <iostream>
using namespace std;

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    this->head = this->tail = 0;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList<T>() {
    while (this->head) {
        DLLNode<T> *tmp = this->head;
        this->head = this->head->next;
        delete tmp;
        tmp = 0;
    }
    cout << "dealloc DoublyLinkedList " << this << endl;
}

template <typename T>
void DoublyLinkedList<T>::addToDLLTail(const T &t) {
    DLLNode<T> *newNode = new DLLNode<T>(t);
    if (this->head == 0) {
        newNode->prev = newNode->next = 0;
        this->head = this->tail = newNode;
    } else {
        newNode->prev = this->tail;
        this->tail->next = newNode;
        this->tail = newNode;
    }
}

template <typename T>
T DoublyLinkedList<T>::deleteToDLLTail() {
    assert(this->head != 0);
    T el = this->tail->info;
    if (this->head == this->tail) {
        delete this->head;
        this->head = this->tail = 0;
    } else {
        DLLNode<T> *preNode = this->tail->prev;
        preNode->next = 0;
        delete this->tail;
        this->tail = preNode;
    }
    return el;
}

template <typename T>
void DoublyLinkedList<T>::traverse() {
    DLLNode<T> *tmp = this->head;
    while (tmp) {
        cout << tmp->info << endl;
        tmp = tmp->next;
    }
}
