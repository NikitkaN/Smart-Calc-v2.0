#include "model.h"

namespace s21 {
class Controller {
public:
  using lexem = std::pair<double, int>;

private:
  s21::Model model_;

public:
  Controller() { ; }
  void InputNewExpression(std::string expression);
  ~Controller() { ; }
  lexem GetResult();
  int GraphCalculation(GraphData *data);
  void CalculateMonthPay(CreditAnuitetData *data);
  void CalculateMonthPay(CreditDifferensiveData *data);
}; // class Controller
} // namespace s21
