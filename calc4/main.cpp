#include <QtGui/QApplication>
#include "calc.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Calc calc;
    calc.show();
    return app.exec();
}
