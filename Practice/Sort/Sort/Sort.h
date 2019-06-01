//
//  Sort.h
//  Sort
//
//  Created by 肖仲文 on 2019/3/2.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#ifndef Sort_h
#define Sort_h

#include <stdio.h>

/**
 归并排序

 @param arr 数组
 @param size 数组元素个数
 */
void mergeSort(int *arr, int size);

/**
 快速排序

 @param arr 数组
 @param size 数组元素个数
 */
void quickSort(int *arr, int size);

/**
 获取第n大的数

 @param arr 数组
 @param size 数组元素个数
 @param n n
 @return 第n大的数
 */
int getNthNumber(int *arr, int size, int n);

#endif /* Sort_h */
