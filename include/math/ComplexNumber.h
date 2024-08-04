#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

#include <ostream>

struct ComplexNumber {
  double real;
  double imag;

  ComplexNumber();
  ComplexNumber(const double r);
  ComplexNumber(const int r);
  ComplexNumber(const double r, const double i);
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

ComplexNumber &operator*=(ComplexNumber &first, double second);

ComplexNumber operator*(const ComplexNumber &first, double second);

ComplexNumber operator*(double first, const ComplexNumber &second);

ComplexNumber &operator*=(ComplexNumber &first, const ComplexNumber &second);

ComplexNumber operator*(const ComplexNumber &first,
                        const ComplexNumber &second);

ComplexNumber &operator/=(ComplexNumber &first, double second);

ComplexNumber operator/(const ComplexNumber &firt, double second);

ComplexNumber &operator/=(ComplexNumber &first, const ComplexNumber &second);

ComplexNumber operator/(const ComplexNumber &first,
                        const ComplexNumber &second);

ComplexNumber operator/(double first, const ComplexNumber &second);

ComplexNumber pow(const ComplexNumber &number, const int power);

std::ostream &operator<<(std::ostream &stream, const ComplexNumber &number);

#endif