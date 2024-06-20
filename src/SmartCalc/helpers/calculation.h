#ifndef SRC_CALCULATION_H_
#define SRC_CALCULATION_H_

#include "operations.h"
#include <math.h>

namespace s21 {
struct calculation {
public:
  double CalcOne(int operation, double num) {
    double result = 0;
    if (operation == kCOS)
      result = cos(num);
    else if (operation == kSIN)
      result = sin(num);
    else if (operation == kTAN)
      result = tan(num);
    else if (operation == kACOS)
      result = acos(num);
    else if (operation == kASIN)
      result = asin(num);
    else if (operation == kATAN)
      result = atan(num);
    else if (operation == kSQRT)
      result = sqrt(num);
    else if (operation == kLN)
      result = log(num);
    else if (operation == kLOG)
      result = log10(num);
    return result;
  }
  double CalcTwo(int operation, double num1, double num2) {
    double result = 0;
    if (operation == kPOW)
      result = pow(num2, num1);
    else if (operation == kMULT)
      result = num2 * num1;
    else if (operation == kDIV)
      result = num2 / num1;
    else if (operation == kMOD)
      result = fmod(num2, num1);
    else if (operation == kSUM)
      result = num2 + num1;
    else if (operation == kSUB)
      result = num2 - num1;
    return result;
  }
};
} // namespace s21
#endif //