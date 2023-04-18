//
// Created by Alessandra Gotti on 17/04/23.
//

#ifndef CHALLENGE2_0_SECANT_H
#define CHALLENGE2_0_SECANT_H

#include"SolverBase.h"


class Secant : public SolverBase{

public:

    ResultType solve() override;

    Secant() = default;
    Secant(double x1, double x2, double level1 = 1.e-4, double level2 = 1.e-10,
           ArgumentType const *function = nullptr, unsigned int it = 150) :
           SolverBase(function), a(x1), b(x2), tol1(level1), tol2(level2), maxIt(it) {};

    void prova() override {std::cout << "Secant";};

    ~Secant() override {};

private:

    double a;
    double b;
    double tol1;
    double tol2;
    unsigned int maxIt;

};


#endif //CHALLENGE2_0_SECANT_H
