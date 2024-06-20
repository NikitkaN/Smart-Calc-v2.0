#ifndef SRC_OPERATIONS_H_
#define SRC_OPERATIONS_H_
#include <string>
#include <vector>
/*
Кодировки операций, функций и ошибок
*/

enum operation {
  kNUM = 0,
  kU_MIN = 1,
  kCOS = 2,
  kSIN = 3,
  kTAN = 4,
  kACOS = 5,
  kASIN = 6,
  kATAN = 7,
  kSQRT = 8,
  kLN = 9,
  kLOG = 10,
  kPOW = 11,
  kMULT = 12,
  kDIV = 13,
  kMOD = 14,
  kSUM = 15,
  kSUB = 16,
  kERROR = 18,
  kOPEN = 19,
  kCLOSE = 20
};

struct GraphData {
  int Xmin, Xmax;
  int Ymin, Ymax;
  std::string expression;
  std::vector<double> x, y;
};

struct CreditAnuitetData {
  double credit_sum;
  double percent;
  int month_count;
  double monthly_payment;
  double summary_pay;
  double overpay;
};

struct CreditDifferensiveData {
  double credit_sum;
  double percent;
  int month_count;
  double monthly_payment_min;
  double monthly_payment_max;
  double summary_pay;
  double overpay;
};

#endif // SRC_OPERATIONS_H_
