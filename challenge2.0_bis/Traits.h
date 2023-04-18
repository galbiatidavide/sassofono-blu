//
// Created by Alessandra Gotti on 17/04/23.
//

#ifndef CHALLENGE2_0_TRAITS_H
#define CHALLENGE2_0_TRAITS_H

#include <functional>
#include <string>
#include <concepts>
#include <vector>
#include <array>
#include "extendedAssert.hpp"


namespace SolverTraits {
    using ArgumentType = std::function<double(const double&)>;
    using ResultType = double;
};

/*namespace TypeTraits{
    template<class F>
    concept ScalarFunction=std::convertible_to<F,std::function<double (double)> > ||
                           std::convertible_to<F,std::function<double (double const &)> >;
}*/

#endif //CHALLENGE2_0_TRAITS_H
