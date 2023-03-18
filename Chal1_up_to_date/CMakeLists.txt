cmake_minimum_required(VERSION 3.24)
project(chal1)

set(CMAKE_CXX_STANDARD 20)

add_executable(chal1 main.cpp Derivatives.hpp muparser_fun.hpp newton.hpp Compute_solution.cpp Compute_solution.h Derivative.h)
