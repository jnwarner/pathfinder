#include <iostream>
#include <cstdlib>
#include "maze.h"

int main() {
    maze testMaze;

    for (int i{0}; i < 10; i++)
        testMaze.generate();

    return EXIT_SUCCESS;
}