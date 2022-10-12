cmake_minimum_required(VERSION 3.21)
project(Huffman)

set(CMAKE_CXX_STANDARD 17)

add_executable(Huffman main.cpp FUNC.cpp Huffman_Tree.h )
