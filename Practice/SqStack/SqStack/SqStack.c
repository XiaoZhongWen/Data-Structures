//
//  SqStack.c
//  SqStack
//
//  Created by 肖仲文 on 2019/2/24.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include "SqStack.h"
#include "stdlib.h"

/**
 初始化顺序栈
 
 @param sqStack 指向顺序栈的指针
 */
void initStack(SqStack *sqStack) {
    DataType *base = (DataType *)malloc(sizeof(DataType) * kMaxStackSize);
    if (!base) {
        exit(0);
    }
    sqStack->base = base;
    sqStack->top = sqStack->base;
    sqStack->stackSize = kMaxStackSize;
}

/**
 销毁顺序栈
 
 @param sqStack 指向顺序栈的指针
 */
void destroyStack(SqStack *sqStack) {
    if (sqStack) {
        sqStack->stackSize = 0;
        sqStack->top = sqStack->base;
        free(sqStack->base);
        sqStack = NULL;
    }
}

/**
 清空栈
 
 @param sqStack 指向顺序栈的指针
 */
void clearStack(SqStack *sqStack) {
    if (sqStack) {
        sqStack->stackSize = 0;
        sqStack->top = sqStack->base;
    }
}

/**
 检测栈是否为空
 
 @param sqStack 指向顺序栈的指针
 @return 栈空返回1,否则返回0
 */
int isEmpty(SqStack *sqStack) {
    return sqStack->base == sqStack->top;
}

/**
 返回栈中元素的个数
 
 @param sqStack 指向顺序栈的指针
 @return 元素的个数
 */
long stackLength(SqStack *sqStack) {
    return sqStack->top - sqStack->base;
}

/**
 获取栈顶元素
 
 @param sqStack 指向顺序栈的指针
 @return 栈顶元素
 */
DataType getTop(SqStack *sqStack) {
    if (isEmpty(sqStack)) {
        return 0;
    } else {
        return *(sqStack->top - 1);
    }
}

/**
 将元素e压入栈中
 
 @param sqStack 指向顺序栈的指针
 @param e <#e description#>
 */
void push(SqStack *sqStack, DataType e) {
    long length = stackLength(sqStack);
    if (length >= sqStack->stackSize) {
        sqStack->base = (DataType *)realloc(sqStack->base, (kMaxStackSize + kStackIncrement) * sizeof(DataType));
        if (!sqStack->base) {
            exit(0);
        }
        sqStack->top = sqStack->base + sqStack->stackSize;
        sqStack->stackSize += kStackIncrement;
    }
    *(sqStack->top) = e;
    sqStack->top++;
}

/**
 出栈
 
 @param sqStack 指向顺序栈的指针
 @param e <#e description#>
 */
void pop(SqStack *sqStack, DataType *e) {
    if (isEmpty(sqStack)) {
        exit(0);
    }
    *e = *(--sqStack->top);
}
