//
// Created by Alessandra Gotti on 17/04/23.
//

#include "RegulaFalsi.h"


ResultType RegulaFalsi::solve() {

    double ya = (*argument)(a);
    double yb = (*argument)(b);
    double delta = b - a;
    double resid0 = std::max(std::abs(ya), std::abs(yb));

    SURE_ASSERT(ya * yb < 0, "Function must change sign at the two end values");

    double yc{ya};
    double c{a};
    double incr = std::numeric_limits<double>::max();
    constexpr double small = 10.0 * std::numeric_limits<double>::epsilon();
    while (std::abs(yc) > tol1 * resid0 + tol2 && incr > small) {
        double incra = -ya / (yb - ya);
        double incrb = 1. - incra;
        double incr = std::min(incra, incrb);

        ASSERTM((std::max(incra, incrb) <= 1.0 && incr >= 0), "Chord is failing")
        c = a + incra * delta;
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

    return c;

}
