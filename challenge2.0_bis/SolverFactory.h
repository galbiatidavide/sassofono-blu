//
// Created by Alessandra Gotti on 18/04/23.
//

#ifndef CHALLENGE2_0_SOLVERFACTORY_H
#define CHALLENGE2_0_SOLVERFACTORY_H

#include "SolverBase.h"
#include "Bisection.h"
#include "Secant.h"
#include "RegulaFalsi.h"
#include "QuasiNewton.h"

    enum SolverKind
    {
        BISECTION = 0,
        SECANT = 1,
        REGULAFALSI = 2,
        QUASINEWTON = 3,

    };


    //template <typename... Args> //i puntini mi permettono di passare un numero indefinito di parameteri

    class SolverFactory {

    public:
        std::unique_ptr<SolverBase> make_Solver(SolverKind kind) {
            switch (kind) {
                case BISECTION:
                    return std::make_unique<Bisection>();
                    break;
                case SECANT:
                    return std::make_unique<Secant>();
                    break;
                case REGULAFALSI:
                    return std::make_unique<RegulaFalsi>();
                    break;
                case QUASINEWTON:
                    return std::make_unique<QuasiNewton>();
                    break;
                default:
                    throw std::runtime_error(
                            "Error in SolverKind: You must specify a valid type");
            }
        }
    };

#endif //CHALLENGE2_0_SOLVERFACTORY_H


/*std::unique_ptr <SolverBase> make_Solver(SolverKind kind, Args &&...args) {
            switch (kind) {
                case BISECTION:
                    return std::make_unique<Bisection>(std::forward<Args>(args)...);
                    break;
                case SECANT:
                    return std::make_unique<Secant>(std::forward<Args>(args)...);
                    break;
                case REGULAFALSI:
                    return std::make_unique<RegulaFalsi>(std::forward<Args>(args)...);
                    break;
                case QUASINEWTON:
                    return std::make_unique<QuasiNewton>(std::forward<Args>(args)...);
                    break;
                default:
                    throw std::runtime_error(
                            "Error in SolverKind: You must specify a valid type");
            }
        }
*/