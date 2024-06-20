#ifndef S21_CREDIT_H
#define S21_CREDIT_H

#include "controller.h"
#include <QDialog>

namespace s21 {

namespace Ui {
class Credit;
}

class Credit : public QDialog {
  Q_OBJECT

public:
  explicit Credit(QWidget *parent = nullptr);
  ~Credit();

private:
  Ui::Credit *ui;
  Controller controller_;
  void GetAnuitetCreditPay_();
  void GetDifferensiveCreditPay_();

private slots:
  void GetMonthPay_();
};

} // namespace s21
#endif // S21_CREDIT_H
