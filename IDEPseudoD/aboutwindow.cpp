#include "aboutwindow.h"
#include "ui_aboutwindow.h"

AboutWindow::AboutWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutWindow)
{
    ui->setupUi(this);
    QFont font;
    font.setWeight(QFont::Bold);
    ui->label_2->setFont(font);
}

AboutWindow::~AboutWindow()
{
    delete ui;
}
