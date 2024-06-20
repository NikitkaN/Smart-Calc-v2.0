#include "controller.h"

/* Controller method called from view
returns a result of the form:
{[answer], NUM} if the expression was valid, and
{[0.0], ERROR} if the expression was incorrect. */

void s21::Controller::InputNewExpression(std::string expression) {
  model_.InputNewExpression(expression);
}

/* Controller method called from view
returns a result of the form:
{[answer], NUM} if the expression was valid, and
{[0.0], ERROR} if the expression was incorrect. */

s21::Controller::lexem s21::Controller::GetResult() {
  return model_.GetCalculated();
}

/* Calculates points for the graph using a method from model
0 - it was successful
1 - the expression did not contain the x variable */

int s21::Controller::GraphCalculation(GraphData *data) {
  return model_.GraphCalculation(data);
}

/* Calculates the data for the credit calculator
using a method from model
overloading for annuity loan */

void s21::Controller::CalculateMonthPay(CreditAnuitetData *data) {
  model_.CalculateMonthPay(data);
}

/* Calculates the data for the credit calculator
using the method from model
overload for differential loan */

void s21::Controller::CalculateMonthPay(CreditDifferensiveData *data) {
  model_.CalculateMonthPay(data);
}
