//
// Created by Alessandra Gotti on 17/04/23.
//

#ifndef CHALLENGE2_0_REGULAFALSI_H
#define CHALLENGE2_0_REGULAFALSI_H

#include "SolverBase.h"


class RegulaFalsi : public SolverBase{

public:
    RegulaFalsi(double x1, double x2, double level1 = 1.e-6, double level1 = 1.e-10, ArgumentType const *function = nullptr) :
            SolverBase(function), a(x1), b(x2), tol1(level1), tol2(level2) {};

    ResultType solve() const override;

private:
    double a;
    double b;
    double tol1;
    double tol2;

};


#endif //CHALLENGE2_0_REGULAFALSI_H
