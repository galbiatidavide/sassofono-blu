//
// Created by Davide Galbiati on 18/03/2023.
//

#include <muParser.h>
#include <functional>

#include <memory>
#include <string>

class MuparserFunExact
{
public:
  MuparserFunExact(const MuparserFunExact &m)
    : m_parser(m.m_parser)
  {
    m_parser.DefineVar("t", &m1_var);
  };

  MuparserFunExact(const std::string &s)
  {
    try
      {
        m_parser.DefineVar("t", &m1_var);
        m_parser.SetExpr(s);
      }
    catch (mu::Parser::exception_type &e)
      {
        std::cerr << e.GetMsg() << std::endl;
      }
  };

  double
  operator()(const double &t)
  {
    double f = 0;

    m1_var = t;

    try
      {
        f = m_parser.Eval();
      }
    catch (mu::Parser::exception_type &e)
      {
        std::cerr << e.GetMsg() << std::endl;
      }
    return f;
  };

private:
  double     m1_var;

  mu::Parser m_parser;
};
