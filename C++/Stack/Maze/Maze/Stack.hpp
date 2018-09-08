//
//  Stack.hpp
//  Maze
//
//  Created by mye on 2018/9/8.
//  Copyright © 2018 mye. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stack>

using namespace std;
template <class T>
class Stack : public stack<T> {
public:
    T pop();
};

#endif /* Stack_hpp */
