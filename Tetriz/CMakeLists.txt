cmake_minimum_required (VERSION 3.16)
project(Tetriz)

set(CXX_STANDARD 20)
 

set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -std=c++14 -pthread")
aux_source_directory(. source)
add_executable(tetris ${source})