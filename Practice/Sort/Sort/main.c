//
//  main.c
//  Sort
//
//  Created by 肖仲文 on 2019/2/24.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include <stdio.h>
#include "Sort.h"

int main(int argc, const char * argv[]) {
    
    int arr[10] = {10, 5, 9, 8, 87, 4, 76, 13, 7, 24};
//    mergeSort(arr, 10);
//    quickSort(arr, 10);
    int number = getNthNumber(arr, 10, 10);
    printf("%d\n", number);
    
    return 0;
}
