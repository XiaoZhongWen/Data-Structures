//
//  BinarySearch.h
//  BinarySearch
//
//  Created by 肖仲文 on 2019/3/2.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#ifndef BinarySearch_h
#define BinarySearch_h

#include <stdio.h>

/**
 查找数组arr中第一个值等于value的元素

 @param arr 数组
 @param size 数组元素个数
 @param value 查找元素的值
 @return 查找成功返回元素的下标, 查找失败返回-1
 */
int binarySearch(int *arr, int size, int value);

/**
 查找数组arr中最后一个值等于value的元素
 
 @param arr 数组
 @param size 数组元素个数
 @param value 查找元素的值
 @return 查找成功返回元素的下标, 查找失败返回-1
 */
int binarySearch2(int *arr, int size, int value);

/**
 查找数组arr中第一个值大于等于value的元素
 
 @param arr 数组
 @param size 数组元素个数
 @param value 查找元素的值
 @return 查找成功返回元素的下标, 查找失败返回-1
 */
int binarySearch3(int *arr, int size, int value);

/**
 查找数组arr中最后一个值小于等于value的元素
 
 @param arr 数组
 @param size 数组元素个数
 @param value 查找元素的值
 @return 查找成功返回元素的下标, 查找失败返回-1
 */
int binarySearch4(int *arr, int size, int value);

/**
 查找数组cycleArr中第一个值等于value的元素
 
 @param cycleArr 循环数组
 @param size 数组元素个数
 @param value 查找元素的值
 @return 查找成功返回元素的下标, 查找失败返回-1
 */
int binarySearch5(int *cycleArr, int size, int value);

/**
 求平方根

 @param value 实数
 @param accuary 精确度
 @return 平方根
 */
double square_root(double value, double accuary);

#endif /* BinarySearch_h */
