//
// Created by Alessandra Gotti on 17/04/23.
//

#include "Bisection.h"

ResultType Bisection::solve() {

    double ya = (*argument)(a);
    double yb = (*argument)(b);
    double delta = b - a;

    SURE_ASSERT(ya * yb < 0, "Function must change sign at the two end values");

    double yc{ya};
    double c{a};
    while (std::abs(delta) > 2 * tol) {
        c = (a + b) / 2.;
        yc = (*argument)(c);
        if (yc * ya < 0.0) {
            yb = yc;
            b = c;
        } else {
            ya = yc;
            a = c;
        }
        delta = b - a;
    }
    return (a + b) / 2.;
}
