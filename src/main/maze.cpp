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

    // Set all cells to walls
    for (int i{0}; i < rows; i++)
        for (int j{0}; j < cols; j++)
            mazeArray[i][j].isWall = true;

    std::cout << "Before generation:" << std::endl;
    log();

    generate();

    std::cout << "After generation:" << std::endl;
    log();
}

bool maze::generate() {
    bool generateSuccess{false};

    srand(time(NULL));

    // Generate first point from which to create maze
    int randRow = rand() % (this->rows - 1) + 1;
    int randCol = rand() % (this->cols - 1) + 1;

    mazeArray[randRow][randCol].isWall = false;

    // TODO: Generate maze using depth-first search

    return generateSuccess;
}

bool maze::clear() {
    // TODO: Clear maze, and set to default
    return false;
}

void maze::log() {
    for (int i{0}; i < rows; i++) {
        for (int j{0}; j < cols; j++)
            std::cout << (mazeArray[i][j].isWall ? "1  " : "0  ");
        std::cout << std::endl;
    }
}