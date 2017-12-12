//
// Created by Joshua on 12/11/2017.
//

#include "maze.h"

maze::maze(const int height, const int width) {
    rows = height;
    cols = width;

    // Allocate rows of maze
    mazeArray = new cell *[rows];

    // Allocate columns of maze
    for (int i{0}; i < rows; i++)
        mazeArray[i] = new cell [cols];

    // Set walls of maze
    for (int i{0}; i < rows; i++)
        for (int j{0}; j < cols; j++)
            if (i == 0 || (i == rows - 1) || j == 0 || (j = cols - 1))
                mazeArray[i][j].isWall = true;
}

bool maze::generate() {
    bool generateSuccess{false};
    // TODO: Generate maze using depth-first search
    return generateSuccess;
}

bool maze::clear() {
    // TODO: Clear maze, and set to default
    return false;
}

void maze::log() {
    // TODO: implement maze output structure, consider ASCII options
}