#include "mainwindow.h"
#include <QApplication>
#include "Model/appmodel.h"

AppModel *App = AppModel::Instance();

int main(int argc, char *argv[])
{
    // App = AppModel::Instance();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
