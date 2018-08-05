//
//  InitSLList.hpp
//  SingleLinkList
//
//  Created by mye on 2018/8/4.
//  Copyright © 2018 mye. All rights reserved.
//

#ifndef InitSLList_hpp
#define InitSLList_hpp

#include <stdio.h>
#include "InitSLLNode.hpp"

class InitSLList {
public:
    InitSLList();
    ~InitSLList();
    
    bool isEmpty();
    int count();
    void addToHead(int el);
    void addToTail(int el);
    int deleteFromHead();
    int deleteFromTail();
    int deleteNodeAt(int index);
    void deleteNode(int el);
    bool isInList(int el) const;
    bool isEqual(InitSLList *list);
    void traverse() const;
    void reverse();
    
private:
    InitSLLNode *header;
    InitSLLNode *tail;
};

#endif /* InitSLList_hpp */
