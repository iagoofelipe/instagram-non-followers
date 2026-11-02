#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setOrganizationName("IagoCarvalho");
    a.setApplicationName("InstagramNonFollowers");

    MainWindow w;
    w.show();
    return QApplication::exec();
}
