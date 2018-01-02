#include <iostream>
#include <thread>
#include "maze.h"

int main() {
    int testCounter = 1;

    maze testMaze(41, 41);

    // Simulation loop
    while (testCounter <= 15) {
        // Generate maze structure
        testMaze.generate();

        // Log maze
        std::cout << "Logging maze " << testCounter << std::endl;
        testMaze.log();
        // Clear for next generation
        testMaze.clear();
        testCounter++;
        std::cout << std::endl;
        // Sleep for output formatting
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    }

    return EXIT_SUCCESS;
}