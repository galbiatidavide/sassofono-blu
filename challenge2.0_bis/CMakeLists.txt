cmake_minimum_required(VERSION 3.24)
project(challenge2.0)

set(CMAKE_CXX_STANDARD 20)

add_executable(challenge2.0
        main.cpp
        Traits.h
        extendedAssert.hpp
        SolverFactory.h
        SolverBase.h
        Bisection.h
        Bisection.cpp
        Secant.h
        Secant.cpp
        QuasiNewton.h
        QuasiNewton.cpp
        RegulaFalsi.h
        RegulaFalsi.cpp
        )