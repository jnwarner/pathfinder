#include <iostream>
#include <cstdlib>
#include "maze.h"

int main() {
    std::srand(std::time(0));

    maze testMaze(45, 45);

    testMaze.generate();

    std::cout << "Logging maze" << std::endl;
    testMaze.log();

    return EXIT_SUCCESS;
}