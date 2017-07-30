#include <QApplication>
#include "mainwindow.h"
//#include "startwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //StartWindow sw;
    //sw.show();

    MainWindow* w = new MainWindow;
    w->setWindowFlags(w->windowFlags() & ~Qt::WindowMaximizeButtonHint &  ~Qt::WindowMinimizeButtonHint);
    w->showMaximized();
    w->show();

    return a.exec();
}
