#ifndef S21_VIEW_H
#define S21_VIEW_H

#include "credit.h"
#include <QMainWindow>

namespace s21 {
namespace Ui {
class View;
}

class View : public QMainWindow {
  Q_OBJECT

public:
  View(QWidget *parent = nullptr);
  ~View();

private:
  Ui::View *ui;
  s21::Controller controller_;
  QVector<QPushButton *> func_buttons_;
  QVector<QPushButton *> buttons_;
  void ErrorClear_();
  void ConnectButtons_();

private slots:
  void AddSymToLabel_();
  void ClearLabel_();
  void AddFuncToLabel_();
  void Calculate_();
  void XEnabled_();
  void MakeGraph_();
  void StartCredit_();
};

} // namespace s21
#endif // S21_VIEW_H
