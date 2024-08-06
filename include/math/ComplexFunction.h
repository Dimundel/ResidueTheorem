#ifndef COMPLEX_FUNCTION_H
#define COMPLEX_FUNCTION_H

#include "ComplexNumber.h"
#include <map>
#include <vector>

class ComplexFunction {
public:
  virtual ComplexNumber operator()(const ComplexNumber &number) = 0;
};

class Polynomial : public ComplexFunction {
private:
  std::map<int, ComplexNumber> m_coefs;

public:
  Polynomial() = default;
  Polynomial(const ComplexNumber &coef, const int power);
  Polynomial(const std::vector<std::pair<ComplexNumber, int>> &coefs);
  ComplexNumber operator()(const ComplexNumber &number) override;
};

#endif