#include "math/ComplexNumber.h"
#include <cmath>

double abs(const ComplexNumber &number) {
  return std::sqrt(number.real * number.real + number.imag * number.imag);
}

double arg(const ComplexNumber &number) {
  return std::atan2(number.imag, number.real);
}

ComplexNumber conjugate(const ComplexNumber &number) {
  ComplexNumber res = {number.real, -number.imag};
  return res;
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
  ComplexNumber res = {first.real - second.real, first.imag - second.imag};
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

ComplexNumber &operator*=(ComplexNumber &first, double second) {
  first.real *= second;
  first.imag *= second;
  return first;
}

ComplexNumber operator*(const ComplexNumber &first, double second) {
  ComplexNumber res = first;
  res *= second;
  return res;
}

ComplexNumber operator*(double first, const ComplexNumber &second) {
  return second * first;
}

ComplexNumber &operator/=(ComplexNumber &first, double second) {
  first.real /= second;
  first.imag /= second;
  return first;
}

ComplexNumber operator/(const ComplexNumber &first, double second) {
  ComplexNumber res = first;
  res /= second;
  return res;
}

ComplexNumber &operator/=(ComplexNumber &first, const ComplexNumber &second) {
  first *= conjugate(second) / abs(second) / abs(second);
  return first;
}

ComplexNumber operator/(const ComplexNumber &first,
                        const ComplexNumber &second) {
  ComplexNumber res = first;
  res /= second;
  return res;
}

ComplexNumber operator/(double first, const ComplexNumber &second) {
  ComplexNumber res = {first, 0};
  res /= second;
  return res;
}

std::ostream &operator<<(std::ostream &stream, const ComplexNumber &number) {
  if (number.real == 0 && number.imag == 0) {
    stream << "0";
  } else {
    if (number.real != 0) {
      stream << number.real;
    }

    if (number.imag > 0) {
      stream << "+" << number.imag << "i";
    } else if (number.imag < 0) {
      stream << number.imag << "i";
    } else if (number.real == 0) {
      stream << number.imag << "i";
    }
  }

  return stream;
}