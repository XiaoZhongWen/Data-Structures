//
//  main.cpp
//  DoublyLinkedList
//
//  Created by mye on 2018/8/4.
//  Copyright © 2018 mye. All rights reserved.
//

#include <iostream>
#include "DoublyLinkedList.cpp"

int main(int argc, const char * argv[]) {
    DoublyLinkedList<int> *list = new DoublyLinkedList<int>();
    
    list->addToDLLTail(1);
    list->addToDLLTail(2);
    list->addToDLLTail(3);
    list->addToDLLTail(4);
    list->addToDLLTail(5);
    list->addToDLLTail(6);
    
    list->deleteToDLLTail();
    list->deleteToDLLTail();
    
    list->traverse();
    
    delete list;
    
    return 0;
}
