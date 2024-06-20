#include "credit.h"
#include "ui_credit.h"

s21::Credit::Credit(QWidget *parent)
    : QDialog(parent), ui(new s21::Ui::Credit) {
  ui->setupUi(this);
  connect(ui->button_calc, SIGNAL(clicked()), this, SLOT(GetMonthPay_()));
}

s21::Credit::~Credit() { delete ui; }

void s21::Credit::GetMonthPay_() {
  if (ui->radio_anuitet->isChecked())
    GetAnuitetCreditPay_();
  else
    GetDifferensiveCreditPay_();
}

void s21::Credit::GetAnuitetCreditPay_() {
  CreditAnuitetData credit_data;
  credit_data.credit_sum = (double)ui->spin_sum->value();
  credit_data.percent = (double)ui->spin_percent->value();
  credit_data.month_count = (ui->combo_type->currentText() == "Мес.")
                                ? ui->spin_time->value()
                                : ui->spin_time->value() * 12;
  controller_.CalculateMonthPay(&credit_data);
  ui->res_pay->setText(QString::number(credit_data.monthly_payment, 'f', 2));
  ui->res_sum->setText(QString::number(credit_data.summary_pay, 'f', 2));
  ui->res_overpay->setText(QString::number(credit_data.overpay, 'f', 2));
}

void s21::Credit::GetDifferensiveCreditPay_() {
  CreditDifferensiveData credit_data;
  credit_data.credit_sum = (double)ui->spin_sum->value();
  credit_data.percent = (double)ui->spin_percent->value();
  credit_data.month_count = (ui->combo_type->currentText() == "Мес.")
                                ? ui->spin_time->value()
                                : ui->spin_time->value() * 12;
  controller_.CalculateMonthPay(&credit_data);
  ui->res_pay->setText(
      QString::number(credit_data.monthly_payment_min, 'f', 2) + " ... " +
      QString::number(credit_data.monthly_payment_max, 'f', 2));
  ui->res_sum->setText(QString::number(credit_data.summary_pay, 'f', 2));
  ui->res_overpay->setText(QString::number(credit_data.overpay, 'f', 2));
}
