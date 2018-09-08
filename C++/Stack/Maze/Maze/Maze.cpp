//
//  Maze.cpp
//  Maze
//
//  Created by mye on 2018/9/8.
//  Copyright © 2018 mye. All rights reserved.
//

#include "Maze.hpp"

Maze::Maze() : exitMarker('e'), entryMarker('m'), visited('.'), passage('0'), wall('1'), currentCell(0,0), exitCell(0,0), entryCell(0,0) {
    Stack<char*> mazeRows;
    char *s;
    long row = 0;
    cout << "Enter a rectangular maze using the following "
    << "characters:\nm - entry\ne - exit\n1 - wall\n0 - passage\n"
    << "Enter one line at a time; end with Ctrl-z:\n";
    
    char data[11][12] = {
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '\0'},
        {'1', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '\0'},
        {'e', '0', '1', '0', '0', '0', '1', '0', '1', '0', '1', '\0'},
        {'1', '0', '1', '0', '0', '0', '1', '0', '1', '0', '1', '\0'},
        {'1', '0', '1', '0', '0', '0', '0', '0', '1', '0', '1', '\0'},
        {'1', '0', '1', '1', '1', '1', '1', '0', '1', '0', '1', '\0'},
        {'1', '0', '1', '0', '1', '0', '0', '0', '1', '0', '1', '\0'},
        {'1', '0', '0', '0', '1', '0', '1', '0', '0', '0', '1', '\0'},
        {'1', '0', '1', 'm', '1', '0', '1', '0', '0', '0', '1', '\0'},
        {'1', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '\0'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '\0'},
    };
    
    for (int i = 0; i < 11; i++) {
        row++;
        s = new char(strlen(data[i]));
        strcpy(s, data[i]);
        mazeRows.push(s);
        if (strchr(s, exitMarker) != 0) {
            exitCell.x = i;
            exitCell.y = strchr(s, exitMarker) - s;
        }
        if (strchr(s, entryMarker) != 0) {
            entryCell.x = i;
            entryCell.y = strchr(s, entryMarker) - s;
        }
    }
    rows = row;
    store = new char*[rows];
    row--;
    for (; !mazeRows.empty(); row--) {
        store[row] = mazeRows.pop();
    }
//    char str[80];
//    while (cin >> str) {
//        row++;
//        cols = strlen(str);
//        s = new char[cols + 3];
//        mazeRows.push(s);
//        strcpy(s + 1, str);
//        s[0] = s[cols + 1] = wall;
//        s[cols + 2] = '\0';
//        if (strchr(str, exitMarker) != 0) {
//            exitCell.x = row;
//            exitCell.y = strchr(str, exitMarker) - s;
//        }
//        if (strchr(str, entryMarker) != 0) {
//            entryCell.x = row;
//            entryCell.y = strchr(str, entryMarker) - s;
//        }
//    }
//    rows = row;
//    store = new char*[rows + 2];
//    store[0] = new char[cols + 3];
//    for (; !mazeRows.empty(); row--) {
//        store[row] = mazeRows.pop();
//    }
//    store[rows + 1] = new char[cols + 3];
//    store[0][cols + 2] = store[rows + 1][cols + 2] = '\0';
//    for (int col = 0; col <= cols + 1; col++) {
//        store[0][col] = wall;
//        store[rows + 1][col] = wall;
//    }
}

Maze::Maze(char **store) : exitMarker('e'), entryMarker('m'), visited('.'), passage('0'), wall('1'), currentCell(0,0), exitCell(0,0), entryCell(0,0) {
    this->store = store;
}

void Maze::pushUnvisited(long row, long col) {
    if (store[row][col] == passage || store[row][col] == exitMarker) {
        mazeStack.push(Cell(row, col));
    }
}

void Maze::exitMaze() {
    long row, col;
    currentCell = entryCell;
    cout << *this;
    cout << "entry: " << "(" << entryCell.x << ", " << entryCell.y << ")" << endl;
    cout << "exit: " << "(" << exitCell.x << ", " << exitCell.y << ")" << endl;
    cout << "search..." << endl;
    while (!(currentCell == exitCell)) {
        row = currentCell.x;
        col = currentCell.y;
        cout << "(" << row << ", " << col << ")" << " -> ";
        if (!(currentCell == entryCell)) {
            store[row][col] = visited;
        }
        pushUnvisited(row - 1, col);
        pushUnvisited(row + 1, col);
        pushUnvisited(row, col - 1);
        pushUnvisited(row, col + 1);
        if (mazeStack.empty()) {
//            cout << *this;
            cout << "Failure" << endl;
            return;
        } else {
            currentCell = mazeStack.pop();
        }
    }
//    cout << *this;
    cout << "(" << exitCell.x << ", " << exitCell.y << ")" << endl;
    cout << "Success" << endl;
}

ostream& operator<<(ostream &out, const Maze &maze) {
    for (int row = 0; row < maze.rows; row++) {
        out << maze.store[row] << endl;
    }
    out << endl;
    return out;
}


