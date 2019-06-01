//
//  main.c
//  BinarySearch
//
//  Created by 肖仲文 on 2019/3/2.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include <stdio.h>
#include "BinarySearch.h"

int main(int argc, const char * argv[]) {
    
    // 1. 求平方根
//    double accuary = 0.000001;
//    printf("%.6f\n", square_root(2.0, accuary));
    
    // 2. 查找第一个等于给定值的元素
//    int arr[] = {1, 3, 4, 5, 6, 8, 8, 8, 11, 18};
//    int index = binarySearch(arr, 10, 8);
//    printf("index: %d\n", index);
    
    // 2. 查找最后一个等于给定值的元素
//    int arr[] = {9, 9, 9, 9, 9};
//    int index = binarySearch2(arr, 5, 8);
//    printf("index: %d\n", index);
    
    // 3. 查找第一个大于等于给定值的元素
//    int arr[] = {3, 4, 6, 7, 10};
//    int arr[] = {7, 7, 7, 7, 7};
//    int index = binarySearch3(arr, 5, 8);
//    printf("index: %d\n", index);
    
    // 4. 查找最后一个小于等于给定值的元素
//    int arr[] = {6, 7, 7, 7, 7, 7};
//    int index = binarySearch4(arr, 6, 6);
//    printf("index: %d\n", index);
    
    // 5. 查找给定元素在循环有序数组中的位置
    int arr[] = {10, 12, 14, 16, 16, 16, 18, 20, 21, 54, 78, 80, 999, 1234, 0, 1, 3, 5, 5, 5, 5, 6, 7, 8, 9, 10, 10, 10};
    for (int i = 0; i < 28; i++) {
        int index = binarySearch5(arr, 28, arr[i]);
        printf("<%d> %d->%d\n", i, arr[i], index);
    }
    return 0;
}
