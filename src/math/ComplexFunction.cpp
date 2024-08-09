#include "math/ComplexFunction.h"
#include "math/ComplexNumber.h"
#include <cmath>
#include <memory>

Polynomial::Polynomial(const ComplexNumber &coef, const int power) {
  m_coefs[power] = coef;
}

Polynomial::Polynomial(
    const std::vector<std::pair<ComplexNumber, int>> &coefs) {
  for (auto pair : coefs) {
    m_coefs[pair.second] = pair.first;
  }
}

void Polynomial::print(std::ostream &stream) const {
  auto it = m_coefs.crbegin();
  while (it != m_coefs.crend()) {

    if (!(it->second.real == 1 && it->second.imag == 0)) {
      stream << it->second;
    }

    if (it->first > 0) {
      stream << "z";
    }
    if (it->first > 1) {
      stream << "^" << it->first;
    }

    ++it;
    if (it != m_coefs.crend() &&
        (it->second.real > 0 ||
         (it->second.real == 0 && it->second.imag > 0))) {
      stream << "+";
    }
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

Exponential::Exponential(std::unique_ptr<ComplexFunction> exponent)
    : m_coef(ComplexNumber(1)), m_exponent(std::move(exponent)){};

Exponential::Exponential(const ComplexNumber &coef,
                         std::unique_ptr<ComplexFunction> exponent)
    : m_coef(coef), m_exponent(std::move(exponent)){};

Exponential &Exponential::operator=(Exponential &&other) noexcept {
  if (this != &other) {
    m_coef = other.m_coef;
    m_exponent = std::move(other.m_exponent);
  }
  return *this;
}

void Exponential::print(std::ostream &stream) const {
  if (!(m_coef.real == 1 && m_coef.imag == 0)) {
    stream << m_coef;
  }
  stream << "exp(" << *m_exponent << ")";
}

ComplexNumber Exponential::operator()(const ComplexNumber &number) {
  ComplexNumber exponent_value = (*m_exponent)(number);
  return std::exp(exponent_value.real) *
         ComplexNumber(std::cos(exponent_value.imag),
                       std::sin(exponent_value.imag));
}

std::ostream &operator<<(std::ostream &stream,
                         const ComplexFunction &function) {
  function.print(stream);
  return stream;
}