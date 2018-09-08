//
//  Cell.hpp
//  Maze
//
//  Created by mye on 2018/9/8.
//  Copyright © 2018 mye. All rights reserved.
//

#ifndef Cell_hpp
#define Cell_hpp

class Cell {
private:
    long x, y;
    friend class Maze;
public:
    Cell(long x, long y);
    bool operator==(const Cell &c) const;
};

#endif /* Cell_hpp */
