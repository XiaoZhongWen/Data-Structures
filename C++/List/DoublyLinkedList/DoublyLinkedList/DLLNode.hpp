//
//  DLLNode.hpp
//  DoublyLinkedList
//
//  Created by mye on 2018/8/4.
//  Copyright © 2018 mye. All rights reserved.
//

#ifndef DLLNode_hpp
#define DLLNode_hpp

#include <stdio.h>

template <typename T>
class DLLNode {
public:
    DLLNode();
    DLLNode(const T &el, DLLNode *p = 0, DLLNode *n = 0);
    ~DLLNode();
    
    T info;
    DLLNode *prev;
    DLLNode *next;
};

#endif /* DLLNode_hpp */
