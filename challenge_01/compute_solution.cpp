//
// Created by Davide Galbiati on 14/03/2023.
//

#include "compute_solution.h"

auto forcing_term = [](double x) { return std::stod(argv[1]); };

double parse_initial_condition(const char* str)
{
    return std::stod(str);
}

double parse_final_time(const char* str)
{
    return std::stod(str);
}

double parse_number_of_intervals(const char* str)
{
    return std::stod(str);
}










