//
// Created by Alessandra Gotti on 17/04/23.
//

#include "Bisection.h"

ResultType Bisection::solve() {

    double ya = argument(a);
    double yb = argument(b);
    double delta = b - a;

    if(ya*yb>0){
        std::cerr << std::endl
        std::exit(ERRORSTATUS);
      }


    double yc{ya};
    double c{a};
    while (std::abs(delta) > 2 * tol) {
        c = (a + b) / 2.;
        yc = f(c);
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
