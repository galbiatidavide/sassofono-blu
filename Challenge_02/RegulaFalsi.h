//
// Created by Davide Galbiati on 16/04/2023.
//

#ifndef CHALLENGE_02_REGULAFALSI_H
#define CHALLENGE_02_REGULAFALSI_H
#include "extendedAssert.hpp"
#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
#include <limits>
#include <tuple>
#include "functionConcepts.hpp"

/*!
 * Computes the zero of a scalar function with the method of the Regula Falsi
 * We stop when the residual is below lolerance;
 *
 * @tparam Function
 * @param f The function
 * @param a First end of initial interval
 * @param b Second end of initial interval
 * @param tol Tolerance (relative)
 * @parma tola Tolerance (absolute)
 * @return The approximation of the zero of f
 * @pre f(a)*f(b)<0
 */
namespace apsc
{
    template<TypeTraits::ScalarFunction Function>
    double
    regulaFalsi(Function const &f, double a, double b, double tol = 1.e-6,
                double tola = 1.e-10) {
        double ya = f(a);
        double yb = f(b);
        double delta = b - a;
        double resid0 = std::max(std::abs(ya), std::abs(yb));
        SURE_ASSERT(ya * yb < 0, "Function must change sign at the two end values");
        double yc{ya};
        double c{a};
        double incr = std::numeric_limits<double>::max();
        constexpr double small = 10.0 * std::numeric_limits<double>::epsilon();
        while (std::abs(yc) > tol * resid0 + tola && incr > small) {
            double incra = -ya / (yb - ya);
            double incrb = 1. - incra;
            double incr = std::min(incra, incrb);
            ASSERTM((std::max(incra, incrb) <= 1.0 && incr >= 0), "Chord is failing")
            c = a + incra * delta;
            // std::cout << c << std::endl;
            yc = f(c);
            if (yc * ya < 0.0) {
                yb = yc;
                b = c;
            } else {
                ya = yc;
                a = c;
            }
            delta = b - a;
            /*
             *      std::cout << delta << " " << yc << " " << ya << " " << yb << " "
             * << incr
             *      << std::endl;
             */
        }
        return c;
    }
}

#endif //CHALLENGE_02_REGULAFALSI_H


