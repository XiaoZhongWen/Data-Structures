//
//  Heap.h
//  Heap
//
//  Created by 肖仲文 on 2019/4/6.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#ifndef Heap_h
#define Heap_h

#include <stdio.h>

/**
 创建一个堆

 @param arr 数组
 */
void createHeap(int *arr);

/**
 向堆中添加一个元素
 
 @param heap 堆
 @param value 元素
 @return heap 堆
 */
int* addElement(int *heap, int value);

/**
 删除堆中的一个元素

 @param heap 堆
 */
int removeElement(int *heap);

/**
 堆排序

 @param arr 数组
 */
void heapSort(int *arr);

/**
 打印

 @param arr 数组
 */
void print(int *arr);

#endif /* Heap_h */
