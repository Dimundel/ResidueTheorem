#include "math/ComplexNumber.h"
#include <cmath>

double abs(const ComplexNumber &number) {
  return std::sqrt(number.real * number.real + number.imag * number.imag);
}