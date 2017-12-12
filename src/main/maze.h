//
// Created by Joshua on 12/11/2017.
//

#ifndef PATHFINDER_MAZE_H
#define PATHFINDER_MAZE_H

struct cell {
    bool isWall;
    bool visited;
};

class maze {
private:
    cell **mazeArray;
    int rows;
    int cols;
public:
    maze(const int height = 10, const int width = 10);
};


#endif //PATHFINDER_MAZE_H
