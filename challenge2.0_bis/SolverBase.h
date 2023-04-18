//
// Created by Alessandra Gotti on 17/04/23.
//

#ifndef CHALLENGE2_0_SOLVERBASE_H
#define CHALLENGE2_0_SOLVERBASE_H

#include "Traits.h"
using namespace SolverTraits;

class SolverBase {

public:

    //constructor and destructor
    SolverBase(ArgumentType const *function = nullptr) : argument{function} {};
    virtual ~SolverBase() = default;

    //getter and setter
    virtual void setArgument(ArgumentType const *fun) {argument = fun;};
    const ArgumentType *getArgument(ArgumentType const *fun) const {return argument;};

    //method
    virtual ResultType solve()  = 0;
    virtual void prova() {};


protected:
    ArgumentType const *argument;

};


#endif //CHALLENGE2_0_SOLVERBASE_H
