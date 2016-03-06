/********************************************************************************
** Form generated from reading UI file 'intabtextedit.ui'
**
** Created: Wed Nov 4 19:40:10 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTABTEXTEDIT_H
#define UI_INTABTEXTEDIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InTabTextEdit
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;

    void setupUi(QWidget *InTabTextEdit)
    {
        if (InTabTextEdit->objectName().isEmpty())
            InTabTextEdit->setObjectName(QString::fromUtf8("InTabTextEdit"));
        InTabTextEdit->resize(532, 386);
        gridLayout = new QGridLayout(InTabTextEdit);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEdit = new QTextEdit(InTabTextEdit);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(InTabTextEdit);

        QMetaObject::connectSlotsByName(InTabTextEdit);
    } // setupUi

    void retranslateUi(QWidget *InTabTextEdit)
    {
        InTabTextEdit->setWindowTitle(QApplication::translate("InTabTextEdit", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class InTabTextEdit: public Ui_InTabTextEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTABTEXTEDIT_H
