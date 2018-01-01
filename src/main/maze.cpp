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

void maze::generate() {

    std::random_device rd;
    std::mt19937 mt(rd());

    std::uniform_int_distribution<> rowGen(1, rows - 1);


    int randRow = rowGen(mt);

    while (randRow % 2 == 0) {
        randRow = rowGen(mt);
    }

    mazeArray[randRow][1].isWall = false;

    rowStart = randRow;
    colStart = 1;

    recursion(rowStart, colStart);

    colFinal = cols - 2;

    for (int i = 1; i < rows; i++) {
        if (mazeArray[i][colFinal - 1].isWall && mazeArray[i - 1][colFinal].isWall) {
            rowFinal = i;
            break;
        } else if (mazeArray[i - 1][colFinal].isWall && mazeArray[i + 1][colFinal].isWall) {
            rowFinal = i;
            break;
        } else if (mazeArray[i][colFinal - 1].isWall && mazeArray[i + 1][colFinal].isWall) {
            rowFinal = i;
            break;
        } else continue;
    }

    return;
}

void maze::recursion(const int row, const int col) {

    std::vector<int> dirVector;

    // Add directions to vector
    for (int dir = UP; dir <= LEFT; dir++) dirVector.push_back(dir);

    std::random_device r;
    std::seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
    std::mt19937 eng(seed);

    // Shuffle vector
    std::shuffle(dirVector.begin(), dirVector.end(), eng);

    // Recursively generate maze
    for (auto& dir : dirVector) {
        switch (dir) {
            case UP:
                if (row - 2 <= 0)
                    continue;
                if (mazeArray[row - 2][col].isWall) {
                    mazeArray[row - 1][col].isWall = false;
                    mazeArray[row - 2][col].isWall = false;
                    recursion(row - 2, col);
                }
                break;
            case RIGHT:
                if (col + 2 >= cols - 1)
                    continue;
                if (mazeArray[row][col + 2].isWall) {
                    mazeArray[row][col + 1].isWall = false;
                    mazeArray[row][col + 2].isWall = false;
                    recursion(row, col + 2);
                }
                break;
            case DOWN:
                if (row + 2 >= rows - 1)
                    continue;
                if (mazeArray[row + 2][col].isWall) {
                    mazeArray[row + 1][col].isWall = false;
                    mazeArray[row + 2][col].isWall = false;
                    recursion(row + 2, col);
                }
                break;
            case LEFT:
                if (col - 2 <= 0)
                    continue;
                if (mazeArray[row][col - 2].isWall) {
                    mazeArray[row][col - 1].isWall = false;
                    mazeArray[row][col - 2].isWall = false;
                    recursion(row, col - 2);
                }
                break;
        }
    }
}

bool maze::clear() {
    // TODO: Clear maze, and set to default
    return false;
}

void maze::log() {
    for (int i{0}; i < rows; i++) {
        for (int j{0}; j < cols; j++) {
            if ((i == rowStart && j == colStart) || (i == rowFinal && j == colFinal)) {
                if (i == rowStart && j == colStart) std:: cout << "S ";
                else std::cout << "F ";
            } else std::cout << (mazeArray[i][j].isWall ? "1 " : "  ");
        }
        std::cout << std::endl;
    }
}