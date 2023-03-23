//
// Created by Davide Galbiati on 19/03/2023.
//

#include <functional>
#include <limits>
#include <vector>
#include <cmath>
#include "Derivative.h"
#include "newton.hpp"

#ifndef CHALLENGE_01_COMPUTE_SOLUTION_H
#define CHALLENGE_01_COMPUTE_SOLUTION_H

class Compute_solution {

private:

    const unsigned int num_steps;
    const double       starting_time;
    const double       final_time;
    const double       initial_datum;

    /*
    const unsigned int n_max_it;
    const double       tol_fun;
    const double       tol_x;
     */
    const std::function<double(const double&, const double&)> f;
    const std::function<double(const double&)> exact_solution{};

    double       L2_norm{0};
    double       infinite_norm{0};
    double       step{0};
    std::vector<std::vector<double>> u_h{};

public:

    Compute_solution(const std::function<double(const double&, const double&)> &f, const std::function<double(const double&)> &exact_solution, const double &initial_datum, const double &starting_time,
                     const double &final_time, const unsigned int &num_steps): /*const unsigned int &n_max_it(n_max_it), const double &tol_fun(tol_fun), const double &tol_x(tol_x),*/
              f(f)
            , exact_solution(exact_solution)
            , starting_time(starting_time)
            , final_time(final_time)
            , initial_datum(initial_datum)
            , num_steps(num_steps)
            /*
            , n_max_it(n_max_it)
            , tol_fun(tol_fun)
            , tol_x(tol_x)*/

    {
        if (starting_time > final_time) {
            std::cerr << "Fatal error: times must be physically consistent.";
            exit(1);
        }
    }

    void solve()
    {

        step = (final_time - starting_time) / num_steps;
        std::vector<double> times{};
        std::vector<double> values{};

        double initial_solution = initial_datum;
        double initial_time = starting_time;

        for(size_t i = 0; i < num_steps; ++i){
            if(i == 0){
                times.push_back(initial_time);
                values.push_back(initial_solution);
            }else{
                NewtonSolver solver(getF(step, initial_time, initial_time + step, initial_solution, f), getdF(step, initial_time, initial_time + step, initial_solution, f),
                                    100, 1000.0, 1000.0);
                solver.solve(initial_solution);
                double future_sol_par = solver.get_result();
                initial_solution = future_sol_par + (step / 2) * f(initial_time + step, future_sol_par) + (step / 2) * f(initial_time, initial_solution);
                initial_time = initial_time + step;
                times.push_back(initial_time);
                values.push_back(initial_solution);
            }
        }
        u_h.push_back(times);
        u_h.push_back(values);
    }

    std::function<double(double)> getF(const double& step, const double& present, const double& future, const double& present_solution, const std::function<double(const double&, const double&)>& f) const
    {
        auto F = [=] (double x) {
            return x - (step / 2) * (f(future, x) + f(present, present_solution)) - present_solution;
        };
        return F;
    }

    std::function<double(double)> getdF(const double& step, const double& present, const double& future, const double& present_solution, const std::function<double(const double&, const double&)>& f) const
    {
        return derive<1>(getF(step, present, future, present_solution, f), 1e-4);
    }

    void convergence()
    {

        std::vector<double> error{};
        std::vector<double> exact_solution_discrete{};

        for(size_t i = 0; i < u_h[1].size(); ++i)
            exact_solution_discrete.push_back(exact_solution(u_h[0][i]));

        for(size_t i = 0; i < u_h[1].size(); ++i)
            error.push_back(exact_solution_discrete[i]-u_h[1][i]);

        L2_norm =  compute_L2_norm(error);
        infinite_norm = compute_infinite_norm(error);
    }

    double compute_L2_norm(std::vector<double> const &v) const
    {
        double norm{0};
        for(size_t i = 0; i < v.size(); ++i){
            norm += step * (v[i]) * (v[i]);
        }
        return sqrt(norm);
    }

    double compute_infinite_norm(std::vector<double> const &v) const
    {
        double norm{0};
        for(size_t i = 0; i < v.size(); ++i){
            double temp = v[i];
            if(v[i]<0)
                temp = -v[i];
            if(temp > norm)
                norm = temp;
        }
        return norm;
    }

    std::vector<std::vector<double>> get_uh() const
    {
        return u_h;
    };

    double get_step() const
    {
        return step;
    };

    double get_L2_norm() const
    {
        return L2_norm;
    };

    double get_infinite_norm() const
    {
        return infinite_norm;
    };
};

#endif //CHALLENGE_01_COMPUTE_SOLUTION_H
