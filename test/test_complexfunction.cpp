#include "math/ComplexFunction.h"
#include "math/ComplexNumber.h"
#include "gtest/gtest.h"
#include <gtest/gtest.h>

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

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}