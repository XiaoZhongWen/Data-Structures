//
//  Stack.cpp
//  Maze
//
//  Created by mye on 2018/9/8.
//  Copyright © 2018 mye. All rights reserved.
//

#include "Stack.hpp"

template <class T>
T Stack<T>::pop() {
    T tmp = this->top();
    stack<T>::pop();
    return tmp;
}
