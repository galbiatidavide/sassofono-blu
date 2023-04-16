//
// Created by Davide Galbiati on 16/04/2023.
//

#ifndef CHALLENGE_02_SECANT_H
#define CHALLENGE_02_SECANT_H
#include "extendedAssert.hpp"
#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
#include <limits>
#include <tuple>
#include "functionConcepts.hpp"

/*!
 * Computes the zero of a scalar function with the method of the secant
 * It stops when \f$|f(x)|\le tol|f(a)| + tola
 *
 * @tparam Function
 * @param f The function
 * @param a First point for computation of derivatives
 * @param b Second point for computing derivatives
 * @param tol relative tolerance
 * @param tola absolute tolerance
 * @param maxIt maximum number of iterations
 * @return The approximation of the zero of f and a status (false if not
 * converging)
 *
 */
namespace apsc
{
    template<TypeTraits::ScalarFunction Function>
    std::tuple<double, bool>
    secant(Function const &f, double a, double b, double tol = 1e-4,
           double tola = 1.e-10, unsigned int maxIt = 150) {
        double ya = f(a);
        double resid = std::abs(ya);
        double c{a};
        unsigned int iter{0u};
        double check = tol * resid + tola;
        bool goOn = resid > check;
        while (goOn && iter < maxIt) {
            ++iter;
            double yb = f(b);
            c = a - ya * (b - a) / (yb - ya);
            double yc = f(c);
            resid = std::abs(yc);
            goOn = resid > check;
            ya = yc;
            a = c;
        }

        return std::make_tuple(c, (iter < maxIt));
    }
}

#endif //CHALLENGE_02_SECANT_H
