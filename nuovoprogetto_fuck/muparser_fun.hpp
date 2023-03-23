//
// Created by Davide Galbiati on 18/03/2023.
//

#include <muParser.h>
#include <functional>

#include <memory>
#include <string>

class MuparserFun
{
public:
  MuparserFun(const MuparserFun &m)
    : m_parser(m.m_parser)
  {
    m_parser.DefineVar("t", &m1_var);
    m_parser.DefineVar("y", &m2_var);
  };

  MuparserFun(const std::string &s)
  {
    try
      {
        m_parser.DefineVar("t", &m1_var);
        m_parser.DefineVar("y", &m2_var);
        m_parser.SetExpr(s);
      }
    catch (mu::Parser::exception_type &e)
      {
        std::cerr << e.GetMsg() << std::endl;
      }
  };

  double
  operator()(const double &t, const double &y)
  {
    double f = 0;

    m1_var = t;
    m2_var = y;

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
  double     m2_var;

  mu::Parser m_parser;
};
