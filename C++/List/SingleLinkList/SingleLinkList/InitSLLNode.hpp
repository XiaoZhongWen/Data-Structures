//
//  InitSLLNode.hpp
//  SingleLinkList
//
//  Created by mye on 2018/8/4.
//  Copyright © 2018 mye. All rights reserved.
//

#ifndef InitSLLNode_hpp
#define InitSLLNode_hpp

#include <stdio.h>

class InitSLLNode {
public:
    InitSLLNode();
    InitSLLNode(int el, InitSLLNode *ptr = 0);
    ~InitSLLNode();
    
    int info;
    InitSLLNode *next;
};

#endif /* InitSLLNode_hpp */
