cmake_minimum_required(VERSION 3.27)
project(cattogradplusplus2)

set(CMAKE_CXX_STANDARD 17)

add_executable(cattogradplusplus2 main.cpp
        cattogradplusplus/atto.cpp
        cattogradplusplus/atto.h)
