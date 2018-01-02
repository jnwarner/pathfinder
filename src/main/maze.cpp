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
    // C++11 random generation
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> rowGen(1, rows - 1);

    // Generate random row
    int randRow = rowGen(mt);

    // Generate until row is not even
    while (randRow % 2 == 0) {
        randRow = rowGen(mt);
    }

    // Set first point to path
    mazeArray[randRow][1].isWall = false;

    rowStart = randRow;
    colStart = 1;

    // Begin DFS generation of maze
    recursion(rowStart, colStart);

    // Set initial values for finish point determination
    rowFinal = NULL;
    colFinal = cols - 2;

    // Get maze end by checking for dead ends
    for (colFinal; colFinal > 1; colFinal--) {
        for (int i = 1; i < rows - 1; i++) {
            // Check for dead end facing down
            if (mazeArray[i][colFinal - 1].isWall &&
                       mazeArray[i - 1][colFinal].isWall &&
                       mazeArray[i][colFinal + 1].isWall &&
                       !mazeArray[i][colFinal].isWall) {
                rowFinal = i;
                break;
            }
            // Check for dead end facing left
            else if (mazeArray[i - 1][colFinal].isWall &&
                       mazeArray[i][colFinal + 1].isWall &&
                       mazeArray[i + 1][colFinal].isWall &&
                       !mazeArray[i][colFinal].isWall) {
                rowFinal = i;
                break;
            }
            // Check for dead end facing up
            else if (mazeArray[i][colFinal - 1].isWall &&
                       mazeArray[i + 1][colFinal].isWall &&
                       mazeArray[i][colFinal + 1].isWall &&
                       !mazeArray[i][colFinal].isWall) {
                rowFinal = i;
                break;
            }
            // Check for dead end facing right
            else if (mazeArray[i][colFinal - 1].isWall &&
                       mazeArray[i + 1][colFinal].isWall &&
                       mazeArray[i - 1][colFinal].isWall &&
                       !mazeArray[i][colFinal].isWall) {
                rowFinal = i;
                break;
            }
        }
        // Break if rowFinal has been set to an end value
        if (rowFinal) break;
    }

    return;
}

void maze::recursion(const int row, const int col) {
    // Initialize direction vector
    std::vector<int> dirVector;

    // Add directions to vector
    for (int dir = UP; dir <= LEFT; dir++) dirVector.push_back(dir);

    // C++11 random generation
    std::random_device r;
    std::seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
    std::mt19937 eng(seed);

    // Shuffle vector using seed
    std::shuffle(dirVector.begin(), dirVector.end(), eng);

    // Recursively generate maze
    for (auto dir : dirVector) {
        switch (dir) {
            case UP:
                if (row - 2 <= 0)
                    // Check for new direction from dirVector
                    continue;
                if (mazeArray[row - 2][col].isWall) {
                    // Set next two cells to paths
                    mazeArray[row - 1][col].isWall = false;
                    mazeArray[row - 2][col].isWall = false;
                    // Make recursive call with new cell location
                    recursion(row - 2, col);
                }
                break;
            case RIGHT:
                if (col + 2 >= cols - 1)
                    // Check for new direction from dirVector
                    continue;
                if (mazeArray[row][col + 2].isWall) {
                    // Set next two cells to paths
                    mazeArray[row][col + 1].isWall = false;
                    mazeArray[row][col + 2].isWall = false;
                    // Make recursive call with new cell location
                    recursion(row, col + 2);
                }
                break;
            case DOWN:
                if (row + 2 >= rows - 1)
                    // Check for new direction from dirVector
                    continue;
                if (mazeArray[row + 2][col].isWall) {
                    // Set next two cells to paths
                    mazeArray[row + 1][col].isWall = false;
                    mazeArray[row + 2][col].isWall = false;
                    // Make recursive call with new cell location
                    recursion(row + 2, col);
                }
                break;
            case LEFT:
                if (col - 2 <= 0)
                    // Check for new direction from dirVector
                    continue;
                if (mazeArray[row][col - 2].isWall) {
                    // Set next two cells to paths
                    mazeArray[row][col - 1].isWall = false;
                    mazeArray[row][col - 2].isWall = false;
                    // Make recursive call with new cell location
                    recursion(row, col - 2);
                }
                break;
        }
    }
}

void maze::clear() {
    // Set all cells to walls
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            mazeArray[i][j].isWall = true;

    // Set start and finish variables to NULL
    rowStart = NULL;
    colStart = NULL;
    rowFinal = NULL;
    colFinal = NULL;

    return;
}

void maze::log() {
    for (int i{0}; i < rows; i++) {
        for (int j{0}; j < cols; j++) {
            // Check if cell is start or finish
            if ((i == rowStart && j == colStart) ||
                (i == rowFinal && j == colFinal)) {
                // Output start
                if (i == rowStart && j == colStart) std:: cout << "S ";
                // Output finish
                else std::cout << "F ";
            }
            // Output wall or path
            else std::cout << (mazeArray[i][j].isWall ? "1 " : "  ");
        }
        std::cout << std::endl;
    }
}