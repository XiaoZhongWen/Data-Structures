//
//  SqQueue.c
//  SqQueue
//
//  Created by 肖仲文 on 2019/2/24.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include "SqQueue.h"
#include "stdlib.h"

/**
 初始化队列
 
 @param queue 队列
 */
void initQueue(SqQueue *queue) {
    queue->base = (DataType *)malloc(sizeof(DataType) * kMaxQueueSize);
    if (queue->base == NULL) {
        exit(0);
    }
    queue->front = queue->rear = 0;
}

/**
 获取队列长度
 
 @param queue 队列
 @return 队列长度
 */
int queueLength(SqQueue *queue) {
    return (queue->rear - queue->front + kMaxQueueSize) % kMaxQueueSize;
}

/**
 检测队列是否满
 
 @param queue 队列
 @return 队列满返回1, 否则返回0
 */
int isFull(SqQueue *queue) {
    return (queue->rear + 1) % kMaxQueueSize == queue->front;
}

/**
 检测队列是否空
 
 @param queue 队列
 @return 队列空返回1, 否则返回0
 */
int isEmpty(SqQueue *queue) {
    return queue->front == queue->rear;
}

/**
 入队操作
 
 @param queue 队列
 @param e 入队元素
 */
void enqueue(SqQueue *queue, DataType e) {
    if (isFull(queue)) {
        return;
    } else {
        queue->base[queue->rear] = e;
        queue->rear = (queue->rear + 1) % kMaxQueueSize;
    }
}

/**
 出队操作
 
 @param queue 队列
 @param e 出队元素
 */
void dequeue(SqQueue *queue, DataType *e) {
    if (isEmpty(queue)) {
        return;
    } else {
        *e = queue->base[queue->front];
        queue->front = (queue->front + 1) % kMaxQueueSize;
    }
}
