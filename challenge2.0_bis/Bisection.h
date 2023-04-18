//
// Created by Alessandra Gotti on 17/04/23.
//

#ifndef CHALLENGE2_0_BISECTION_H
#define CHALLENGE2_0_BISECTION_H

#include "SolverBase.h"


class Bisection : public SolverBase {

public:


    ResultType solve() override;

    void prova() override {std::cout << "Bisection";};

    Bisection() = default;
    Bisection(double x1, double x2, double level = 1.e-5, ArgumentType const *function = nullptr) :
    SolverBase(function), a(x1), b(x2), tol(level) {};

    ~Bisection() override {};

private:
    double a;
    double b;
    double tol;

};


#endif //CHALLENGE2_0_BISECTION_H
