//
// Created by Alessandra Gotti on 17/04/23.
//

#ifndef CHALLENGE2_0_QUASINEWTON_H
#define CHALLENGE2_0_QUASINEWTON_H

#include "SolverBase.h"

class QuasiNewton : public SolverBase {

public:

    ResultType solve() override;

    QuasiNewton() = default;
    QuasiNewton(double x, ArgumentType der, double level1 = 1.e-4, double level2 = 1.e-10, unsigned int it = 150,
                ArgumentType const *function = nullptr) :
            SolverBase(function), a(x), tol1(level1), tol2(level2), derivative(der), maxIt(it) {};

    void prova() override {std::cout << "QuasiNewton";};

    ~QuasiNewton() override {};

private:
    const ArgumentType derivative;
    double a;
    double tol1;
    double tol2;
    unsigned int maxIt;




};


#endif //CHALLENGE2_0_QUASINEWTON_H
