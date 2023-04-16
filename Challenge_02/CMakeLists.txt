cmake_minimum_required(VERSION 3.24)
project(Challenge_02)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(Challenge_02
        extendedAssert.hpp
        testBasicZeroFun.cpp
        QuasiNewton.h
        Bisection.h
        RegulaFalsi.h
        Secant.h
        SolverTraits.h
        SolverBase.h)
