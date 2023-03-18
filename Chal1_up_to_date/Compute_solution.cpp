//
// Created by Davide Galbiati on 18/03/2023.
//

#include "Compute_solution.h"

std::vector<std::vector<double>> Compute_solution::solve() const{

    double step = (final_time - starting_time) / num_steps;
    std::vector<double> times(num_steps - 1);
    std::vector<double> values(num_steps - 1);

    double initial_solution = initial_datum;
    double initial_time = starting_time;

    for(size_t i = 0; i < num_steps - 1; ++i){
        if(i == 0){
            times.push_back(initial_time);
            values.push_back(initial_solution);
        } else {
            NewtonSolver solver(getF(step, initial_time, initial_time + i * step, initial_solution, f), getdF(), 100, 1000.0, 1000.0);
            solver.solve(initial_solution);
            initial_solution = solver.get_result();
            initial_time = initial_solution + i * step;
            times.push_back(initial_time);
            values.push_back(initial_solution);
        }
    }
    return {times, values};
}

std::function<double(double)> Compute_solution::getF(const double& step, const double& present, const double& future, const double& present_solution, std::function<double(const double&, const double&)>& f) const {
    auto F = [&] (double x) {
        return x - (step / 2) * (f(future, x) + f(present, present_solution)) - present_solution;
    };
    return F;
}

std::function<double(double)> Compute_solution::getdF(const double& step, const double& present, const double& future, const double& present_solution, std::function<double(const double&, const double&)>& f) const {
    auto dF = [&] (double x) {
        return apsc::makeCenteredDerivative<1>(getF(step, present, future, present_solution, f), 1e-4);;
    };
    return dF;
}