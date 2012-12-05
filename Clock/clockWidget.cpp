#include <QtGui>
#include "clockWidget.h"
#include <time.h>
ClockWidget::ClockWidget(QWidget *parent)
    : QWidget(parent)
{
    setBackgroundRole(QPalette::Midlight);
    setAutoFillBackground(true);

    QTimer *mTimer = new QTimer(this);
    connect(mTimer, SIGNAL(timeout()), this, SLOT(update()));
    mTimer->start(1000);

    locTime = 1;
}

void ClockWidget::setLocTime(int i)
{
    locTime = i;
}

int ClockWidget::getLocTime()
{
    return locTime;
}

void ClockWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setWindow(-100,-100,200,200);
    int side = qMin(width(), height());
    painter.setViewport((width() - side) / 2, (height() - side) / 2,
                        side, side);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::darkCyan, 2, Qt::SolidLine, Qt::RoundCap));
    painter.setBrush(QBrush(Qt::lightGray, Qt::SolidPattern));
    painter.drawEllipse(-80,-80, 160, 160);

    // clock dial
    for (int i = 0; i <= 60; ++i)
    {
        if ((i % 5 == 0)&&(i!=0))
        {
            painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap));
            painter.drawEllipse(-1.5, -60, 3, 3);
            painter.drawText(-16, -75, 32, 30,
                             Qt::AlignHCenter | Qt::AlignTop,
                             QString::number(i/5));
        }
        else
        {
            painter.setPen(QPen(Qt::darkCyan, 1, Qt::SolidLine, Qt::RoundCap));
            painter.drawEllipse(0, -60, 1, 1);
        }
            painter.rotate(6);
    }
    painter.rotate(-6);

    tm *tm1 = NULL;
    time_t time1 = time(NULL);

    //time calculation
    if (getLocTime()==0)
        tm1 = gmtime(&time1);
    else
        tm1 = localtime(&time1);
    int hour1 = tm1->tm_hour;
    int min1 = tm1->tm_min;
    int sec1 = tm1->tm_sec;

    //hour hand
    painter.save();
    painter.rotate(30.0 * ((hour1 + min1 / 60.0)));//hour
    painter.fillRect(-3, -45, 6, 55, QBrush(Qt::black, Qt::SolidPattern));
    painter.restore();

    //minute hand
    painter.save();
    painter.rotate(6 * min1);
    painter.fillRect(-2, -60, 4, 70, QBrush(Qt::black, Qt::SolidPattern));//min
    painter.restore();

    //second hand
    painter.save();
    painter.rotate(6 * sec1);
    painter.fillRect(-1, -65, 2, 75, QBrush(Qt::red, Qt::SolidPattern));//sec
    painter.restore();

    painter.setBrush(QBrush(Qt::darkCyan, Qt::SolidPattern));
    painter.drawEllipse(-3, -3, 6, 6);
}

void ClockWidget::timeLoc()
{
    setLocTime(1);
}

void ClockWidget::timeGMT()
{
    setLocTime(0);
}

