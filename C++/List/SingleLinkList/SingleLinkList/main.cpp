//
//  main.cpp
//  SingleLinkList
//
//  Created by mye on 2018/8/4.
//  Copyright © 2018 mye. All rights reserved.
//

#include <iostream>
#include "InitSLList.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    
    InitSLList *list = new InitSLList();
    list->addToTail(1);
    list->addToTail(2);
    list->addToTail(3);
    list->addToTail(4);
    list->addToTail(5);
    list->addToTail(6);
    
    cout << list->isInList(5) << endl;
    cout << list->isInList(7) << endl;
    
    list->deleteFromHead();
    list->deleteFromTail();
    
    list->addToHead(1);
    list->addToTail(6);
    
    list->deleteNode(4);
    list->deleteNode(1);
    list->deleteNode(6);
    
    list->deleteFromHead();
    list->deleteFromTail();
    
    list->deleteNode(3);
    cout << list->isEmpty() << endl;
    
    list->traverse();
    
    delete list;
    
    return 0;
}
