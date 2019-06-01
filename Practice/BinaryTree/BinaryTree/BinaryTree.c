//
//  BinaryTree.c
//  BinaryTree
//
//  Created by 肖仲文 on 2019/4/6.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include "BinaryTree.h"
#include "SequenceQueue.h"
#include <stdlib.h>
#include <stdio.h>

/**
 创建二叉树
 
 @param data 元素值
 @return root 根节点
 */
BinaryTreeNode* createBinaryTree(DataType data) {
    BinaryTreeNode *root = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    root->left = root->right = NULL;
    root->data = data;
    return root;
}

/**
 判断树是否为空
 
 @param root 根节点
 @return 1 树为空
 */
int isEmpty(BinaryTreeNode *root) {
    return root == NULL;
}

/**
 清除二叉树
 
 @param root 根节点
 */
void clearBinaryTre(BinaryTreeNode *root) {
    
}

/**
 插入元素
 
 @param root 根节点
 @param data 元素值
 */
void insertElement(BinaryTreeNode *root, DataType data) {
    if (isEmpty(root)) {
        BinaryTreeNode *node = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
        node->left = node->right = NULL;
        node->data = data;
        root = node;
        return;
    }
    BinaryTreeNode *p = root;
    BinaryTreeNode *preNode = root;
    while (p != NULL) {
        preNode = p;
        if (data < p->data) {
            p = p->left;
        } else {
            p = p->right;
        }
    }
    BinaryTreeNode *treeNode = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    treeNode->left = treeNode->right = NULL;
    treeNode->data = data;
    if (data < preNode->data) {
        preNode->left = treeNode;
    } else {
        preNode->right = treeNode;
    }
}

/**
 中序遍历二叉树
 
 @param treeNode 二叉树节点
 */
void inOrder(BinaryTreeNode *treeNode) {
    if (treeNode == NULL) {
        return;
    }
    inOrder(treeNode->left);
    printf("%d\n", treeNode->data);
    inOrder(treeNode->right);
}

/**
 层序遍历二叉树
 
 @param treeNode 二叉树节点
 */
void tierOrder(BinaryTreeNode *treeNode) {
    if (treeNode == NULL) {
        return;
    }
    SqQueue *queue = initQueue();
    enqueue(queue, treeNode);
    while (!_isEmpty(queue)) {
        BinaryTreeNode *node = dequeue(queue);
        printf("%d\n", node->data);
        if (node->left) {
            enqueue(queue, node->left);
        }
        if (node->right) {
            enqueue(queue, node->right);
        }
    }
}
