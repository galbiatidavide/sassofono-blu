//
// Created by Alessandra Gotti on 17/04/23.
//

#include "Secant.h"

//ho tolto const anche dall'header perchè non assegna altrimenti
//è comunque un probelma che va risolto perchè evidentemente non va bene mettere come oggetti
//boh

ResultType Secant::solve()  {

    double ya = (*argument)(a);
    double resid = std::abs(ya);
    double c{a};
    unsigned int iter{0u};
    double check = tol1 * resid + tol2;
    bool goOn = resid > check;
    while (goOn && iter < maxIt) {
        ++iter;
        double yb = (*argument)(b);
        c = a - ya * (b - a) / (yb - ya);
        double yc = (*argument)(c);
        resid = std::abs(yc);
        goOn = resid > check;
        ya = yc;
        a = c;
    }

    return c;
//return std::make_tuple(c, (iter < maxIt));

}
