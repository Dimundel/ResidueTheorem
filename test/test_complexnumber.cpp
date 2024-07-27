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
  EXPECT_EQ((num_real * num_imag).real, 0);
  EXPECT_EQ((num_real * num_imag).imag, -6);

  EXPECT_EQ((num1 * num2).real, -2);
  EXPECT_EQ((num1 * num2).imag, 11);
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}