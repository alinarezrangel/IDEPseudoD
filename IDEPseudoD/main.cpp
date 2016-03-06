#include <QApplication>
#include <QSplashScreen>
#include <QPixmap>
#include <QThread>
#include "mainwindow.h"

class Sleeper : public QThread
{
public:
    static void sleep(unsigned long sec){QThread::sleep(sec);}
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pixmap("/usr/share/idepseudod/Iconos/splash.png");
    QSplashScreen splash(pixmap);
    splash.show();
    a.processEvents();
    splash.showMessage("Configurando los buffers",Qt::AlignBottom | Qt::AlignLeft);
    a.processEvents();
    Sleeper::sleep(2);
    splash.showMessage("Iniciando la IDE",Qt::AlignBottom | Qt::AlignLeft);
    a.processEvents();
    Sleeper::sleep(2);
    MainWindow w;
    w.show();
    splash.finish(&w);
    return a.exec();
}
