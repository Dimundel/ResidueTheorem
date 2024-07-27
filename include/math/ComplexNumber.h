#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

#include <ostream>

struct ComplexNumber {
  double real;
  double imag;
};

double abs(const ComplexNumber &number);

double arg(const ComplexNumber &number);

ComplexNumber conjugate(const ComplexNumber &number);

ComplexNumber &operator+=(ComplexNumber &first, const ComplexNumber &second);

ComplexNumber operator+(const ComplexNumber &first,
                        const ComplexNumber &second);

ComplexNumber &operator-=(ComplexNumber &first, const ComplexNumber &second);

ComplexNumber operator-(const ComplexNumber &first,
                        const ComplexNumber &second);

ComplexNumber &operator*=(ComplexNumber &first, const ComplexNumber &second);

ComplexNumber operator*(const ComplexNumber &first,
                        const ComplexNumber &second);

std::ostream &operator<<(std::ostream &stream, const ComplexNumber &number);

#endif