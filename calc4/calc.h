#pragma once
#include <QWidget>

class QLabel;
class QLineEdit;
class QSpinBox;
class QComboBox;
class QPushButton;

class Calc : public QWidget
{
    Q_OBJECT

public:
    Calc(QWidget *parent = 0);

public slots:
    void calculate();

private:
    QLineEdit *mResult;
    QSpinBox *mV1;
    QSpinBox *mV2;
    QComboBox *mOperation;
    QPushButton *mButton1;
};
