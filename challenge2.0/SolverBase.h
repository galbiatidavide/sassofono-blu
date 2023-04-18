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
    virtual ~SolverBase(){};

    //getter and setter
    virtual void setArgument(ArgumentType const *fun) {argument = fun;};
    const ArgumentType *getArgument(ArgumentType const *fun) const {return argument;};

    //method
    virtual ArgumentType solve() const = 0;


protected:
    ArgumentType const *argument;

};


#endif //CHALLENGE2_0_SOLVERBASE_H
