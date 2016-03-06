#ifndef EJECUTOR_CONFIG_H
#define EJECUTOR_CONFIG_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <QKeySequence>
#include <QFileDialog>

namespace Ui {
class ejecutor_config;
}

class ejecutor_config : public QDialog
{
    Q_OBJECT
    
public:
    explicit ejecutor_config(QWidget *parent = 0);
    ~ejecutor_config();

    QString command;
    QString inputFile;
    QString outputFile;
private slots:
    void on_buttonBox_accepted();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ejecutor_config *ui;
};

#endif // EJECUTOR_CONFIG_H
