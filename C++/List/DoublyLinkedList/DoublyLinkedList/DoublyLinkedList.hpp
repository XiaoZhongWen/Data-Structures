//
//  DoublyLinkedList.hpp
//  DoublyLinkedList
//
//  Created by mye on 2018/8/4.
//  Copyright © 2018 mye. All rights reserved.
//

#ifndef DoublyLinkedList_hpp
#define DoublyLinkedList_hpp

#include <stdio.h>
#include "DLLNode.cpp"

template <typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    
    void addToDLLTail(const T& t);
    T deleteToDLLTail();
    
    void traverse();
    
protected:
    DLLNode<T> *head;
    DLLNode<T> *tail;
};


#endif /* DoublyLinkedList_hpp */
