//
// Created by Davide Galbiati on 14/03/2023.
//

#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>

#ifndef CHALLENGE_01_COMPUTE_SOLUTION_H
#define CHALLENGE_01_COMPUTE_SOLUTION_H


class compute_solution {
private:
    double initial_condition;
    double T;
    int N;
public:
    compute_solution(double initial_condition, double T, int N): initial_condition{initial_condition}, T{T}, N{N}{}

    //might return a tuple
    std::vector<std::vector<double>> numerical_solution(std::vector<std::function<double(double,double)>>, int);

    double forcing_term = [](double x);

};


//! Computes the Nth derivative of a function by finite difference
/*!
\tparam N the order of the derivative
\tparam F the callable object of signature T (T const &)
\tparam T The argument and return type of the callable object
\tparam DT The type of differencing: either DifferenceType::FORWARD or
DifferenceType::BACKWARD or DifferenceType::CENTERED
 */
template <unsigned N, typename F, typename T = double,
          typename DT = DifferenceType::FORWARD>
class NthDerivative
{
public:
  //! the previous derivative, the type is switched.
  using PreviousDerivative = NthDerivative<N - 1, F, T, typename DT::otherType>;
  //! Constructor
  /*!
  \param f The function (callable object)
  \param h The spacing to be used in the formula
   */
  NthDerivative(const F &f, T h) : pDerivative{f, h}, h{h} {}
  //! The call operator that computes the derivative
  /*!
  \param x The point where the derivative is computed
  \return The derivative value
   */
  T
  operator()(const T &x) const
  {
    if constexpr(std::is_same<DifferenceType::FORWARD, DT>::value)
      return (pDerivative(x + h) - pDerivative(x)) / h;
    else if constexpr(std::is_same<DifferenceType::BACKWARD, DT>::value)
      return (pDerivative(x) - pDerivative(x - h)) / h;
    else
      return (pDerivative(x + h) - pDerivative(x - h)) / (2 * h);
  }

private:
  PreviousDerivative pDerivative;
  T const            h;
};

/*!
   * Specialization for first derivative
   * @tparam F A callable object type
   * @tparam T The type of the varaible
   * @tparam DT The difference type
 */
template <typename F, typename T, typename DT> class NthDerivative<1u, F, T, DT>
{
public:
  //! Constructor
  NthDerivative(const F &f, T h) : f{f}, h{h} {}
  T
  operator()(const T &x) const
  {
    //! This is C++17 syntax. Don't use a simple  if if you want efficiency!
    if constexpr(std::is_same_v<DifferenceType::FORWARD, DT>)
      return (f(x + h) - f(x)) / h;
    else if constexpr(std::is_same_v<DifferenceType::BACKWARD, DT>)
      return (f(x) - f(x - h)) / h;
    else
      return (f(x + h) - f(x - h)) / (2. * h);
  }

private:
  // Now I store the function
  F const &f;
  T const  h;
};




#endif //CHALLENGE_01_COMPUTE_SOLUTION_H
