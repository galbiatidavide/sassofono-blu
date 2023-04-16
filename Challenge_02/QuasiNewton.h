//
// Created by Davide Galbiati on 16/04/2023.
//

#ifndef CHALLENGE_02_QUASINEWTON_H
#define CHALLENGE_02_QUASINEWTON_H
#include "extendedAssert.hpp"
#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
#include <limits>
#include <tuple>
#include "functionConcepts.hpp"

/*!
 * Computes the zero of a scalar function with the Newton
 * It stops when \f$|f(x)|\le tol|f(a)| + tola
 *
 * @tparam Function double(double)
 * @param f The function
 * @param df the derivative
 * @param a Initial point
 * @param tol relative tolerance
 * @param tola absolute tolerance
 * @param maxIt maximum number of iterations
 * @return The approximation of the zero of f and a status (false if not
 * converging)
 *
 */
namespace apsc
{
    template<TypeTraits::ScalarFunction Function, TypeTraits::ScalarFunction Dfunction>
    std::tuple<double, bool>
    Newton(Function const &f, Dfunction const &df, double a, double tol = 1e-4,
           double tola = 1.e-10, unsigned int maxIt = 150) {
        double ya = f(a);
        double resid = std::abs(ya);
        unsigned int iter{0u};
        double check = tol * resid + tola;
        bool goOn = resid > check;
        while (goOn && iter < maxIt) {
            ++iter;
            a += -ya / df(a);
            ya = f(a);
            resid = std::abs(ya);
            goOn = resid > check;
        }

        return std::make_tuple(a, (iter < maxIt));
    }
}

#endif //CHALLENGE_02_QUASINEWTON_H
