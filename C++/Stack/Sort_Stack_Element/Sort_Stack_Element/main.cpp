//
//  main.cpp
//  Sort_Stack_Element
//
//  Created by mye on 2018/9/8.
//  Copyright © 2018 mye. All rights reserved.
//

#include <iostream>
#include "stack"

using namespace std;

int main(int argc, const char * argv[]) {
    
    // 1. 定义一个栈stackA
    stack<int> stackA;
    for (int i = 0; i < 100; i++) {
        int rd = rand();
        stackA.push(rd);
    }
    
    // 2. 排序stackA中的元素
    // 2.1 定义辅助栈stackB及辅助变量
    stack<int> stackB;
    stackB.push(stackA.top());
    stackA.pop();
    
    int a = stackA.top();
    int b = INT_MIN;
    stackA.pop();
    
    while (!stackA.empty()) {
        if (stackA.top() < a) {
            stackB.push(a);
            a = stackA.top();
            stackA.pop();
        } else if (stackA.top() < stackB.top()) {
            stackB.push(stackA.top());
            stackA.pop();
        } else {
            b = stackA.top();
            stackA.pop();
            int countForPop = 0;
            while (!stackB.empty() && stackB.top() < b) {
                countForPop++;
                stackA.push(stackB.top());
                stackB.pop();
            }
            stackB.push(b);
            while (countForPop) {
                countForPop--;
                stackB.push(stackA.top());
                stackA.pop();
            }
        }
    }
    stackB.push(a);
    
    while (!stackB.empty()) {
        cout << stackB.top() << endl;
        stackA.push(stackB.top());
        stackB.pop();
    }
    
    return 0;
}
