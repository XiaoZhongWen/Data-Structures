//
//  main.cpp
//  Queen
//
//  Created by mye on 2018/9/9.
//  Copyright © 2018 mye. All rights reserved.
//

#include <iostream>
#include "ChessBoard.hpp"

int main(int argc, const char * argv[]) {
    
    ChessBoard *chessBoard = new ChessBoard(12);
    chessBoard->findSolutions();
    chessBoard->printAllSolutions();
    
    return 0;
}
