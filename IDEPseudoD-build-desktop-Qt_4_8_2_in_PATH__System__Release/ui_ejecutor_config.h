/********************************************************************************
** Form generated from reading UI file 'ejecutor_config.ui'
**
** Created: Sun Mar 13 15:08:23 2016
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EJECUTOR_CONFIG_H
#define UI_EJECUTOR_CONFIG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ejecutor_config
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_2;
    QLabel *label_4;

    void setupUi(QDialog *ejecutor_config)
    {
        if (ejecutor_config->objectName().isEmpty())
            ejecutor_config->setObjectName(QString::fromUtf8("ejecutor_config"));
        ejecutor_config->resize(477, 232);
        buttonBox = new QDialogButtonBox(ejecutor_config);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(390, 10, 81, 81));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(ejecutor_config);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 130, 131, 21));
        lineEdit = new QLineEdit(ejecutor_config);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 130, 241, 31));
        pushButton = new QPushButton(ejecutor_config);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(390, 130, 81, 31));
        label_2 = new QLabel(ejecutor_config);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 221, 21));
        lineEdit_2 = new QLineEdit(ejecutor_config);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(10, 30, 371, 31));
        label_3 = new QLabel(ejecutor_config);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 190, 121, 21));
        lineEdit_3 = new QLineEdit(ejecutor_config);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(130, 190, 251, 31));
        pushButton_2 = new QPushButton(ejecutor_config);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(390, 190, 81, 31));
        label_4 = new QLabel(ejecutor_config);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 70, 371, 51));
        label_4->setWordWrap(true);

        retranslateUi(ejecutor_config);
        QObject::connect(buttonBox, SIGNAL(accepted()), ejecutor_config, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ejecutor_config, SLOT(reject()));

        QMetaObject::connectSlotsByName(ejecutor_config);
    } // setupUi

    void retranslateUi(QDialog *ejecutor_config)
    {
        ejecutor_config->setWindowTitle(QApplication::translate("ejecutor_config", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ejecutor_config", "Archivo de entrada", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("ejecutor_config", "/usr/share/idepseudod/buffer/Input.txt", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ejecutor_config", "mostrar", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ejecutor_config", "Comando para ejecutar PseudoD", 0, QApplication::UnicodeUTF8));
        lineEdit_2->setText(QApplication::translate("ejecutor_config", "/opt/pseudod/bin/ipdc -f %file%", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ejecutor_config", "Archivo de salida", 0, QApplication::UnicodeUTF8));
        lineEdit_3->setText(QApplication::translate("ejecutor_config", "/usr/share/idepseudod/buffer/Output.txt", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("ejecutor_config", "mostrar", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ejecutor_config", "Cada aparici\303\263n de <b>%file%</b> ser\303\241 reemplazada por el nombre del archivo", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ejecutor_config: public Ui_ejecutor_config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EJECUTOR_CONFIG_H
