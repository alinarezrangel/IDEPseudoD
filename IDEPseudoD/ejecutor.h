#ifndef EJECUTOR_H
#define EJECUTOR_H

#include <QDialog>
#include <QTextStream>
#include <QFile>
#include <QIODevice>
#include <QProcess>
#include <QString>
#include <QStringList>
#include <cstdlib>
//#include "terminal.h"
#include <QDebug>
#include <QTextStream>
#include "ejecutor_config.h"

namespace Ui {
class ejecutor;
}

class ejecutor : public QDialog
{
    Q_OBJECT
    
public:
    explicit ejecutor(QString file,QWidget *parent = 0);
    ~ejecutor();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::ejecutor *ui;
    QString fileIn;
    QString fileOut;
    QString file;
    QString commandExec;
    QStringList args;
};

#endif // EJECUTOR_H
