#include <iostream>
#include <cstdlib>
#include "maze.h"

int main() {
    maze testMaze(45, 45);

    testMaze.generate();

    std::cout << "Logging maze" << std::endl;
    testMaze.log();

    return EXIT_SUCCESS;
}