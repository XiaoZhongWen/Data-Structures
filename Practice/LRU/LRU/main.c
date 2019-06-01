//
//  main.c
//  LRU
//
//  Created by 肖仲文 on 2019/2/23.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include <stdio.h>
#include "stdlib.h"
#include "LinkList.h"

int main(int argc, const char * argv[]) {
    
    // 1. 初始化链表
    LinkList linkList = NULL;
    init(&linkList);
    if (linkList == NULL) {
        printf("LinkList init failure.");
        return 0;
    }
    
    int arr[] = {6, 7, 9, 7, 10, 55, 23, 98, 7, 11, 12, 23, 55};
    for (int i = 0; i < 13; i++) {
        int e = arr[i];
        addCache(linkList, e);
    }
    
    printAll(linkList);
    
    LinkNode *node = findMiddleNode(linkList);
    printf("middle: %d\n", node->e);
    
    
    return 0;
}
