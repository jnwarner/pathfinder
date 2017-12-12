cmake_minimum_required(VERSION 3.9)
project(pathfinder)

set(CMAKE_CXX_STANDARD 11)

add_executable(pathfinder src/main/main.cpp src/main/maze.cpp src/main/maze.h)