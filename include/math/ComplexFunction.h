#ifndef COMPLEX_FUNCTION_H
#define COMPLEX_FUNCTION_H

#include "ComplexNumber.h"
#include <map>
#include <memory>
#include <ostream>
#include <vector>

class ComplexFunction {
public:
  virtual ComplexNumber operator()(const ComplexNumber &number) = 0;
  friend std::ostream &operator<<(std::ostream &os, const ComplexFunction &cf);

protected:
  virtual void print(std::ostream &stream) const = 0;
};

class Polynomial : public ComplexFunction {
private:
  std::map<int, ComplexNumber> m_coefs;

protected:
  void print(std::ostream &stream) const override;

public:
  Polynomial() = default;
  Polynomial(const ComplexNumber &coef, const int power);
  Polynomial(const std::vector<std::pair<ComplexNumber, int>> &coefs);
  ComplexNumber operator()(const ComplexNumber &number) override;
};

class Exponential : public ComplexFunction {
private:
  ComplexNumber m_coef;
  std::unique_ptr<ComplexFunction> m_exponent;

protected:
  void print(std::ostream &stream) const override;

public:
  Exponential(std::unique_ptr<ComplexFunction> exponent);
  Exponential(const ComplexNumber &coef,
              std::unique_ptr<ComplexFunction> exponent);
  Exponential &operator=(Exponential &&other) noexcept;

  ComplexNumber operator()(const ComplexNumber &number) override;
};

#endif