//
//  Cell.cpp
//  Maze
//
//  Created by mye on 2018/9/8.
//  Copyright © 2018 mye. All rights reserved.
//

#include "Cell.hpp"

Cell::Cell(long x, long y) {
    this->x = x;
    this->y = y;
}

bool Cell::operator==(const Cell &c)const {
    return this->x == c.x && this->y == c.y;
}
