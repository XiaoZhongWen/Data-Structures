//
//  Heap.c
//  Heap
//
//  Created by 肖仲文 on 2019/4/6.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include "Heap.h"
#include <stdlib.h>

/**
 创建一个堆
 
 @param arr 数组
 */
void createHeap(int *arr) {
    if (arr == NULL) {
        return;
    }
    int size = arr[0];
    for (int i = size / 2; i >= 1; i--) {
        int key = i;
        while (2 * key <= size) {
            int leftNo = 2 * key;
            int rightNo = 2 * key + 1;
            
            if (leftNo <= size && rightNo > size) {
                if (arr[key] < arr[leftNo]) {
                    int tmp = arr[key];
                    arr[key] = arr[leftNo];
                    arr[leftNo] = tmp;
                    key = 2 * leftNo;
                } else {
                    break;
                }
            } else if (leftNo <= size && rightNo <= size) {
                if (arr[leftNo] < arr[rightNo]) {
                    if (arr[key] < arr[rightNo]) {
                        int tmp = arr[key];
                        arr[key] = arr[rightNo];
                        arr[rightNo] = tmp;
                        key = rightNo;
                    } else {
                        break;
                    }
                } else {
                    if (arr[key] < arr[leftNo]) {
                        int tmp = arr[key];
                        arr[key] = arr[leftNo];
                        arr[leftNo] = tmp;
                        key = leftNo;
                    } else {
                        break;
                    }
                }
            } else {
                break;
            }
        }
    }
}

/**
 向堆中添加一个元素
 
 @param heap 堆
 @param value 元素
 @return heap 堆
 */
int* addElement(int *heap, int value) {
    int size = heap[0] + 1;
    int *newHeap = (int *)realloc(heap, size + 1);
    if (newHeap == NULL) {
        return NULL;
    }
    newHeap[0] = size;
    newHeap[size] = value;
    int key = size;
    while (key >= 1) {
        int parent = key / 2;
        if (newHeap[key] > newHeap[parent]) {
            int tmp = newHeap[key];
            newHeap[key] = newHeap[parent];
            newHeap[parent] = tmp;
            key = key / 2;
        } else {
            break;
        }
    }
    return newHeap;
}

/**
 删除堆中的一个元素
 
 @param heap 堆
 */
int removeElement(int *heap) {
    int size = heap[0];
    if (heap == NULL || size <= 0) {
        return -1;
    }
    int tmp = heap[1];
    int value = heap[1];
    heap[1] = heap[size];
    heap[size] = tmp;
    heap[0] = size -  1;
    createHeap(heap);
    return value;
}

/**
 堆排序
 
 @param arr 数组
 */
void heapSort(int *arr) {
    createHeap(arr);
    while (arr[0] > 0) {
        removeElement(arr);
    }
}

/**
 打印
 
 @param arr 数组
 */
void print(int *arr) {
    int size = arr[0];
    for (int i = 1; i <= size; i++) {
        printf("%d\n", arr[i]);
    }
}
