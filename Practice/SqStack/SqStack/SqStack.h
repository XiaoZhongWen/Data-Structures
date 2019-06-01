//
//  SqStack.h
//  SqStack
//
//  Created by 肖仲文 on 2019/2/24.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#ifndef SqStack_h
#define SqStack_h

#include <stdio.h>

#define kMaxStackSize   50
#define kStackIncrement   50

typedef int DataType;

typedef struct {
    DataType *base;
    DataType *top;
    int stackSize; // 当前分配给栈的存储空间
}SqStack;

/**
 初始化顺序栈

 @param sqStack 指向顺序栈的指针
 */
void initStack(SqStack *sqStack);

/**
 销毁顺序栈
 
 @param sqStack 指向顺序栈的指针
 */
void destroyStack(SqStack *sqStack);

/**
 清空栈

 @param sqStack 指向顺序栈的指针
 */
void clearStack(SqStack *sqStack);

/**
 检测栈是否为空

 @param sqStack 指向顺序栈的指针
 @return 栈空返回1,否则返回0
 */
int isEmpty(SqStack *sqStack);

/**
 返回栈中元素的个数

 @param sqStack 指向顺序栈的指针
 @return 元素的个数
 */
long stackLength(SqStack *sqStack);

/**
 获取栈顶元素

 @param sqStack 指向顺序栈的指针
 @return 栈顶元素
 */
DataType getTop(SqStack *sqStack);

/**
 将元素e压入栈中

 @param sqStack 指向顺序栈的指针
 @param e <#e description#>
 */
void push(SqStack *sqStack, DataType e);

/**
 出栈
 
 @param sqStack 指向顺序栈的指针
 @param e <#e description#>
 */
void pop(SqStack *sqStack, DataType *e);

#endif /* SqStack_h */
