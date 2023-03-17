//
// Created by Davide Galbiati on 15/03/2023.
//

#ifndef MY_ENV_CRANK_NICOLSON_H
#define MY_ENV_CRANK_NICOLSON_H

#include "Derivatives.hpp"
#include "basicZeroFun.hpp"
#include "horner.hpp"
#include "newton.hpp"
#include <tuple>

class crank_nicolson {

public:
/*
    auto f = [](double t, std::function<double(double)> y) {
        return std::exp(-t * y(t));
    };
*/
    auto f = [](auto input) {
        return [=](double t, std::function<double(double)> y) {
            return input(t, y(t));
        };
    };
\

    decltype(auto) F = [step, t1, t2, sol]( double x) {
        return x - (step/2)*(f(t2,x)+f(t1,sol))-sol;
    };
    //function that takes as input a single function wrapper and returns the result

std::vector<std::vector<double>> compute_crank_nicolson(const std::function<double(double t, std::function<double(double)> y)>& f, const double& number_of_intervals, const double &final_time,
                                                        const double& initial_condition){


        double step = final_time/initial_condition;
        std::vector<double> solution(number_of_intervals);
        std::vector<double> times(number_of_intervals);
        times.push_back(0.);
        solution.push_back(initial_condition);

        double initial_time = 0.0;
        double initial_sol = initial_condition;
        for(size_t i = 0; i < number_of_intervals - 1; ++i){




            auto dF = apsc::makeBackwardDerivative<1>(F, 1e-4);

            std::tuple<double, bool> my_tuple = apsc::Newton(F,dF, initial_sol);
            double sol = std::get<0>(my_tuple);
            times.push_back(initial_time);
            solution.push_back(sol);
            initial_time = initial_time + i*step;
            initial_sol = sol;
        }


        return {times,solution};
    }

};










#endif //MY_ENV_CRANK_NICOLSON_H
