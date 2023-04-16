//
// Created by Davide Galbiati on 16/04/2023.
//

#ifndef CHALLENGE_02_SOLVERBASE_H
#define CHALLENGE_02_SOLVERBASE_H

#include <TypeTraits.h>
#include <SolverTraits.h>

namespace apsc
{
    class SolverBase : public SolverTraits {
    public:
        //! Takes a pointer to an existing non linear system
        SolverBase(std::function<double(double)> const *function = nullptr) : function{function} {};

        //! Sets the non linear system.
        virtual void
        setFunction(std::function<double(double)> const *fun)
        {
            function = fun;
        };

        //! Solves the system \f$J(x)z= b\f$
        //! /param x the point where to evaluate the Jacobian
        //! /param b the right hand side of the system J(x) y=b
        //! /return the result z
        virtual ArgumentType solve(ArgumentType const &x,
                                   ArgumentType const &b) const = 0;

        virtual ~SolverBase(){};

    protected:
        //! A pointer to the non-linear system
        std::function<double(double)> const *function;
    };





#endif //CHALLENGE_02_SOLVERBASE_H