#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

struct ComplexNumber {
  double real;
  double imag;
};

double abs(const ComplexNumber &number);

double arg(const ComplexNumber &number);

ComplexNumber &operator+=(ComplexNumber &first, const ComplexNumber &second);

ComplexNumber operator+(const ComplexNumber &first,
                        const ComplexNumber &second);

ComplexNumber &operator-=(ComplexNumber &first, const ComplexNumber &second);

ComplexNumber operator-(const ComplexNumber &first,
                        const ComplexNumber &second);

ComplexNumber &operator*=(ComplexNumber &first, const ComplexNumber &second);

ComplexNumber operator*(const ComplexNumber &first,
                        const ComplexNumber &second);

#endif