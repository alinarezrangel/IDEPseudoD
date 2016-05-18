#include "intabtextedit.h"
#include "ui_intabtextedit.h"

InTabTextEdit::InTabTextEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InTabTextEdit)
{
    ui->setupUi(this);
    //highlight = new PseudoDSyntaxHighlighter(ui->textEdit->document());
    hasChanged = false;
    fileName = "";
    this->filter = new MainEventFilter();
    //ui->textEdit->installEventFilter(this->filter);
    /*QPalette colors = ui->textEdit->palette();
    colors.setColor(QPalette::Base,QColor(201,201,201));
    ui->textEdit->setPalette(colors);*/
    this->editable = true;
}

InTabTextEdit::~InTabTextEdit()
{
    //delete highlight;
    delete filter;
    delete ui;
}

PseudoDSyntaxHighlighter* InTabTextEdit::getHighlighter(void)
{
    return this->ui->textEdit->getHighlighter();
}

void InTabTextEdit::on_textEdit_textChanged()
{
    hasChanged = true;
}

void InTabTextEdit::saveFile()
{
    qDebug() << "saveFile() called";
    if(fileName == "")
    {
        qDebug() << "The file name is void";
        fileName = QFileDialog::getSaveFileName(this,"Save file","/home","PseudoD files (*.pd *.psd *.pseudo);;All files (*)");
        QFile ffile(fileName);
        if(!ffile.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug() << "The file not open";
            QMessageBox::warning(this,"Unable to open","Unable to open the file for save",QMessageBox::Ok);
            fileName = "";
            myFileStatus.goodSave = false;
            return;
        }
        ffile.write(ui->textEdit->toPlainText().toUtf8());
        ffile.close();
        qDebug() << "Nice!";
    }
    else
    {
        qDebug() << "Saving with the file name";
        QFile ffile(fileName);
        if(!ffile.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug() << "The file not open";
            QMessageBox::warning(this,"Unable to open","Unable to open the file for save",QMessageBox::Ok);
            fileName = "";
            myFileStatus.goodSave = false;
            return;
        }
        ffile.write(ui->textEdit->toPlainText().toUtf8());
        ffile.close();
        qDebug() << "Nice 2!";
    }
    myFileStatus.goodSave = true;
}

void InTabTextEdit::openFile()
{
    this->editable = false;
    qDebug() << "Open file called";
    fileName = QFileDialog::getOpenFileName(this,"Open file","/home","PseudoD files (*.pd *.psd *.pseudo);;All files (*)");
    QFile ffile(fileName);
    if(!ffile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "The file not open";
        QMessageBox::warning(this,"Unable to open","Unable to open the file for read",QMessageBox::Ok);
        fileName = "";
        myFileStatus.goodOpen = false;
        return;
    }
    QTextStream in(&ffile);
    ui->textEdit->setText(in.readAll());
    ffile.close();
    myFileStatus.goodOpen = true;
    qDebug() << "Niceg!";
    this->editable = true;
}

QString InTabTextEdit::getAllText(void)
{
    return ui->textEdit->toPlainText();
}

void InTabTextEdit::setAllText(QString str)
{
    ui->textEdit->setPlainText(str);
}

QString InTabTextEdit::getHTMLSource(void)
{
    return ui->textEdit->toHtml();
}
