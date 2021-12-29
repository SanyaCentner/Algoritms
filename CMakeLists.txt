cmake_minimum_required(VERSION 3.20)
project(Algoritms)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(Algoritms src/main.cpp src/utils.cpp src/ListGraph.cpp src/MatrixGraph.cpp src/SetGraph.cpp src/ArcGraph.cpp)
