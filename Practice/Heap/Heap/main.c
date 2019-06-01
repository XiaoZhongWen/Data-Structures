//
//  main.c
//  Heap
//
//  Created by 肖仲文 on 2019/4/6.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include <stdio.h>
#include "Heap.h"
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
//    int arr[] = {9, 7, 5, 19, 8, 4, 1, 20, 13, 16};
    int *array = (int *)malloc(sizeof(int) * 10);
    array[0] = 9;
    array[1] = 7;
    array[2] = 5;
    array[3] = 19;
    array[4] = 8;
    array[5] = 4;
    array[6] = 1;
    array[7] = 20;
    array[8] = 13;
    array[9] = 16;
    
//    array[0] = 9;
//    array[1] = 4;
//    array[2] = 16;
//    array[3] = 19;
//    array[4] = 13;
//    array[5] = 6;
//    array[6] = 1;
//    array[7] = 7;
//    array[8] = 5;
//    array[9] = 8;

    
    heapSort(array);
    for (int i = 1; i <= 9; i++) {
        printf("%d\n", array[i]);
    }
    
    createHeap(array);
    addElement(array, 6);
    removeElement(array);
    
    return 0;
}
