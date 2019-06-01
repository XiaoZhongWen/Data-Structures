//
//  SequenceQueue.h
//  BinaryTree
//
//  Created by 肖仲文 on 2019/4/6.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#ifndef SequenceQueue_h
#define SequenceQueue_h

#include <stdio.h>
#include "BinaryTree.h"

#define kQueueSize 10

typedef struct QueueNode {
    int front;
    int rear;
    BinaryTreeNode **treeNodes;
} SqQueue;

/**
 初始化队列

 @return 队列
 */
SqQueue* initQueue();

/**
 队列是否满

 @param queue 队列
 @return 1 满
 */
int isFull(SqQueue *queue);

/**
 队列是否空
 
 @param queue 队列
 @return 1 空
 */
int _isEmpty(SqQueue *queue);

/**
 入队

 @param queue 队列
 @param treeNode 树节点
 */
void enqueue(SqQueue *queue, BinaryTreeNode *treeNode);

/**
 出队
 
 @param queue 队列
 @return treeNode 树节点
 */
BinaryTreeNode* dequeue(SqQueue *queue);

#endif /* SequenceQueue_h */
