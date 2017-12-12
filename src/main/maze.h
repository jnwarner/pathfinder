//
// Created by Joshua on 12/11/2017.
//

#ifndef PATHFINDER_MAZE_H
#define PATHFINDER_MAZE_H

#include <cstdlib>
#include <iostream>
#include <time.h>

enum directions{up = 1, right = 2, down = 3, left = 4};

struct cell {
    bool isWall;
    bool visited;
    // TODO: Consider other needs for cell
};

class maze {
private:
    cell **mazeArray;
    int rows;
    int cols;
public:
    maze(const int height = 10, const int width = 10);
    bool generate();
    bool clear();
    void log();
    // TODO: Consider other needs for maze
};


#endif //PATHFINDER_MAZE_H
