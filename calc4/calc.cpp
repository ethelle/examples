#include <QtGui>
#include "calc.h"
Calc::Calc(QWidget *parent)
    :QWidget(parent)
{
    mV1 = new QSpinBox;
    mV1->setRange(-20000, 20000);
    mV1->setValue(0);

    mOperation = new QComboBox;
    mOperation->addItem(tr("+"));
    mOperation->addItem(tr("-"));
    mOperation->addItem(tr("*"));
    mOperation->addItem(tr("/"));

    mV2 = new QSpinBox;
    mV2->setRange(-20000, 20000);
    mV2->setValue(0);

    QLabel *eqLabel = new QLabel(tr("="));

    mResult = new QLineEdit;
    mResult->setReadOnly(true);
    mResult->setMaxLength(15);
    QString str = QString::number(mV1->value());

    mResult->setText(str);

    QObject::connect(mV1, SIGNAL(valueChanged(int)),this, SLOT(calculate()));
    QObject::connect(mV2, SIGNAL(valueChanged(int)),this, SLOT(calculate()));
    QObject::connect(mOperation, SIGNAL(currentIndexChanged(int)),this, SLOT(calculate()));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(mV1, 0, 0);
    mainLayout->addWidget(mOperation, 0, 1);
    mainLayout->addWidget(mV2, 0, 2);
    mainLayout->addWidget(eqLabel, 0, 3);
    mainLayout->addWidget(mResult, 0, 4, Qt::AlignRight);
    setLayout(mainLayout);

    setWindowTitle(tr("Simple Calc"));

    calculate();

}

void Calc::calculate()
{

    QString str;
    int val1= Calc::mV1->value();
    int val2= Calc::mV2->value();

    int n = Calc::mOperation->currentIndex();
    switch (n)
    {
    case 0:
        str = QString::number(val1+val2);
        break;
    case 1:
        str = QString::number(val1-val2);
        break;
    case 2:
        str = QString::number(val1*val2);
        break;
    case 3:
        if (val2!=0)
        {
            str = QString::number(double (val1)/double(val2));
            break;
        }
        else
        {
            QMessageBox::information(this, tr("Error"),tr("divide by 0"));
            str = QString::number(0);
            break;
        }
    }
    Calc::mResult->setText(str);
}
