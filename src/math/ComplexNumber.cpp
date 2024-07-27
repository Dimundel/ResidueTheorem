#include "math/ComplexNumber.h"
#include <cmath>

double abs(const ComplexNumber &number) {
  return std::sqrt(number.real * number.real + number.imag * number.imag);
}

double arg(const ComplexNumber &number) {
  return std::atan2(number.imag, number.real);
}

ComplexNumber &operator+=(ComplexNumber &first, const ComplexNumber &second) {
  first.real += second.real;
  return first;
}

ComplexNumber operator+(const ComplexNumber &first,
                        const ComplexNumber &second) {
  ComplexNumber res = {first.real + second.real, first.imag + second.imag};
  return res;
}

ComplexNumber &operator-=(ComplexNumber &first, const ComplexNumber &second) {
  first.real -= second.real;
  first.imag -= second.imag;
  return first;
}

ComplexNumber operator-(const ComplexNumber &first,
                        const ComplexNumber &second) {
  ComplexNumber res = {first.real - second.real, first.imag + -second.imag};
  return res;
}

ComplexNumber &operator*=(ComplexNumber &first, const ComplexNumber &second) {
  double new_real = first.real * second.real - first.imag * second.imag;
  first.imag = first.real * second.imag + first.imag * second.real;
  first.real = new_real;
  return first;
}

ComplexNumber operator*(const ComplexNumber &first,
                        const ComplexNumber &second) {
  ComplexNumber res = first;
  res *= second;
  return res;
}