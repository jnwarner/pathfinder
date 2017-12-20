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
}

bool maze::generate() {

    bool generateSuccess{false};

    std::random_device rd;
    std::mt19937 mt(rd());

    std::uniform_int_distribution<> row(0, rows);
    std::uniform_int_distribution<> col(0, cols);

    std::cout << "Row " << row(mt) << " Col " << col(mt) << std::endl;

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