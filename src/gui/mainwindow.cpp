#include "mainwindow.h"
#include "math/calculator.h"

// Other
#include <QComboBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
  m_left = new QLineEdit(this);
  m_right = new QLineEdit(this);
  m_op = new QComboBox(this);
  m_op->addItems({"+", "-", "*", "/"});
  m_result = new QLabel("= ?", this);

  auto *equals = new QPushButton("=", this);
  connect(equals, &QPushButton::clicked, this, &MainWindow::calculate);

  auto *row = new QHBoxLayout;
  row->addWidget(m_left);
  row->addWidget(m_op);
  row->addWidget(m_right);
  row->addWidget(equals);

  auto *layout = new QVBoxLayout(this);
  layout->addLayout(row);
  layout->addWidget(m_result);

  setWindowTitle("Qt Calculator");
}

void MainWindow::calculate() {
  const double leftNumb = m_left->text().toDouble();
  const double rightNumb = m_right->text().toDouble();
  const QString operation = m_op->currentText();

  try {
    double r = 0.0;
    if (operation == "+")
      r = calc::add(leftNumb, rightNumb);
    else if (operation == "-")
      r = calc::subtract(leftNumb, rightNumb);
    else if (operation == "*")
      r = calc::multiply(leftNumb, rightNumb);
    else if (operation == "/")
      r = calc::divide(leftNumb, rightNumb);

    m_result->setText(QString("= %1").arg(r));
  } catch (const std::exception &e) {
    m_result->setText(e.what());
  }
}
