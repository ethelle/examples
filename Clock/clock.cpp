#include <QtGui>
#include "clock.h"
#include "clockWidget.h"
Clock::Clock(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("Clock"));
    resize(200, 240);

    ClockWidget *clockWidget = new ClockWidget;

    QPushButton *buttonGMT = new QPushButton;
    buttonGMT->setText(tr("GMT"));
    QPushButton *buttonLocal = new QPushButton;
    buttonLocal->setText(tr("Local"));


    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(buttonGMT);
    layout->addWidget(buttonLocal);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(clockWidget,0,0);
    mainLayout->addLayout(layout,1,0);
    setLayout(mainLayout);

    connect(buttonGMT, SIGNAL(clicked()), clockWidget, SLOT(timeGMT()));
    connect(buttonLocal, SIGNAL(clicked()), clockWidget, SLOT(timeLoc()));
}
