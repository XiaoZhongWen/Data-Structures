//
//  main.c
//  KMP
//
//  Created by 肖仲文 on 2018/6/3.
//  Copyright © 2018 肖仲文. All rights reserved.
//

#include <stdio.h>

#define MAXSTRLEN 255
typedef unsigned char SString[MAXSTRLEN + 1]; // 0号单元存放串的长度

/**
 生成一个值为chars的串

 @param T 串
 @param chars 字符串常量
 */
void strAssign(SString T, const char *chars) {
    
    if (chars == NULL) {
        return;
    }
    
    int index = 0;
    while (*(chars + index) != '\0') {
        T[index + 1] = *(chars + index);
        index++;
    }
    T[0] = index;
}

/**
 求模式串T的next函数值并保存到数组next

 @param T 模式串
 @param next next值数组
 */
void get_next(SString T, int next[]) {
    int i = 1;
    int j = 0;
    next[i] = j;
    while (i < T[0]) {
        if (j == 0 || T[i] == T[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

/**
 KMP算法

 @param S 主串
 @param T 模式串
 @param next 模式串的next值数组
 @return 模式串与主串匹配时的位置, 不匹配返回0
 */
int index_kmp (SString S, SString T, int next[]) {
    int i = 1;
    int j = 1;
    while (i <= S[0] && j <= T[0]) {
        if (j == 0 || S[i] == T[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j > T[0]) {
        return i - T[0];
    } else {
        return 0;
    }
}

int main(int argc, const char * argv[]) {
    
    // 定义主串和模式串
    SString mainStr, patternStr;
    
    // 初始化主串和模式串
    strAssign(mainStr, "ababcabcacbab");
    strAssign(patternStr, "abcac");
    
    // next值
    int next[patternStr[0] + 1];
    get_next(patternStr, next);
    
    // kmp
    int pos = index_kmp(mainStr, patternStr, next);
    printf("pos = %d\n", pos);
    
    return 0;
}
