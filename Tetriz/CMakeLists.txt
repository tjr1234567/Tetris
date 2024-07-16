cmake_minimum_required (VERSION 3.16)
project(Tetriz)

set(CXX_STANDARD 20)

aux_source_directory(. source)
add_executable(tetris ${source})