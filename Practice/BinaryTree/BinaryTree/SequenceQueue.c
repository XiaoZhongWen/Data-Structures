//
//  SequenceQueue.c
//  BinaryTree
//
//  Created by 肖仲文 on 2019/4/6.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include "SequenceQueue.h"
#include <stdlib.h>

/**
 初始化队列
 
 @return 队列
 */
SqQueue* initQueue() {
    SqQueue *queue = (SqQueue *)malloc(sizeof(SqQueue));
    queue->treeNodes = (BinaryTreeNode **)calloc(kQueueSize, sizeof(BinaryTreeNode *));
    queue->front = queue->rear = 0;
    return queue;
}

/**
 队列是否满
 
 @param queue 队列
 @return 1 满
 */
int isFull(SqQueue *queue) {
    return (queue->rear + 1) % kQueueSize == queue->front;
}

/**
 队列是否空
 
 @param queue 队列
 @return 1 空
 */
int _isEmpty(SqQueue *queue) {
    return queue->front == queue->rear;
}

/**
 入队
 
 @param queue 队列
 @param treeNode 树节点
 */
void enqueue(SqQueue *queue, BinaryTreeNode *treeNode) {
    if (queue == NULL || isFull(queue)) {
        return;
    }
    queue->treeNodes[queue->rear] = treeNode;
    queue->rear = (queue->rear + 1) % kQueueSize;
}

/**
 出队
 
 @param queue 队列
 @return treeNode 树节点
 */
BinaryTreeNode* dequeue(SqQueue *queue) {
    if (queue == NULL || _isEmpty(queue)) {
        return NULL;
    }
    BinaryTreeNode *treeNode = queue->treeNodes[queue->front];
    queue->front = (queue->front + 1) % kQueueSize;
    return treeNode;
}
