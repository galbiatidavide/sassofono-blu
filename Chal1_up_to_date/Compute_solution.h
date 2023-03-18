//
// Created by Davide Galbiati on 18/03/2023.
//

#include <functional>
#include <limits>
#include <vector>
#include "Derivatives.hpp"
#include "newton.hpp"


#ifndef CHAL1_COMPUTE_SOLUTION_H
#define CHAL1_COMPUTE_SOLUTION_H


class Compute_solution {

private:
    std::function<double(const double&, const double&)> f;

    const unsigned int num_steps;
    const double       starting_time;
    const double       final_time;
    const double       initial_datum;

public:

    Compute_solution(std::function<double(const double&, const double&)> &f, const double initial_datum,
                     const double final_time, const unsigned int num_steps, const double starting_time = 0):
              f(f)
            , starting_time(starting_time)
            , final_time(final_time)
            , initial_datum(initial_datum)
            , num_steps(num_steps)
    {
        if (starting_time > final_time) {
            std::cerr << "Fatal error: times must be physically consistent.";
            exit(1);
        }
    }

    std::vector<std::vector<double>> solve() const;

    std::function<double(double)> getF(const double& step, const double& present, const double& future, const double& present_solution, std::function<double(const double&, const double&)>& f) const;

    std::function<double(double)> getdF(const double& step, const double& present, const double& future, const double& present_solution, std::function<double(const double&, const double&)>& f) const;
};


#endif //CHAL1_COMPUTE_SOLUTION_H
