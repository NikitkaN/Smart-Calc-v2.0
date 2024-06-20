#include "view.h"
#include "ui_view.h"

s21::View::View(QWidget *parent) : QMainWindow(parent), ui(new s21::Ui::View) {
  ui->setupUi(this);
  buttons_ = {
      ui->button_0,    ui->button_1,     ui->button_2,    ui->button_3,
      ui->button_4,    ui->button_5,     ui->button_6,    ui->button_7,
      ui->button_8,    ui->button_9,     ui->button_dot,  ui->button_x,
      ui->button_open, ui->button_close, ui->button_plus, ui->button_minus,
      ui->button_mult, ui->button_div,   ui->button_pow};
  func_buttons_ = {ui->button_sin,  ui->button_cos,  ui->button_tan,
                   ui->button_asin, ui->button_acos, ui->button_atan,
                   ui->button_sqrt, ui->button_ln,   ui->button_log,
                   ui->button_mod};
  this->ConnectButtons_();
}

s21::View::~View() { delete ui; }

void s21::View::ConnectButtons_() {
  for (auto it : buttons_) {
    connect(it, SIGNAL(clicked()), this, SLOT(AddSymToLabel_()));
  }
  for (auto it : func_buttons_) {
    connect(it, SIGNAL(clicked()), this, SLOT(AddFuncToLabel_()));
  }
  connect(ui->button_clear, SIGNAL(clicked()), this, SLOT(ClearLabel_()));
  connect(ui->button_delete, SIGNAL(clicked()), this, SLOT(ClearLabel_()));
  connect(ui->button_equal, SIGNAL(clicked()), this, SLOT(Calculate_()));
  connect(ui->radio_value, SIGNAL(toggled(bool)), this, SLOT(XEnabled_()));
  connect(ui->radio_graph, SIGNAL(toggled(bool)), this, SLOT(XEnabled_()));
  connect(ui->button_make_graph, SIGNAL(clicked()), this, SLOT(MakeGraph_()));
  connect(ui->credit_button, SIGNAL(clicked()), this, SLOT(StartCredit_()));
}

void s21::View::ErrorClear_() { // чистка лейбла перед вводом
  QString result_label = ui->result_show->text();
  if (result_label == "Ошибка ввода") {
    ui->result_show->setText("");
  }
}

void s21::View::AddSymToLabel_() { // добавление чисел и точки в лейбл
  QPushButton *button = (QPushButton *)sender();
  ErrorClear_();
  QString result_label = ui->result_show->text();
  ui->result_show->setText(result_label + button->text());
}

void s21::View::ClearLabel_() { // удаление одного или всех чисел из лейбла
  QPushButton *button = (QPushButton *)sender();
  QString result_label = ui->result_show->text();
  if (button == ui->button_delete)
    result_label = "";
  else
    result_label.resize(result_label.size() - 1);
  ui->result_show->setText(result_label);
}

void s21::View::AddFuncToLabel_() {
  QPushButton *button = (QPushButton *)sender();
  ErrorClear_();
  QString result_label = ui->result_show->text();
  ui->result_show->setText(result_label + button->text() + "(");
}

void s21::View::Calculate_() {
  QString str = ui->result_show->text();
  if (ui->radio_value->isChecked()) {
    if (str.contains('x')) {
      str.replace("x", ui->x_value->toPlainText());
    }
    controller_.InputNewExpression(str.toStdString());
    s21::Controller::lexem result = controller_.GetResult();
    if (result.second == kERROR) {
      ui->result_show->setText("Ошибка ввода");
    } else {
      ui->result_show->setText(QString::number(result.first, 'g', 10));
    }
  }
}

void s21::View::XEnabled_() {
  QRadioButton *button = (QRadioButton *)sender();
  if (button == ui->radio_graph) {
    ui->x_value->setEnabled(0);
    ui->button_make_graph->setEnabled(1);
    this->setFixedWidth(957);
    this->setFixedHeight(618);
    ui->spin_max->setEnabled(true);
    ui->spin_min->setEnabled(true);
  } else {
    ui->x_value->setEnabled(1);
    ui->button_make_graph->setEnabled(0);
    this->setFixedWidth(520);
    this->setFixedHeight(618);
    ui->spin_max->setEnabled(false);
    ui->spin_min->setEnabled(false);
  }
}

void s21::View::MakeGraph_() {
  GraphData data;
  data.expression = ui->result_show->text().toStdString();
  data.Xmin = ui->spin_min->value();
  data.Xmax = ui->spin_max->value();
  int graph_result = controller_.GraphCalculation(&data);
  if (graph_result == 1) {
    ui->result_show->setText("Ошибка: Выражение не содержит 'x'");
  } else if (graph_result == 2) {
    ui->result_show->setText("Ошибка: Xmin == Xmax");
  } else {
    QVector<double> vector_x = QVector<double>(data.x.begin(), data.x.end());
    QVector<double> vector_y = QVector<double>(data.y.begin(), data.y.end());
    ui->widget->addGraph();
    ui->widget->graph(0)->data()->clear();
    ui->widget->graph(0)->addData(vector_x, vector_y);
    ui->widget->xAxis->setRange(data.Xmin, data.Xmax);
    ui->widget->yAxis->setRange(data.Ymin, data.Ymax);
    ui->widget->replot();
  }
}

void s21::View::StartCredit_() {
  Credit window;
  window.setModal(true);
  window.show();
  window.exec();
}
