#include <QtGui/QApplication>
#include "mainwindow.h"
#include <stdio.h>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    MainWindow w;    
    w.show();
    app.quit();
    
    return app.exec();
}
