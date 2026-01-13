

#include <iostream>
#include <vector> // could also use QList later in Qt

#include "MainWindow.h"
#include <QApplication>

using namespace std;



int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();
}

