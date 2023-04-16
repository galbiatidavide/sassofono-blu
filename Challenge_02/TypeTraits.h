//
// Created by Davide Galbiati on 17/04/2023.
//

#ifndef CHALLENGE_02_TYPETRAITS_H
#define CHALLENGE_02_TYPETRAITS_H

#include <functional>
#include <concepts>
#include <vector>
#include <array>


namespace TypeTraits{

    template<class F>
    concept ScalarFunction=std::convertible_to<F,std::function<double (double)> > ||
    std::convertible_to<F,std::function<double (double const &)> >;
}

#endif //CHALLENGE_02_TYPETRAITS_H
