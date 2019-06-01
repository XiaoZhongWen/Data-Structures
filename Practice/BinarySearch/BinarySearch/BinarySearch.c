//
//  BinarySearch.c
//  BinarySearch
//
//  Created by 肖仲文 on 2019/3/2.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include "BinarySearch.h"
#include "math.h"

/**
 查找数组arr中第一个值等于value的元素
 
 @param arr 数组
 @param size 数组元素个数
 @param value 查找元素的值
 @return 查找成功返回元素的下标, 查找失败返回-1
 */
int binarySearch(int *arr, int size, int value) {
    int low = 0;
    int high = size - 1;
    int index = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int e = arr[mid];
        if (e < value) {
            low = mid + 1;
        }
        if (e > value) {
            high = mid - 1;
        }
        if (e == value) {
            if (mid == 0) {
                index = mid;
                break;
            }
            if (mid > 0) {
                if (arr[mid - 1] < value) {
                    index = mid;
                    break;
                }
                if (arr[mid - 1] == value) {
                    high = mid - 1;
                }
            }
        }
    }
    return index;
}

/**
 查找数组arr中最后一个值等于value的元素
 
 @param arr 数组
 @param size 数组元素个数
 @param value 查找元素的值
 @return 查找成功返回元素的下标, 查找失败返回-1
 */
int binarySearch2(int *arr, int size, int value) {
    int low = 0;
    int high = size - 1;
    int index = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int e = arr[mid];
        if (e < value) {
            low = mid + 1;
        }
        if (e > value) {
            high = mid - 1;
        }
        if (e == value) {
            if (mid == size - 1) {
                index = mid;
                break;
            }
            if (mid >= 0 &&
                mid < size - 1) {
                if (arr[mid + 1] > value) {
                    index = mid;
                    break;
                }
                if (arr[mid + 1] == value) {
                    low = mid + 1;
                }
            }
        }
    }
    return index;
}

/**
 查找数组arr中第一个值大于value的元素
 
 @param arr 数组
 @param size 数组元素个数
 @param value 查找元素的值
 @return 查找成功返回元素的下标, 查找失败返回-1
 */
int binarySearch3(int *arr, int size, int value) {
    int low = 0;
    int high = size - 1;
    int index = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int e = arr[mid];
        if (e < value) {
            low = mid + 1;
        }
        if (e >= value) {
            if (mid > 0) {
                if (arr[mid - 1] < value) {
                    index = mid;
                    break;
                } else {
                    index = mid - 1;
                    high = mid - 1;
                }
            } else {
                index = mid;
                break;
            }
        }
    }
    return index;
}

/**
 查找数组arr中最后一个值小于等于value的元素
 
 @param arr 数组
 @param size 数组元素个数
 @param value 查找元素的值
 @return 查找成功返回元素的下标, 查找失败返回-1
 */
int binarySearch4(int *arr, int size, int value) {
    int low = 0;
    int high = size - 1;
    int index = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int e = arr[mid];
        if (e > value) {
            high = mid - 1;
        } else {
            if (arr[mid + 1] > value) {
                index = mid;
                break;
            } else {
                index = mid + 1;
                low = mid + 1;
            }
        }
    }
    return index;
}

/**
 查找数组cycleArr中第一个值等于value的元素
 
 @param cycleArr 循环数组
 @param size 数组元素个数
 @param value 查找元素的值
 @return 查找成功返回元素的下标, 查找失败返回-1
 */
int binarySearch5(int *cycleArr, int size, int value) {
    int low = 0;
    int high = size - 1;
    int index = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (cycleArr[mid] == value) {
            index = mid;
            break;
        }
        if (cycleArr[low] == value) {
            index = low;
            break;
        }
        if (cycleArr[low] < value) {
            // 前部分
            if (cycleArr[mid] > value) {
                high = mid - 1;
            } else {
                if (cycleArr[mid] >= cycleArr[low]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        } else {
            // 后部分
            if (cycleArr[mid] < value) {
                low = mid + 1;
            } else {
                if (cycleArr[mid] >= cycleArr[low]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
    }
    
    return index;
}

/**
 求平方根
 
 @param value 实数
 @param accuary 精确度
 @return 平方根
 */
double square_root(double value, double accuary) {
    long long low = 0;
    long long high = 0;
    if (value > 1.0) {
        high = value / accuary - 1;;
    }
    if (value > 0.0 &&
        value <= 1.0) {
        high = 1.0 / accuary -  1;
    }
    double mid = 0.0;
    double delta = 0.0;
    while (low < high) {
        long long center = (high + low) / 2;
        mid = center * accuary;
        delta = mid * mid - value;
        if (fabs(delta) < 2 * accuary) {
            break;
        } else {
            if (delta < 0) {
                low = center + 1;
            } else {
                high = center - 1;
            }
        }
    }
    return mid;
}
