//
//  Maze.hpp
//  Maze
//
//  Created by mye on 2018/9/8.
//  Copyright © 2018 mye. All rights reserved.
//

#ifndef Maze_hpp
#define Maze_hpp
#include "Cell.hpp"
#include "Stack.cpp"
#include <iostream>

class Maze {
public:
    Maze();
    Maze(char **store);
    void exitMaze();
private:
    Cell currentCell, entryCell, exitCell;
    const char exitMarker, entryMarker, visited, passage, wall;
    Stack<Cell> mazeStack;
    char **store;
    friend ostream& operator<<(ostream&, const Maze&);
    long rows, cols;
    void pushUnvisited(long row, long col);
};

#endif /* Maze_hpp */
