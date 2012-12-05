#pragma once
#include <QWidget>

class ClockWidget : public QWidget
{
    Q_OBJECT

public:
    ClockWidget(QWidget *parent = 0);
    QTimer *mTimer;
    void setLocTime(int i);
    int getLocTime();

public slots:
    void timeLoc();
    void timeGMT();

protected:
    int locTime;
    void paintEvent(QPaintEvent *event);
};
