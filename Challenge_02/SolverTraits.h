//
// Created by Davide Galbiati on 17/04/2023.
//

#ifndef CHALLENGE_02_SOLVERTRAITS_H
#define CHALLENGE_02_SOLVERTRAITS_H

#include <functional>
#include <concepts>
#include <vector>
#include <array>





struct SolverTraits {

    //! The type of argument: an Eigen dynamic vector
    using ArgumentType = std::function<double(double)>;
    //! The return type: we want a function \f$R^N\to R^N\f$
    using ReturnType = double;
    //! The type for the non-linear system




};



#endif //CHALLENGE_02_SOLVERTRAITS_H
