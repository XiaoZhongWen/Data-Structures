//
//  ChessBoard.hpp
//  Queen
//
//  Created by mye on 2018/9/9.
//  Copyright © 2018 mye. All rights reserved.
//

#ifndef ChessBoard_hpp
#define ChessBoard_hpp

#include <iostream>
#include <vector>

using namespace std;

class ChessBoard {
private:
    bool *column;            // 被占用的列
    bool *leftDiagonal;      // 被占用的左斜线
    bool *rightDiagonal;     // 被占用的右斜线
    int *positions;          // 满足条件的所有皇后的放置位置 (数组下标表示行序号, 数组元素表示列序号)
    int countOfSolutions;    // 总方案数
    vector<int*> solutions;  // 所有的放置方案集合
    const int squares;       // 规格
    const int offset;        // 右斜线数组下标偏移量
    const bool available;    // 可放置皇后标识
    
    void putQueen(int rowIndex);    // 将皇后放置在第row行上
    void initializeBoard();         // 初始化棋盘
    
public:
    ChessBoard();           // 8 * 8
    ChessBoard(int n);      // n * n
    
    void findSolutions();       // 寻找皇后的放置方案
    void printAllSolutions();   // 输出所有的解决方案
};

#endif /* ChessBoard_hpp */
