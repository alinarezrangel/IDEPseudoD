#include "ejecutor_config.h"
#include "ui_ejecutor_config.h"

ejecutor_config::ejecutor_config(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ejecutor_config)
{
    ui->setupUi(this);
}

ejecutor_config::~ejecutor_config()
{
    delete ui;
}

void ejecutor_config::on_buttonBox_accepted()
{
    this->command = this->ui->lineEdit_2->text();
    this->inputFile = this->ui->lineEdit->text();
    this->outputFile = this->ui->lineEdit_3->text();
}

void ejecutor_config::on_pushButton_clicked()
{
    this->inputFile = QFileDialog::getOpenFileName(this,"Select file","/home","Text files (*.txt);;All files (*)");
}

void ejecutor_config::on_pushButton_2_clicked()
{
    this->outputFile = QFileDialog::getOpenFileName(this,"Select file","/home","Text files (*.txt);;All files (*)");
}
