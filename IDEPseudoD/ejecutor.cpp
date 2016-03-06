#include "ejecutor.h"
#include "ui_ejecutor.h"

ejecutor::ejecutor(QString file, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ejecutor)
{
    ui->setupUi(this);
    this->file = file;
    this->fileIn = "/usr/share/idepseudod/buffer/Input.txt";
    this->fileOut = "/usr/share/idepseudod/buffer/Output.txt";
    this->commandExec = "ipdc -f %file%";
    this->args << "-f" << this->file;
}

ejecutor::~ejecutor()
{
    delete ui;
}

/*void ejecutor::ejecutar(QString file)
{
    QString finalFile;
    if(file == "")
    {
        // Ejecuta this->file
        finalFile = this->file;
    }
    else
    {
        // Ejecuta arg file
        finalFile = file;
    }
    /*QProcess proc(this);
    QString exec("xterm");
    QStringList args;
    args << "-into" << QString::number(this->winId());
    proc.execute(exec,args);*//*
    QString command = "xterm -into ";
    command.append(QString::number(this->winId()));
    system(command.toStdString().c_str());*/
//}

void ejecutor::on_pushButton_clicked()
{
    QProcess proc(this);
    proc.start(ui->lineEdit->text());
    proc.waitForStarted(-1);
    proc.waitForFinished(-1);
    proc.close();
}

void ejecutor::on_pushButton_2_clicked()
{
    QFile fil(fileIn);
    if(!fil.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "No se puede abrir el archivo para ejecutar";
        ui->textEdit->setText("<span style=\"color: red;\">No se pudo abrir el archivo predeterminado</span>");
        return;
    }
    QTextStream stream(&fil);
    stream << ui->plainTextEdit->toPlainText();
    fil.close();
    QProcess proc(this);
    QString command = this->commandExec.replace("%file%",this->file);
    proc.setStandardInputFile(this->fileIn);
    proc.setStandardOutputFile(this->fileOut);
    proc.start(command);
    proc.waitForStarted();
    proc.waitForFinished();
    QFile fl2(fileOut);
    if(!fl2.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "No se puede abrir el archivo para ejecutar";
        ui->textEdit->setText("<span style=\"color: red;\">No se pudo abrir el archivo predeterminado</span>");
        return;
    }
    QTextStream strm(&fl2);
    QString allData = fl2.readAll();
    ui->textEdit->setPlainText(allData);
    fl2.close();
}

void ejecutor::on_pushButton_4_clicked()
{
    ejecutor_config cfg(this);
    cfg.exec();
    this->fileIn = cfg.inputFile;
    this->fileOut = cfg.outputFile;
    this->commandExec = cfg.command;
}
