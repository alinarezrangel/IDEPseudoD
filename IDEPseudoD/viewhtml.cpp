#include "viewhtml.h"
#include "ui_viewhtml.h"

ViewHTML::ViewHTML(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewHTML)
{
    ui->setupUi(this);
}

ViewHTML::~ViewHTML()
{
    delete ui;
}

void ViewHTML::setHTML(QString& html)
{
    QString html_gen = html.mid(223,html.size() - 237);
    ui->textBrowser->setPlainText(html_gen);
}

void ViewHTML::on_pushButton_clicked()
{
    QClipboard* clip = QApplication::clipboard();
    clip->setText(ui->textBrowser->toPlainText());
}
