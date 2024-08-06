#include "math/ComplexFunction.h"
#include "math/ComplexNumber.h"

Polynomial::Polynomial(const ComplexNumber &coef, const int power) {
  m_coefs[power] = coef;
}

Polynomial::Polynomial(
    const std::vector<std::pair<ComplexNumber, int>> &coefs) {
  for (auto pair : coefs) {
    m_coefs[pair.second] = pair.first;
  }
}

ComplexNumber Polynomial::operator()(const ComplexNumber &number) {
  if (m_coefs.size() == 1) {
    return m_coefs.begin()->second * pow(number, m_coefs.begin()->first);
  }
  ComplexNumber value = m_coefs.crbegin()->second;
  for (auto it = m_coefs.crbegin(); it != std::prev(m_coefs.crend(), 1); it++) {
    value *= pow(number, it->first - std::next(it, 1)->first);
    value += std::next(it, 1)->second;
  }
  value *= pow(number, m_coefs.begin()->first);
  return value;
}