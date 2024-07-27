#include "math/ComplexNumber.h"
#include <gtest/gtest.h>

class ComplexNumberTest : public testing::Test {
protected:
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

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}