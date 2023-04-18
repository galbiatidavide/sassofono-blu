#include <iostream>
#include "SolverFactory.h"

int main() {

    std::function<double(const double &)> func =
            [](const double &x) {return x - 4;};

    std::function<double(const double &)> der =
            [](const double &x) {return 1;};


    SolverFactory factory;
    ResultType resb = 0, ress = 0, resq = 0, resr = 0;
    Bisection provaZerib(0, 10, 1.e-5, &func);
    Secant  provaZeris (0, 10, 1.e-4, 1.e-10, &func, 150);
    QuasiNewton provaZeriq(0,  der, 1.e-4,  1.e-10, 150, &func);
    RegulaFalsi provaZerir(0, 10, 1.e-6, 1.e-10, &func);


    resb = provaZerib.solve();
    std::cout << resb << std::endl;

    ress = provaZeris.solve();
    std::cout << ress << std::endl;

    resq = provaZeriq.solve();
    std::cout << resq << std::endl;

    resr = provaZerir.solve();
    std::cout << resr;


    return 0;
}
