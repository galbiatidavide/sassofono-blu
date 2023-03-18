
#include "muparser_fun.hpp"
#include "Compute_solution.h"
#include <GetPot>



int
main(int argc, char **argv)
{
    GetPot datafile("test1.txt");

    const std::string forcing_term_str  = datafile("forcing_term", "-t * exp( -y )");
    const std::string initial_datum_str  = datafile("initial_datum", "0");

    MuparserFun forcing_term(forcing_term_str), initial_datum(initial_datum_str);

    //sistemare la regolazione sui parametri del metodo di newton, se li assegnamo in ingresso dobbiamo sistemare il costruttore di compute solution e farglieli prendere
    const unsigned int n_max_it   = datafile("n_max_it", 100);
    const double       tol_fun    = datafile("tol_fun", 1.0e-14);
    const double       tol_x      = datafile("tol_x", 1.0e-14);
    const double       final_time = datafile("final_time", 10);
    const unsigned int num_steps  = datafile("num_steps", 1000);
    const std::string  filename = datafile("filename", "data.txt");

    //perche' non lo legge forcing term che nell'ese lo fa cosi?
    Compute_solution solver(forcing_term, initial_datum, final_time, num_steps);

    //stampare bene perche sono vettori serve il ciclo
    std::cout << "x    = " << solver.solve() << std::endl;


    return 0;
}
