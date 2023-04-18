//
// Created by Alessandra Gotti on 17/04/23.
//

#include "QuasiNewton.h"


    ResultType QuasiNewton::solve() {

        double ya = (*argument)(a);
        double resid = std::abs(ya);
        unsigned int iter{0u};
        double check = tol1 * resid + tol2;
        bool goOn = resid > check;
        while (goOn && iter < maxIt) {
            ++iter;
            a += -ya / derivative(a);
            ya = (*argument)(a);
            resid = std::abs(ya);
            goOn = resid > check;
        }

            return a;
            //return std::make_tuple(a, (iter < maxIt));

        }
