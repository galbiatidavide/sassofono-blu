//
// Created by Davide Galbiati on 16/04/2023.
//

#ifndef CHALLENGE_02_SOLVERFACTORY_H
#define CHALLENGE_02_SOLVERFACTORY_H

#include "SolverBase.h"
#include "Bisection.h"
#include "QuasiNewton.h"
#include "RegulaFalsi.h"
#include "Secant.h"
#include <memory>
#include <stdexcept>

namespace apsc
{
    enum SolverResource {
        BISECTION = 0,
        QUASINEWTON = 1,
        REGULAFALSI = 2,
        SECANT = 3,
    };

//! A simple factory that returns a SolverBase polymorphic object wrapped in a
//! unique_prt
//!
//! /param resource The resource of solver type class you want
//! /param args Optional arguments to be forwarded to the constructor
//!
    template <typename... Args>
    std::unique_ptr<apsc::SolverBase>
    make_Solver(SolverResource resource, Args&&...args)
    {
        switch(resource)
        {
            case BISECTION:
                return std::make_unique<apsc::Bisection>(std::forward<Args>(args)...);
                break;
            case QUASINEWTON:
                return std::make_unique<apsc::QuasiNewton>(std::forward<Args>(args)...);
                break;
            case REGULAFALSI:
                return std::make_unique<apsc::RegulaFalsi>(std::forward<Args>(args)...);
                break;
            case SECANT:
                return std::make_unique<apsc::Secant>(std::forward<Args>(args)...);
                break;
            default:
                throw std::runtime_error(
                        "Error in SolverResource: You must specify a valid type");
        }
    }
}

#endif //CHALLENGE_02_SOLVERFACTORY_H
