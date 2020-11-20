cmake_minimum_required(VERSION 3.17)
project(biblioteca)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Weffc++")
add_executable(biblioteca main.cpp carte.cpp carte.h biblioteca.cpp biblioteca.h)