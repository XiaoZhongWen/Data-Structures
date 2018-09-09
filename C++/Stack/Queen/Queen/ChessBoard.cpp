//
//  ChessBoard.cpp
//  Queen
//
//  Created by mye on 2018/9/9.
//  Copyright © 2018 mye. All rights reserved.
//

#include "ChessBoard.hpp"

ChessBoard::ChessBoard() : available(true), squares(8), offset(squares - 1) {
    initializeBoard();
}

ChessBoard::ChessBoard(int n) : available(true), squares(n), offset(squares - 1) {
    initializeBoard();
}

void ChessBoard::initializeBoard() {
    column = new bool[squares];
    leftDiagonal = new bool[2 * squares - 1];
    rightDiagonal = new bool[2 * squares - 1];
    positions = new int[squares];
    
    for (int i = 0; i < squares; i++) {
        column[i] = available;
    }
    
    int diagonalCount = 2 * squares - 1;
    for (int i = 0; i < diagonalCount; i++) {
        leftDiagonal[i] = rightDiagonal[i] = available;
    }
}

void ChessBoard::putQueen(int rowIndex) {
    for (int col = 0; col < squares; col++) {
        if (column[col] == available
            && leftDiagonal[rowIndex + col] == available
            && rightDiagonal[rowIndex - col + offset]) {
            positions[rowIndex] = col;
            column[col] = !available;
            leftDiagonal[rowIndex + col] = !available;
            rightDiagonal[rowIndex - col + offset] = !available;
            if (rowIndex < squares - 1) {
                putQueen(rowIndex + 1);
            } else {
                int *pos = new int[squares];
                for (int i = 0; i < squares; i++) {
                    pos[i] = positions[i];
                }
                solutions.push_back(pos);
            }
            column[col] = available;
            leftDiagonal[rowIndex + col] = available;
            rightDiagonal[rowIndex - col + offset] = available;
        }
    }
}

void ChessBoard::findSolutions() {
    putQueen(0);
}

void ChessBoard::printAllSolutions() {
    int index = 0;
    for (vector<int*>::iterator iter = solutions.begin(); iter < solutions.end(); iter++) {
        index++;
        cout << index << "th: ";
        for (int i = 0; i < squares; i++) {
            cout << "(" << i << " ," << (*iter)[i] << ") ";
        }
        cout << endl;
    }
}
