#include <iostream>
#include <thread>
#include "maze.h"

int main() {
    int testCounter = 1;

    maze testMaze(35, 35);

    while (testCounter <= 15) {
        testMaze.generate();

        std::cout << "Logging maze " << testCounter << std::endl;
        testCounter++;
        testMaze.log();
        testMaze.clear();
        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return EXIT_SUCCESS;
}