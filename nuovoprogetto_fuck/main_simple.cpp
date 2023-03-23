#include <iostream>
#include <functional>
#include <cmath>
#include <iomanip>
#include <vector>
#include <fstream>
#include <muParser.h>
#include "muparser_fun.hpp"
#include "muparser_fun_exact.hpp"
#include "GetPot"
#include "Compute_solution.h"
//librerie? (dove)
//ciclo non va
//perche le stampa uguali ma poi il grafico va bene
//quando conseganre ora
//in quanti si puo consegnare
//fare doppio main
//separare il codice in .cpp
//perche il make non va le cose

int main(int argc, char **argv) {

    std::cerr<<"ciaooooooooooooooooo";
 /*   std::function<double(double const &, double const&)> f = [](double const &t, double const& y){
        return -t * exp(-y);
    };

    std::function<double(double const &)> exact_solution = [](double const &t){

      return log(-0.5*t*t+1);
    };
*/
    GetPot datafile("data_parameters.txt");
    const std::string forcing_term_str  = datafile("forcing_term", "-t * exp( -y )");
    const std::string exact_sol_str  = datafile("exact_solution", "log(-0.5*t*t+1)");

    const unsigned int n_max_it      = datafile("n_max_it", 100);
    const unsigned int num_steps     = datafile("number_steps", 100);
    const double       initial_datum = datafile("initial_datum", 0);
    const double       tol_fun       = datafile("tol_fun", 1.0e-14);
    const double       tol_x         = datafile("tol_x", 1.0e-14);
    const double       final_time    = datafile("final_time", 10);
    const double       starting_time = datafile("starting_time", 0);
    const std::string  filename = datafile("filename", "data_parameters.txt");

    MuparserFun f(forcing_term_str);
    MuparserFunExact exact_solution(exact_sol_str);

    Compute_solution solver(f, exact_solution, initial_datum, starting_time, final_time, num_steps);
    solver.solve();
    std::vector<std::vector<double>> sol = solver.get_uh();
    solver.convergence();
    double my_L2_norm = solver.get_L2_norm();
    double my_infinite_norm = solver.get_infinite_norm();

    const int colWidth = 12;
    std::cout << std::fixed << std::setprecision(5);

    for(size_t i = 0; i < sol[0].size(); ++i){
        std::cout << "u_h = " << sol[1][i] << std::setw(colWidth) << " at time t_n = " << sol[0][i] << std::endl;
    }


    std::cout << "Result file: result.dat" << std::endl;
    std::ofstream file("result.dat");
    file << "#time\tcomputed solution" << std::endl;

    for(int m = 0; m < sol[0].size(); ++m)
    {
        file.setf(std::ios::left, std::ios::adjustfield);
        file.width(16);
        file << sol[0][m] << "\t\t" << sol[1][m] << "\n";
    }

    file << "#L2-norm is    " << my_L2_norm << std::endl;
    file << "#infinite-norm is  " << my_infinite_norm << std::endl;

    std::vector<double> L2_norms;
    std::vector<double> infinite_norms;
    std::vector<double> steps;
    int num = 50;
//1
    Compute_solution solver1(f, exact_solution, initial_datum, starting_time, final_time, num);
    solver1.solve();
    solver1.convergence();
    L2_norms.push_back(solver1.get_L2_norm());
    std::cerr<<solver1.get_L2_norm()<<std::endl;
    infinite_norms.push_back(solver1.get_infinite_norm());
    steps.push_back(solver1.get_step());

//2
    Compute_solution solver2(f, exact_solution, initial_datum, starting_time, final_time, 500);
    solver2.solve();
    solver2.convergence();
    L2_norms.push_back(solver2.get_L2_norm());
    std::cerr<<solver1.get_L2_norm()<<std::endl;
    infinite_norms.push_back(solver2.get_infinite_norm());
    steps.push_back(solver2.get_step());
//3
    Compute_solution solver3(f, exact_solution, initial_datum, starting_time, final_time, 5000);
    solver3.solve();
    solver3.convergence();
    L2_norms.push_back(solver3.get_L2_norm());
    std::cerr<<solver1.get_L2_norm()<<std::endl;
    infinite_norms.push_back(solver3.get_infinite_norm());
    steps.push_back(solver3.get_step());
//4
    Compute_solution solver4(f, exact_solution, initial_datum, starting_time, final_time, 50000);
    solver4.solve();
    solver4.convergence();
    L2_norms.push_back(solver4.get_L2_norm());
    std::cerr<<solver1.get_L2_norm()<<std::endl;
    infinite_norms.push_back(solver4.get_infinite_norm());
    steps.push_back(solver4.get_step());
    /*
    for(size_t i = 0; i < 5; ++i){
        Compute_solution solver(f, exact_solution, 0, 1, num);
        solver.solve();
        solver.convergence();
        L2_norms.push_back(solver.get_L2_norm());
        infinite_norms.push_back(solver.get_infinite_norm());
        steps.push_back(solver.get_step());
        num = num * 10;
    }*/

    std::cout << "Result file: error.dat" << std::endl;
    std::ofstream file2("error.dat");

    for(int m = 0; m < L2_norms.size(); ++m)
    {
        file2.setf(std::ios::left, std::ios::adjustfield);
        file2.width(16);
        file2 << steps[m] << "\t\t" << L2_norms[m] << "\t\t" <<infinite_norms[m] << "\n";
    }

    return 0;
}

