//
//  SqQueue.h
//  SqQueue
//
//  Created by 肖仲文 on 2019/2/24.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#ifndef SqQueue_h
#define SqQueue_h

#include <stdio.h>

#define kMaxQueueSize   50

typedef int DataType;

typedef struct {
    DataType *base;
    int front;
    int rear;
}SqQueue;

/**
 初始化队列

 @param queue 队列
 */
void initQueue(SqQueue *queue);

/**
 获取队列长度

 @param queue 队列
 @return 队列长度
 */
int queueLength(SqQueue *queue);

/**
 检测队列是否满

 @param queue 队列
 @return 队列满返回1, 否则返回0
 */
int isFull(SqQueue *queue);

/**
 检测队列是否空
 
 @param queue 队列
 @return 队列空返回1, 否则返回0
 */
int isEmpty(SqQueue *queue);

/**
 入队操作

 @param queue 队列
 @param e 入队元素
 */
void enqueue(SqQueue *queue, DataType e);

/**
 出队操作

 @param queue 队列
 @param e 出队元素
 */
void dequeue(SqQueue *queue, DataType *e);

#endif /* SqQueue_h */
