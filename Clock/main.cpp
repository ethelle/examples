#include <QtGui/QApplication>
#include "clock.h"
#include "clockWidget.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Clock clock;
    clock.show();
    return app.exec();
}
