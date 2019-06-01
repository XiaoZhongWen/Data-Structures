//
//  main.c
//  BinaryTree
//
//  Created by 肖仲文 on 2019/4/6.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include <stdio.h>
#include "BinaryTree.h"

int main(int argc, const char * argv[]) {
    
    BinaryTreeNode *root = createBinaryTree(6);
    
    insertElement(root, 4);
    insertElement(root, 9);
    insertElement(root, 2);
    insertElement(root, 5);
    insertElement(root, 8);
    insertElement(root, 12);
    
//    inOrder(root);
    tierOrder(root);
    
    return 0;
}
