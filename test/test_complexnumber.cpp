#include "math/ComplexNumber.h"
#include <cmath>
#include <gtest/gtest.h>
#include <sstream>

const double MAX_ERROR = 1e-6;

class ComplexNumberTest : public testing::Test {
protected:
  ComplexNumber num_zero = {0, 0};
  ComplexNumber num_real = {2, 0};
  ComplexNumber num_imag = {0, -3};
  ComplexNumber num1 = {3, -4};
  ComplexNumber num2 = {-2, 1};
};

TEST_F(ComplexNumberTest, Multiplication) {
  ComplexNumber result1 = num_real * num_imag;
  EXPECT_EQ(result1.real, 0) << "Expected real part to be 0";
  EXPECT_EQ(result1.imag, -6) << "Expected imaginary part to be -6";

  ComplexNumber result2 = num1 * num2;
  EXPECT_EQ(result2.real, -2) << "Expected real part to be -2";
  EXPECT_EQ(result2.imag, 11) << "Expected imaginary part to be 11";
}

TEST_F(ComplexNumberTest, Argument) {
  EXPECT_EQ(arg(num_real), 0);
  EXPECT_EQ(arg(num_imag), -M_PI / 2);
  EXPECT_NEAR(arg(num1), -0.92729521, MAX_ERROR);
  EXPECT_NEAR(arg(num2), 2.677945045, MAX_ERROR);
}

TEST_F(ComplexNumberTest, Division) {
  ComplexNumber result1 = num_zero / num2;
  EXPECT_EQ(result1.real, 0);
  EXPECT_EQ(result1.imag, 0);

  ComplexNumber result2 = num1 / num2;
  EXPECT_NEAR(result2.real, -2, MAX_ERROR);
  EXPECT_NEAR(result2.imag, 1, MAX_ERROR);

  ComplexNumber result3 = num1 / 2.;
  EXPECT_NEAR(result3.real, 1.5, MAX_ERROR);
  EXPECT_NEAR(result3.imag, -2, MAX_ERROR);

  ComplexNumber result4 = 3 / num2;
  EXPECT_NEAR(result4.real, -1.2, MAX_ERROR);
  EXPECT_NEAR(result4.imag, -0.6, MAX_ERROR);
}

TEST_F(ComplexNumberTest, Exponentiation) {
  ComplexNumber result1 = pow(num_zero, 3);
  EXPECT_EQ(result1.real, 0);
  EXPECT_EQ(result1.imag, 0);

  ComplexNumber result2 = pow(num_real, 2);
  EXPECT_EQ(result2.real, 4);
  EXPECT_EQ(result2.imag, 0);

  ComplexNumber result3 = pow(num1, 1);
  EXPECT_EQ(result3.real, 3);
  EXPECT_EQ(result3.imag, -4);

  ComplexNumber result4 = pow(num2, 2);
  EXPECT_EQ(result4.real, 3);
  EXPECT_EQ(result4.imag, -4);

  ComplexNumber result5 = pow(num2, 0);
  EXPECT_EQ(result5.real, 1);
  EXPECT_EQ(result5.imag, 0);

  ComplexNumber result6 = pow(num2, 18);
  EXPECT_EQ(result6.real, -922077);
  EXPECT_EQ(result6.imag, -1721764);
}

TEST_F(ComplexNumberTest, PrintOperator) {
  std::ostringstream output;

  output << num_zero;
  EXPECT_EQ(output.str(), "0");
  output.str("");

  output << num_real;
  EXPECT_EQ(output.str(), "2");
  output.str("");

  output << num_imag;
  EXPECT_EQ(output.str(), "-3i");
  output.str("");

  output << num1;
  EXPECT_EQ(output.str(), "3-4i");
  output.str("");

  output << num2;
  EXPECT_EQ(output.str(), "-2+1i");
  output.str("");
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}