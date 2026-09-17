#pragma once
#include <QWidget>
#include <qtmetamacros.h>
#include <qwidget.h>

class QLineEdit;
class QComboBox;
class QLabel;

class MainWindow : public QWidget {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);

private slots:
  void calculate();

private:
  QLineEdit *m_left;
  QComboBox *m_op;
  QLineEdit *m_right;
  QLabel *m_result;
};
