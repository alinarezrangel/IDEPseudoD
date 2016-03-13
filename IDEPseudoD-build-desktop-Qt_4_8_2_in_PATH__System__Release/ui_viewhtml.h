/********************************************************************************
** Form generated from reading UI file 'viewhtml.ui'
**
** Created: Sun Mar 13 15:18:36 2016
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWHTML_H
#define UI_VIEWHTML_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_ViewHTML
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;

    void setupUi(QDialog *ViewHTML)
    {
        if (ViewHTML->objectName().isEmpty())
            ViewHTML->setObjectName(QString::fromUtf8("ViewHTML"));
        ViewHTML->resize(614, 545);
        buttonBox = new QDialogButtonBox(ViewHTML);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(520, 10, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(ViewHTML);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 501, 21));
        textBrowser = new QTextBrowser(ViewHTML);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 30, 501, 501));
        pushButton = new QPushButton(ViewHTML);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(520, 260, 91, 271));

        retranslateUi(ViewHTML);
        QObject::connect(buttonBox, SIGNAL(accepted()), ViewHTML, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ViewHTML, SLOT(reject()));

        QMetaObject::connectSlotsByName(ViewHTML);
    } // setupUi

    void retranslateUi(QDialog *ViewHTML)
    {
        ViewHTML->setWindowTitle(QApplication::translate("ViewHTML", "Mostar HTML", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ViewHTML", "Puedes usar esto en tus paginas HTML", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ViewHTML", "copiar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ViewHTML: public Ui_ViewHTML {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWHTML_H
