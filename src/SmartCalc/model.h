#ifndef SRC_MODEL_H_
#define SRC_MODEL_H_

#include <iostream>
#include <list>
#include <map>
#include <stdio.h>
#include <string>
#include <utility>

#include "helpers/calculation.h"
#include "helpers/operations.h"

namespace s21 {
class Model {
public:
  using lexem = std::pair<double, int>;
  using parse_iter = std::string::iterator;

private:
  std::string expression_;
  std::list<std::pair<double, int>> stack_;
  std::list<std::pair<double, int>> output_;
  calculation calculation_;

  std::map<std::string, int> functions_dictionary_ = {
      {"cos", kCOS},   {"sin", kSIN},   {"tan", kTAN},   {"acos", kACOS},
      {"asin", kASIN}, {"atan", kATAN}, {"sqrt", kSQRT}, {"ln", kLN},
      {"log", kLOG},   {"mod", kMOD}};

  std::map<char, int> operations_dictionary_ = {
      {'~', kU_MIN}, {'*', kMULT}, {'^', kPOW},  {'/', kDIV},
      {'+', kSUM},   {'-', kSUB},  {'(', kOPEN}, {')', kCLOSE}};

public:
  Model() { ; }
  void InputNewExpression(std::string expression);
  ~Model() { ; }
  lexem GetCalculated();
  int GraphCalculation(GraphData *data);
  void CalculateMonthPay(CreditAnuitetData *data);
  void CalculateMonthPay(CreditDifferensiveData *data);

private:
  int ParseCycle_();
  lexem GetOperation_(parse_iter &iter);
  lexem GetNumber_(parse_iter &iter);
  lexem GetFunc_(parse_iter &iter);
  bool BringToNormal_();
  int CalcPrecedence_(lexem curr_lexem);
  void FilterLexem_(lexem curr_lexem);
  bool ProcessBrackets_(lexem curr_lexem);
  void ProcessPrecedence_(lexem curr_lexem);
  void MoveToOutput_();
  int GetResult_();
  int ApplyOperation_();
  int GetTwo_(double *num1, double *num2);
  int GetOne_(double *num);
  static bool IsNum_(char symbol);
  static bool IsLetter_(char symbol);
  void ErrorHandling_();
  void ExpressionReplace_(std::string &src, const std::string sub, char sym);
  void CalcDifferensiveCycle_(CreditDifferensiveData *data);
}; // class Model
} // namespace s21

#endif // SRC_MODEL_H_
