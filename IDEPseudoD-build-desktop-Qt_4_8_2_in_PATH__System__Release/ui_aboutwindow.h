/********************************************************************************
** Form generated from reading UI file 'aboutwindow.ui'
**
** Created: Sun Mar 13 15:18:36 2016
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTWINDOW_H
#define UI_ABOUTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_AboutWindow
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *AboutWindow)
    {
        if (AboutWindow->objectName().isEmpty())
            AboutWindow->setObjectName(QString::fromUtf8("AboutWindow"));
        AboutWindow->resize(400, 300);
        buttonBox = new QDialogButtonBox(AboutWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(AboutWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 80, 361, 151));
        label->setWordWrap(true);
        label_2 = new QLabel(AboutWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 30, 231, 41));
        label_2->setTextFormat(Qt::RichText);

        retranslateUi(AboutWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), AboutWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AboutWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(AboutWindow);
    } // setupUi

    void retranslateUi(QDialog *AboutWindow)
    {
        AboutWindow->setWindowTitle(QApplication::translate("AboutWindow", "Acerca de", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AboutWindow", "IDE PseudoD es la IDE oficial de PseudoD, dise\303\261ada en Qt. Posee multiples caracteristicas como exportaci\303\263n a HTML, resaltado de sintaxis, entro otros.\n"
"\n"
"Creado por Alejandro Linarez Rangel, disponible en https://github.com/alinarezrangel/IDEPseudoD", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AboutWindow", "Acerca de ...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AboutWindow: public Ui_AboutWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTWINDOW_H
