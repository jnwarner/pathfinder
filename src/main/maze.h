//
// Created by Joshua on 12/11/2017.
//

#ifndef PATHFINDER_MAZE_H
#define PATHFINDER_MAZE_H

#include <iostream>
#include <random>
#include <typeinfo>
#include <stack>

enum direction{UP = 1, RIGHT = 2, DOWN = 3, LEFT = 4};

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
    int rowStart;
    int colStart;
    int rowFinal;
    int colFinal;
public:
    maze(const int height = 10, const int width = 10);
    void generate();
    void recursion(const int row, const int col);
    void clear();
    void log();
    // TODO: Consider other needs for maze
};


#endif //PATHFINDER_MAZE_H
