/********************************************************************************
** Form generated from reading UI file 'ejecutor.ui'
**
** Created: Sun Mar 13 15:18:36 2016
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EJECUTOR_H
#define UI_EJECUTOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ejecutor
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QTextEdit *textEdit;
    QLabel *label_3;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;

    void setupUi(QDialog *ejecutor)
    {
        if (ejecutor->objectName().isEmpty())
            ejecutor->setObjectName(QString::fromUtf8("ejecutor"));
        ejecutor->resize(890, 498);
        ejecutor->setFocusPolicy(Qt::NoFocus);
        buttonBox = new QDialogButtonBox(ejecutor);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(690, 450, 191, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(ejecutor);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 30, 311, 31));
        label = new QLabel(ejecutor);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 301, 21));
        pushButton = new QPushButton(ejecutor);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 30, 95, 31));
        label_2 = new QLabel(ejecutor);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 90, 211, 21));
        textEdit = new QTextEdit(ejecutor);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 120, 341, 311));
        label_3 = new QLabel(ejecutor);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(260, 100, 51, 21));
        plainTextEdit = new QPlainTextEdit(ejecutor);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(370, 120, 381, 311));
        label_4 = new QLabel(ejecutor);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(370, 100, 61, 21));
        pushButton_2 = new QPushButton(ejecutor);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(760, 120, 121, 311));
        pushButton_4 = new QPushButton(ejecutor);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 450, 161, 31));

        retranslateUi(ejecutor);
        QObject::connect(buttonBox, SIGNAL(accepted()), ejecutor, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ejecutor, SLOT(reject()));

        QMetaObject::connectSlotsByName(ejecutor);
    } // setupUi

    void retranslateUi(QDialog *ejecutor)
    {
        ejecutor->setWindowTitle(QApplication::translate("ejecutor", "Ejecutar archivo", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ejecutor", "Comando para ejecutar un terminal(opcional)", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ejecutor", "ejecutar", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ejecutor", "Usar sistema de entrada/salida", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ejecutor", "Salida", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ejecutor", "Entrada", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("ejecutor", "ejecutar", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("ejecutor", "Configuracion", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ejecutor: public Ui_ejecutor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EJECUTOR_H
