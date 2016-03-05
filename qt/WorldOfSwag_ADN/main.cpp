#include <QApplication>
#include <iostream>
#include <stdlib.h>
#include <ctime>

#include "utils/utils.hpp"
#include "mainwindow.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    return app.exec();
}
