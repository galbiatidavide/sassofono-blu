cmake_minimum_required(VERSION 3.23)
project(my_env)

set(CMAKE_CXX_STANDARD 20)

add_executable(my_env main.cpp Derivatives.hpp horner.cpp horner.hpp newton.hpp basicZeroFun.hpp extendedAssert.hpp functionConcepts.hpp crank_nicolson.cpp crank_nicolson.h)
