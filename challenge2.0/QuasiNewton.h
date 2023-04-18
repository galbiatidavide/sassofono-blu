//
// Created by Alessandra Gotti on 17/04/23.
//

#ifndef CHALLENGE2_0_QUASINEWTON_H
#define CHALLENGE2_0_QUASINEWTON_H

#include "SolverBase.h"

class QuasiNewton : public SolverBase {

public:
    //solve

    QuasiNewton(double x1, double x2, double first_pt, double level = 1.e-4, ArgumentType const *function = nullptr) :
            SolverBase(function), a(x1), b(x2), start_pt(first_pt), tol(level) {};

private:
    const ArgumentType derivative;
    double a;
    double b;
    double tol;
    double start_pt;



};


#endif //CHALLENGE2_0_QUASINEWTON_H
