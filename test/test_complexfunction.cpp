#include "math/ComplexFunction.h"
#include "math/ComplexNumber.h"
#include "gtest/gtest.h"
#include <cmath>
#include <gtest/gtest.h>
#include <memory>

const double MAX_ERROR = 1e-6;

class PolynomialTest : public testing::Test {
protected:
  PolynomialTest()
      : pol1({{ComplexNumber(1, 0), 2},
              {ComplexNumber(-1, 0), 1},
              {ComplexNumber(1, 0), 0}}),
        pol2(ComplexNumber(1), 3),
        pol3({{ComplexNumber(1, 1), 4}, {ComplexNumber(0, -2), 2}}) {}

  Polynomial pol1;
  Polynomial pol2;
  Polynomial pol3;
};

TEST_F(PolynomialTest, Evaluate) {
  ComplexNumber result1 = pol1(0);
  EXPECT_EQ(result1.real, 1);
  EXPECT_EQ(result1.imag, 0);

  ComplexNumber result2 = pol1(ComplexNumber(1, 1));
  EXPECT_EQ(result2.real, 0);
  EXPECT_EQ(result2.imag, 1);

  ComplexNumber result3 = pol2(1);
  EXPECT_EQ(result3.real, 1);
  EXPECT_EQ(result3.imag, 0);

  ComplexNumber result4 = pol2(ComplexNumber(0, -1));
  EXPECT_EQ(result4.real, 0);
  EXPECT_EQ(result4.imag, 1);

  ComplexNumber result5 = pol3(ComplexNumber(-1, 1));
  EXPECT_EQ(result5.real, -8);
  EXPECT_EQ(result5.imag, -4);
}

class ExponentialTest : public testing::Test {
protected:
  std::unique_ptr<Polynomial> pol1 =
      std::make_unique<Polynomial>(Polynomial(ComplexNumber(1), 1));
  std::unique_ptr<Polynomial> pol2 =
      std::make_unique<Polynomial>(Polynomial(ComplexNumber(0, -1), 1));
  std::unique_ptr<Polynomial> pol3 =
      std::make_unique<Polynomial>(Polynomial({{1, 2}, {-1, 1}, {1, 0}}));
  std::unique_ptr<Polynomial> pol4 = std::make_unique<Polynomial>(*pol1);
  std::unique_ptr<Exponential> exp =
      std::make_unique<Exponential>(std::move(pol4));

  Exponential exp1;
  Exponential exp2;
  Exponential exp3;
  Exponential exp4;
  ExponentialTest()
      : exp1(std::move(pol1)), exp2(std::move(pol2)), exp3(std::move(pol3)),
        exp4(std::move(exp)) {}
};

TEST_F(ExponentialTest, Evaluate) {
  ComplexNumber result1 = exp1(ComplexNumber(0));
  EXPECT_EQ(result1.real, 1);
  EXPECT_EQ(result1.imag, 0);

  ComplexNumber result2 = exp2(ComplexNumber(M_PI));
  EXPECT_NEAR(result2.real, -1, MAX_ERROR);
  EXPECT_NEAR(result2.imag, 0, MAX_ERROR);

  ComplexNumber result3 = exp2(ComplexNumber(M_PI / 2));
  EXPECT_NEAR(result3.real, 0, MAX_ERROR);
  EXPECT_NEAR(result3.imag, -1, MAX_ERROR);

  ComplexNumber result4 = exp3(ComplexNumber(1, 1));
  EXPECT_NEAR(result4.real, 0.54030230, MAX_ERROR);
  EXPECT_NEAR(result4.imag, 0.84147098, MAX_ERROR);

  ComplexNumber result5 = exp4(ComplexNumber(0, 1));
  EXPECT_NEAR(result5.real, 1.14383564, MAX_ERROR);
  EXPECT_NEAR(result5.imag, 1.27988300, MAX_ERROR);
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}