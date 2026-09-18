#include "mainwindow.h"
#include "math/calculator.h"

// QT
#include <QComboBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <qcombobox.h>

// Could start using a Designer UI file
// (https://doc.qt.io/qt-6/designer-using-a-ui-file.html)
// Or a style sheet.
MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
  m_left = new QLineEdit(this);
  m_right = new QLineEdit(this);
  m_op = new QComboBox(this);
  m_result = new QLabel("= ?", this);

  m_left->setValidator(new QDoubleValidator(this));
  m_right->setValidator(new QDoubleValidator(this));
  m_op->addItems({"+", "-", "*", "/"});

  auto *equals = new QPushButton("=", this);
  connect(equals, &QPushButton::clicked, this, &MainWindow::calculate);
  connect(m_left, &QLineEdit::returnPressed, this, &MainWindow::calculate);
  connect(m_right, &QLineEdit::returnPressed, this, &MainWindow::calculate);

  auto *row = new QHBoxLayout;
  row->addWidget(m_left);
  row->addWidget(m_op);
  row->addWidget(m_right);
  row->addWidget(equals);

  auto *layout = new QVBoxLayout(this);
  layout->addLayout(row);
  layout->addWidget(m_result);

  setWindowTitle("Qt Calculator");

  /*
   * When using squareRoot m_right should be hidden.
   * */
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
