//
//  InitSLLNode.cpp
//  SingleLinkList
//
//  Created by mye on 2018/8/4.
//  Copyright © 2018 mye. All rights reserved.
//

#include "InitSLLNode.hpp"
#include <iostream>
using namespace std;

InitSLLNode::InitSLLNode() {
    this->info = 0;
    this->next = 0;
}

InitSLLNode::InitSLLNode(int el, InitSLLNode *ptr) {
    this->info = el;
    this->next = ptr;
}

InitSLLNode::~InitSLLNode() {
    cout << "dealloc InitSLLNode: " << this << endl;
}
