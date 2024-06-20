#include "../SmartCalc/controller.h"
#include <gtest/gtest.h>
constexpr int precision = 1e-7;

TEST(calc_test, test1) {
  s21::Controller controller;
  controller.InputNewExpression("(2+3)*5");
  auto result = controller.GetResult();
  EXPECT_EQ(25.0f, result.first);
}

TEST(calc_test, test2) {
  s21::Controller controller;
  controller.InputNewExpression("1/2 + (2+3)/(sin(9-2)^2-6/7)");
  auto result = controller.GetResult();
  EXPECT_LT(precision, fabs(-11.2506 - result.first));
}

TEST(calc_test, test3) {
  s21::Controller controller;
  controller.InputNewExpression("1/2+(2+3");
  auto result = controller.GetResult();
  EXPECT_EQ(kERROR, result.second);
}

TEST(calc_test, test4) {
  s21::Controller controller;
  controller.InputNewExpression("1/2+(2.3.5+3)");
  auto result = controller.GetResult();
  EXPECT_EQ(kERROR, result.second);
}

TEST(calc_test, test5) {
  s21::Controller controller;
  controller.InputNewExpression("1**");
  auto result = controller.GetResult();
  EXPECT_EQ(kERROR, result.second);
}

TEST(calc_test, test6) {
  s21::Controller controller;
  controller.InputNewExpression("sin(2) * cos(5) + tan(67^2) /\
            sin(128) - atan(sqrt(9)) - (4 mod 2) * log(5)");
  auto result = controller.GetResult();
  EXPECT_LT(precision, fabs(-1.47532 - result.first));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
