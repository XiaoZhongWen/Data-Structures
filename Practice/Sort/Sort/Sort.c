//
//  Sort.c
//  Sort
//
//  Created by 肖仲文 on 2019/3/2.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>

void merge_sort_c(int *arr, int p, int r);
void merge(int *arr, int p, int q, int r);
void quick_sort(int *arr, int left, int right);
void nthNumber(int *arr, int left, int right, int n, int *number);

/**
 归并排序
 
 @param arr 数组
 @param size 数组元素个数
 */
void mergeSort(int *arr, int size) {
    if (arr == NULL || size <= 0) {
        return;
    }
    merge_sort_c(arr, 0, size - 1);
}

/**
 归并算法

 @param arr 数组
 @param p 首元素序号
 @param r 尾元素序号
 */
void merge_sort_c(int arr[], int p, int r) {
    if (p >= r) {
        return;
    }
    int q = (p + r) / 2;
    merge_sort_c(arr, p, q);
    merge_sort_c(arr, q + 1, r);
    merge(arr, p, q + 1, r);
}

void merge(int arr[], int p, int q, int r) {
    if (arr == NULL ||
        p > q ||
        q > r) {
        return;
    }
    
    int index = 0;
    int start = p;
    int mid = q;
    int end = r;
    int size = r - p + 1;
    int *tmp = (int *)malloc(sizeof(int) * size);
    while (p < mid && q <= r) {
        if (arr[p] < arr[q]) {
            tmp[index] = arr[p];
            p++;
        } else {
            tmp[index] = arr[q];
            q++;
        }
        index++;
    }
    while (p < mid) {
        tmp[index] = arr[p];
        p++;
        index++;
    }
    while (q <= r) {
        tmp[index] = arr[q];
        q++;
        index++;
    }
    for (int i = start; i <= end; i++) {
        arr[i] = tmp[i - start];
    }
    free(tmp);
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 选择pivot并将pivot放到right位置
 
 @param arr 待排数组
 @param left 左边序号
 @param right 右边序号
 */
int median(int *arr, int left, int right) {
    int mid = (left + right) / 2;
    if (arr[left] > arr[mid]) {
        swap(&arr[left], &arr[mid]);
    }
    if (arr[left] > arr[right]) {
        swap(&arr[left], &arr[right]);
    }
    if (arr[mid] > arr[right]) {
        swap(&arr[mid], &arr[right]);
    }
    swap(&arr[mid], &arr[right]);
    return arr[right];
}

/**
 快速排序
 
 @param arr 数组
 @param size 数组元素个数
 */
void quickSort(int *arr, int size) {
    if (arr == NULL ||
        size <= 0) {
        return;
    }
    quick_sort(arr, 0, size - 1);
}

/**
 快速排序算法

 @param arr 数组
 @param left 起始元素序号
 @param right 尾部元素序号
 */
void quick_sort(int *arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = median(arr, left, right);
    int i = left;
    int j = right - 1;
    while (1) {
        while (i <= right &&
               arr[i] < pivot) {
            i++;
        }
        while (j >= left &&
               arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        } else {
            break;
        }
    }
    swap(&arr[i], &arr[right]);
    quick_sort(arr, left, i - 1);
    quick_sort(arr, i + 1, right);
}

/**
 获取第n大的数
 
 @param arr 数组
 @param size 数组元素个数
 @param n n
 @return 第n大的数
 */
int getNthNumber(int *arr, int size, int n) {
    if (size < 0 ||
        n > size) {
        exit(0);
    }
    int *tmp = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        tmp[i] = arr[i];
    }
    
    int left = 0;
    int right = size - 1;
    int number = 0;
    while (left <= right) {
        int pivot = median(tmp, left, right);
        int i = left;
        int j = right - 1;
        while (1) {
            while (i <= right &&
                   tmp[i] < pivot) {
                i++;
            }
            while (j >= left &&
                   tmp[j] > pivot) {
                j--;
            }
            if (i < j) {
                swap(&tmp[i], &tmp[j]);
            } else {
                break;
            }
        }
        swap(&tmp[i], &tmp[right]);
        if (i == n - 1) {
            number = tmp[i];
            break;
        }
        if (i > n - 1) {
            right = i - 1;
        }
        if (i < n - 1) {
            left = i + 1;
        }
    }
    free(tmp);
    return number;
}
